SQL practical 5 :

 1)  select productno from product_master where productno not in(select productno from sales_order_details);

+-----------+
| productno |
+-----------+
| P07865    |
| P08865    |
+-----------+

2)select productno from product_master where productno in(select productno from sales_order_details);

+-----------+
| productno |
+-----------+
| P00001    |
| P0345     |
| P06734    |
| P07868    |
| P07885    |
| P07965    |
| P07975    |
+-----------+
3) select description from product_master where productno in(
	select productno from sales_order_details where orderno in (
	select orderno from sales_order where delytype='f'));

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


4)  select * from product_master where sellprice < (
select sellprice from product_master where productno = 'p0345');

+-----------+--------------+-------------+-----------+-----------+-----------+-----------+
| productno | description  | unitmeasure | qtyonhand | reordervl | sellprice | costprice |
+-----------+--------------+-------------+-----------+-----------+-----------+-----------+
| P00001    | T-Shirts     | Piece       |       200 |        50 |    350.00 |    250.00 |
| P07965    | demin Shirts | Piece       |       100 |         4 |    350.00 |    250.00 |
| P07975    | lycra tops   | Piece       |        70 |        30 |    300.00 |    175.00 |
| P08865    | skirts       | Piece       |        75 |        30 |    450.00 |    300.00 |
+-----------+--------------+-------------+-----------+-----------+-----------+-----------+


5)   select name from client_master where clientno in (
     select clientno from sales_order where orderstatus='In Process');
+--------+
| name   |
+--------+
| Korth  |
| hansel |
+--------+

6) select salesmanname from salesman_master where salesmanno in(
     select salesmanno from sales_order where orderstatus='Cancelled');

+--------------+
| salesmanname |
+--------------+
| Omkar        |
+--------------+

7) select name from client_master where clientno in(
    -> select clientno from sales_order where orderdate < '2005-01-01');
+---------+
| name    |
+---------+
| Korth   |
| mamta   |
| chhaya  |
| ashwini |
| hansel  |
+---------+

8)  select salesmanname from salesman_master where salesmanno not in (
     select salesmanno from sales_order);

+--------------+
| salesmanname |
+--------------+
| Nikhil       |
+--------------+


9) 

select name from client_master where clientno in (
select clientno from sales_order where delytype='f');

+--------+
| name   |
+--------+
| Korth  |
| chhaya |
| hansel |
+--------+


10)
select name from client_master where clientno in (
select clientno from sales_order where salesmanno = 'S00002');

+---------+
| name    |
+---------+
| mamta   |
| ashwini |
+---------+