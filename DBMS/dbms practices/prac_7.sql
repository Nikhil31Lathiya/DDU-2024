
                                MySQL   
                Practical 8 MySQL Join Advance Query

1) display all details of every client clients as well as order details of clients. Using leftjoin


select * from client_master as c left join sales_order as s on c.clientno = s.clientno;
+----------+---------+-----------+------------+----------+---------+----------+------------+------------+----------+------------+-------------+
| clientno | name    | city      | state      | baldue   | orderno | clientno | orderdate  | salesmanno | delytype | deltdate   | orderstatus |
+----------+---------+-----------+------------+----------+---------+----------+------------+------------+----------+------------+-------------+
| C00001   | Korth   | mumbai    | maharastra | 15500.00 | O19001  | C00001   | 2004-06-12 | S00001     | F        | 2004-07-20 | In Process  |
| C00001   | Korth   | mumbai    | maharastra | 15500.00 | O19003  | C00001   | 2004-04-03 | S00001     | F        | 2004-04-07 | Fulfilled   |
| C00002   | mamta   | madras    | tamil nadu |     0.00 | O19002  | C00002   | 2004-06-25 | S00002     | P        | 2004-06-27 | Cancelled   |
| C00003   | chhaya  | mumbai    | maharastra |  5000.00 | O46865  | C00003   | 2004-02-18 | S00003     | F        | 2004-02-20 | Fulfilled   |
| C00004   | ashwini | bangalore | karnataka  |     0.00 | O46866  | C00004   | 2004-05-20 | S00002     | P        | 2004-05-22 | Cancelled   |
| C00005   | hansel  | mumbai    | maharastra |  2000.00 | O19008  | C00005   | 2004-05-24 | S00004     | F        | 2004-07-26 | In Process  |
| C00006   | deepak  | bangalore | karnataka  |     0.00 | NULL    | NULL   
  | NULL       | NULL       | NULL     | NULL       | NULL        |
+----------+---------+-----------+------------+----------+---------+----------+------------+------------+----------+------------

2. Display only those salesman name who has supplies the order (hint innerjoin)

select distinct sm.salesmanname from salesman_master as sm inner join 
sales_order as so on sm.salesmanno = so.salesmanno;
+--------------+
| salesmanname |
+--------------+         |
| Aman         |
| Omkar        |
| Ray          |
| Ashishh      |
+--------------+

3. display only those product name who has been ordered.(hint inner join)

select distinct p.description from product_master as p inner join sales_order_details as s where p.productno = s.productno;
+--------------+
| description  |
+--------------+
| T-Shirts     |
| Shirts       |
| Cotton jeans |
| Trousers     |
| pull overs   |
| demin Shirts |
| lycra tops   |
+--------------+

4) Display salesman name,city,saleamout,clientno,orderno,orderdate,orderstatus of only those sales man who have order. Using right join.

select s.salesmanname ,s.city ,s.sale_amt , so.clientno , so.orderno, so.orderdate , so.orderstatus from salesman_master s right join sales_order as so  on s.salesmanno = so.salesmanno;
+--------------+-----------+----------+----------+---------+------------+-------------+
| salesmanname | city      | sale_amt | clientno | orderno | orderdate  | orderstatus |
+--------------+-----------+----------+----------+---------+------------+-------------+
| Aman         | Mumbai    |  3000.00 | C00001   | O19001  | 2004-06-12 | In Process  |
| Omkar        | Mumbai    |  6700.00 | C00002   | O19002  | 2004-06-25 | Cancelled   |
| Aman         | Mumbai    |  3000.00 | C00001   | O19003  | 2004-04-03 | Fulfilled   |
| Ashishh      | Ahmedabad |  3500.00 | C00005   | O19008  | 2004-05-24 | In Process  |
| Ray          | Mumbai    |  4000.00 | C00003   | O46865  | 2004-02-18 | Fulfilled   |
| Omkar        | Mumbai    |  6700.00 | C00004   | O46866  | 2004-05-20 | Cancelled   |
+--------------+-----------+----------+----------+---------+------------+-------------+


5) displaydescription, description,qtyonhand,reorderlvl,sellprice,qtyorder,orderno for all product Using left join .

select p.description , p.qtyonhand , p.reordervl , p.sellprice , s.qtyordered , s.orderno from product_master as p left join sales_order_details as s on p.productno = s.productno;
+--------------+-----------+-----------+-----------+------------+---------+
| description  | qtyonhand | reordervl | sellprice | qtyordered | orderno |
+--------------+-----------+-----------+-----------+------------+---------+
| T-Shirts     |       200 |        50 |    350.00 |          4 | O19001  |
| T-Shirts     |       200 |        50 |    350.00 |         10 | O19002  |
| T-Shirts     |       200 |        50 |    350.00 |         10 | O46865  |
| T-Shirts     |       200 |        50 |    350.00 |          8 | O19008  |
| Shirts       |       150 |        50 |    500.00 |          4 | O46865  |
| Shirts       |       150 |        50 |    500.00 |          2 | O19003  |
| Cotton jeans |       100 |        20 |    600.00 |          1 | O19003  |
| jeans        |       100 |        20 |    750.00 |       NULL | NULL    |
| Trousers     |       150 |        50 |    850.00 |          3 | O46865  |
| pull overs   |        80 |        30 |    700.00 |          2 | O19001  |
| pull overs   |        80 |        30 |    700.00 |          3 | O46865  |
| demin Shirts |       100 |         4 |    350.00 |          2 | O19001  |
| demin Shirts |       100 |         4 |    350.00 |          1 | O46866  |
| lycra tops   |        70 |        30 |    300.00 |          1 | O46866  |
| lycra tops   |        70 |        30 |    300.00 |          5 | O19008  |
| skirts       |        75 |        30 |    450.00 |       NULL | NULL    |
+--------------+-----------+-----------+-----------+------------+---------+

Exercise on Case Statement

1. Based on sale price of product display the message as result. If saleprice is less than 500 , result message is “its not costaly” o.w display the result message “it is costaly”
Output should be like Prductno , sellprice, result


select productno, sellprice,
    case  
        when sellprice < 500 then "its not costaly"
        else "its costaly"
    end as result from product_master;
+-----------+-----------+-----------------+
| productno | sellprice | result          |
+-----------+-----------+-----------------+
| P00001    |    350.00 | its not costaly |
| P0345     |    500.00 | its costaly     |
| P06734    |    600.00 | its costaly     |
| P07865    |    750.00 | its costaly     |
| P07868    |    850.00 | its costaly     |
| P07885    |    700.00 | its costaly     |
| P07965    |    350.00 | its not costaly |
| P07975    |    300.00 | its not costaly |
| P08865    |    450.00 | its not costaly |
+-----------+-----------+-----------------+


2) 
Calculate the bonus for the salesman based on sales amount
If sales_amount is 1000-2000 give 2% bonus
If sales_amount is 2001-3000 give 3% bonus
If sales_amount greater than 3000 give 5% bonus
o.w dont give any bonus. Output should be like Salesmanno, sales_amount, bounus


select salesmanno, sale_amt ,
    case 
    when sale_amt >=2000 and sale_amt < 1000 then sale_amt*0.02
    when sale_amt >2000 and sale_amt <= 3000 then sale_amt*0.03
    when sale_amt >=3000 then sale_amt*0.05
    end as bonus  from salesman_master;
+------------+----------+--------+
| salesmanno | sale_amt | bonus  |
+------------+----------+--------+
| S00001     |  3000.00 |  90.00 |
| S00002     |  6700.00 | 335.00 |
| S00003     |  4000.00 | 200.00 |
| S00004     |  3500.00 | 175.00 |
| S1007      |  9000.00 | 450.00 |
+------------+----------+--------+

3)  calculate total quantity ordered of each product .
     if is 5-10 message is “good sailing item”
    if is 10-15 message is “very good sailing item”
    else message “no sale”


select productno , sum(qtyordered) as total_qty ,
        case
    when sum(qtyordered) >= 5 and sum(qtyordered) <10 then "good sailing item"
    when sum(qtyordered) >= 10 and sum(qtyordered) <=15 then "very good sailing item"
    else "no sale"
    end as message from sales_order_details group by productno;
+-----------+-----------+-------------------+
| productno | total_qty | message           |
+-----------+-----------+-------------------+
| P00001    |        32 | no sale           |
| P0345     |         6 | good sailing item |
| P06734    |         1 | no sale           |
| P07868    |         3 | no sale           |
| P07885    |         5 | good sailing item |
| P07965    |         3 | no sale           |
| P07975    |         6 | good sailing item |
+-----------+-----------+-------------------+


4)  Add field bonus float(10,2) in office table;
    Update the bonus of every employee based on salary
    If salary is 5000-10000 then bonus is 2%
    If salary is 10,001 – 15 then bonus is 3 %
    If salary is greater than 15,000 then bonus is 5%
    Else bonus is 0%


alter table emp add column bonus float(10,2) ;

update emp set bonus = 
    case 
      when salary >=5000 and salary <=10000 then salary*0.02
      when salary >10000 and salary <=15000 then salary*0.03
      when  salary > 15000 then salary*0.05
      else 0
    end;
+---------------+------+--------+---------+
| name          | age  | salary | bonus   |
+---------------+------+--------+---------+
| John Doe      |   25 |   6000 |  120.00 |
| Jane Smith    |   30 |   7000 |  140.00 |
| Bob Johnson   |   22 |  15000 |  450.00 |
| Alice Brown   |   28 |  10000 |  200.00 |
| Charlie Davis |   35 |  75000 | 3750.00 |
+---------------+------+--------+---------+

