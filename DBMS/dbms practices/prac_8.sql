1)

delimiter $$
create procedure proc1() 
begin
    declare id int;
    declare fname varchar(30);

    set id = 1;
    set fname ='ram';

    select id, fname ;
end $$

delimiter ;

call proc1();
+------+-------+
| id   | fname |
+------+-------+
|    1 | ram   |
+------+-------+

2) 

delimiter $$
create procedure proc2() 
begin
    declare count_1 int;
    set count_1 = 10;

    while count_1 > 0 do
        select count_1;
        set count_1 = count_1- 1;
    end while;
end $$
delimiter ;


3)

delimiter $$
create procedure proc3( IN n int)
begin 
    declare i int default 1;
    declare ans int default 0;
    
    while i<=n do
        set ans = ans + i ;
        set i = i + 1 ;
    end while;
    select ans;
    end $$
   delimiter ;
 
 call proc3(10);
+------+
| ans  |
+------+
|   55 |
+------+

4)
create procedure proc4 ( IN id int)
begin 
    select name ,sum(marks)/3 from student_sub where student_id = id
    group by name;
end;


5) 
delimiter $$
create procedure proc5 ( IN n int)
begin 
    if mod(n,2) = 0 then 
    select concat(n," is even");
    else
    select concat(n," is odd");
    end if;
end $$
delimiter ;

call proc5(10);

+----------------------+
| concat(n," is even") |
+----------------------+
| 10 is even           |
+----------------------+

6)
delimiter $$
create procedure proc6 ( IN o_id varchar(30) , OUT t_qty int)
begin
  select sum(qtyordered) into t_qty from sales_order_details where orderno = o_id;
end $$

delimiter ;
 
call proc6("O19001", @t_qty);
select @t_qty;
+--------+
| @t_qty |
+--------+
|      8 |
+--------+

----------------------------------------------------------
1)
DELIMITER $$

CREATE FUNCTION func1(n INT)
RETURNS VARCHAR(30)
DETERMINISTIC
BEGIN
    DECLARE val VARCHAR(30);

    IF MOD(n, 2) = 0 THEN
        SET val = 'even';
    ELSE
        SET val = 'odd';
    END IF;

    RETURN val;
END $$

DELIMITER ;

select func1(5);
+----------+
| func1(5) |
+----------+
| odd      |
+----------+

2)

DELIMITER $$

CREATE FUNCTION func2(age INT)
RETURNS VARCHAR(30)
DETERMINISTIC
BEGIN 
    DECLARE st VARCHAR(30);

    IF age <= 25 THEN
        SET st = 'Young';
    ELSEIF age >= 26 AND age <= 32 THEN
        SET st = 'Middle';
    ELSE
        SET st = 'Old';
    END IF;

    RETURN st;
END $$

DELIMITER ;

select name, age, func2(age) from emp
+---------------+------+------------+
| name          | age  | func2(age) |
+---------------+------+------------+
| John Doe      |   25 | Young      |
| Jane Smith    |   30 | Middle     |
| Bob Johnson   |   22 | Young      |
| Alice Brown   |   28 | Middle     |
| Charlie Davis |   35 | Old        |
+---------------+------+------------+

3)

CREATE FUNCTION fun3(order_no VARCHAR(6)) RETURNS
VARCHAR(255)
 -> BEGIN
 -> DECLARE product_name VARCHAR(255);
 -> SELECT p.description INTO product_name
 -> FROM product_master p
 -> JOIN sales_order_details sod ON p.productno = sod.productno
 -> WHERE sod.orderno = order_no
 -> LIMIT 1;
 -> RETURN product_name;
 -> END;
 -> $$
 
  delimiter ;


mysql> select fun3('O46866');
+----------------+
| fun3('O46866') |
+----------------+
| Denim Shirts |
+----------------+

select func3('O46866');
