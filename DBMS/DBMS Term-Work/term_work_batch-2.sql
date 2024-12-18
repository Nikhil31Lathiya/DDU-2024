Table 1 :-
--------------------------------------------
create table Emp (
    Eid int Primary key,
    Ename varchar(50),
    salary int,
    city varchar(60),
    depname varchar(60)
);

insert into Emp values
(1 , 'Ram' , 15000 , 'Nadiad' , 'sales'),
(2 , 'Dinesh' , 5000 , 'Gdm', 'Account'),
(3 , 'Devasish' , 10000 , 'Gdm', 'sales'),
(4 , 'Nikhil' , 12000 , 'Anjar', 'sales'),
(5 , 'Ayush' , 20000 , 'Bhuj', 'Finance'),
(6 , 'Aditya' , 13000 , 'Surat' , 'Finance');
(7 , 'Rakesh' , 5000 , 'Surat' , 'Acount');


Table 2 :-
--------------------------------------------

create table Leave_1(
    leaveid int primary key, 
    leavetype ENUM('CL','DL' , 'ML') not null
);

insert into Leave_1 values 
(101 , 'CL'),
(102 , 'CL'),
(103 , 'DL'),
(104 , 'DL'),
(105 , 'ML'),
(106 , 'ML'),
(107 , 'ML'),
(108 ,  'CL');



Table 3 :-
--------------------------------------------

create table Emp_leave(
    Eid int,
    leaveid int,
    leavedate date,
    foreign key (Eid) references Emp(Eid),
    foreign key (leaveid) references Leave_1(leaveid),
    primary key (leaveid,Eid)
);

insert into Emp_leave values
(1, 101, '2018-02-12'),
(2, 102, '2017-04-21'),
(3, 103, '2020-05-26'),
(7 , 107 , '2020-12-31'),
(7 , 108 , '2020-10-15');
(4 , 104 , '2023-11-22');


----------------------------------------------------------------

1)
select * from Emp where Ename like 'D%';
+-----+----------+--------+------+---------+
| Eid | Ename    | salary | city | depname |
+-----+----------+--------+------+---------+
|   2 | Dinesh   |   5000 | Gdm  | Account |
|   3 | Devasish |  10000 | Gdm  | sales   |
+-----+----------+--------+------+---------+


2)

select * from Emp where salary between 10000 and 15000 ;
+-----+----------+--------+--------+---------+
| Eid | Ename    | salary | city   | depname |
+-----+----------+--------+--------+---------+
|   1 | Ram      |  15000 | Nadiad | sales   |
|   3 | Devasish |  10000 | Gdm    | sales   |
|   4 | Nikhil   |  12000 | Anjar  | sales   |
|   6 | Aditya   |  13000 | Surat  | Finance |
+-----+----------+--------+--------+---------+


3)

select Ename from emp where eid in
(select eid from Emp_leave where leaveid in 
(select leaveid from Leave_1 where leavetype='CL'));
+--------+
| Ename  |
+--------+
| Ram    |
| Dinesh |
+--------+


4)
select eid, leaveid  from emp_leave where leavedate < '2019-02-12';
+-----+---------+
| eid | leaveid |
+-----+---------+
|   1 |     101 |
|   2 |     102 |
+-----+---------+


5)
select depname, SUM(salary) from emp group by depname;
+---------+-------------+
| depname | SUM(salary) |
+---------+-------------+
| sales   |       37000 |
| Account |        5000 |
| Finance |       33000 |
+---------+-------------+


6)
select leavetype from leave_1 where leaveid in (
    select leaveid from emp_leave where eid in (
        select eid from emp where ename='Rakesh'
    )); 
+-----------+
| leavetype |
+-----------+
| ML        |
| CL        |
+-----------+

7) 
select leavedate from emp_leave where leaveid in (
    select leaveid from leave_1  where leavetype = 'DL');
+------------+
| leavedate  |
+------------+
| 2020-05-26 |
| 2023-11-22 |
+------------+

8)
update emp set city='Goa' where ename='Rakesh';
+-----+----------+--------+--------+---------+
| Eid | Ename    | salary | city   | depname |
----------------------------------------------
|   7 | Rakesh   |   5000 | Goa    | Account |
+-----+----------+--------+--------+---------+

9)  
select leavetype , count(leaveid) from leave_1 group by leavetype;
+-----------+----------------+
| leavetype | count(leaveid) |
+-----------+----------------+
| CL        |              3 |
| DL        |              2 |
| ML        |              3 |
+-----------+----------------+

10)

delimiter $$
create procedure display(IN dname varchar(60) ,  OUT maxSal int)
begin 
    select * from Emp_leave where eid in (
        select eid from emp where depname= dname 
    );
    select max(salary) into maxSal from emp where depname= dname;
end $$
delimiter ;

call display('sales' , @maxSal);

+-----+---------+------------+
| Eid | leaveid | leavedate  |
+-----+---------+------------+
|   1 |     101 | 2018-02-12 |
|   3 |     103 | 2020-05-26 |
|   4 |     104 | 2023-11-22 |
+-----+---------+------------+

select @maxSal;
+---------+
| @maxSal |
+---------+
|   15000 |
+---------+

11)

-- delimiter $$
--     create function disp(leave_id int) 
--     returns varchar(20) 
--     deterministic
-- 	begin
-- 	  declare employee_name varchar(20);
--  	   select ename into employee_name from emp where eid in (select eid from emp_leave where leaveid not in(select leaveid from Leave_1 where leaveid = leave_id));
-- 	return employee_name;

-- 	end $$ 
--     delimiter ;

--   select display(102);

--  Result consisted of more than one row  
-- --------------------------

delimiter $$
create function display(leave_id int) returns LONGTEXT deterministic
	begin
	  declare employee_name LONGTEXT;
 	   select GROUP_CONCAT(ename) into employee_name from emp where eid in (select eid from emp_leave    
               where leaveid not in(select leaveid from leave_1 where leaveid = leave_id));
	   return employee_name;
	end $$
    delimiter ;

  select display(102);

+----------------------------+
| display(102)               |
+----------------------------+
| Ram,Devasish,Nikhil,Rakesh |
+----------------------------+

12)

alter table emp add bonus int;

update emp set bonus = case
    WHEN salary < 5000 THEN salary * 0.05
    WHEN salary BETWEEN 5001 AND 10000 THEN salary * 0.06
    ELSE salary * 0.07
END;
+-----+----------+--------+--------+---------+-------+
| Eid | Ename    | salary | city   | depname | bonus |
+-----+----------+--------+--------+---------+-------+
|   1 | Ram      |  15000 | Nadiad | sales   |  1050 |
|   2 | Dinesh   |   5000 | Gdm    | Account |   350 |
|   3 | Devasish |  10000 | Gdm    | sales   |   600 |
|   4 | Nikhil   |  12000 | Anjar  | sales   |   840 |
|   5 | Ayush    |  20000 | Bhuj   | Finance |  1400 |
|   6 | Aditya   |  13000 | Surat  | Finance |   910 |
|   7 | Rakesh   |   5000 | Goa    | Account |   350 |
+-----+----------+--------+--------+---------+-------+

select leavetype , count(leaveid) from leave_1 group by leavetype;
