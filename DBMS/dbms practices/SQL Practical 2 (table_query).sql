create table client_master(

	clientno varchar(6) primary key,
	name varchar(20) not null,
	city varchar(15),
	state varchar(15),
	baldue float(10,2),
	check(clientno like 'C%')
);

create table product_master(

productno varchar(6) primary key,
description varchar(15) not null,
unitmeasure varchar(10) not null,
qtyonhand int(8) not null,
reordervl int(8) not null,
sellprice float(8,2),
costprice float(8,2),
check (sellprice >0),
check(costprice >0)	
);

create table salesman_master(

salesmanno varchar(6) primary key,
salesmanname varchar(30) not null,
city varchar(20),
state varchar(20),
sale_amt float(8,2),
check(sale_amt >0),
check(salesmanno like 'S%')
);

create table sales_order(

orderno varchar(6) primary key,
clientno varchar(6),
orderdate date not null,
salesmanno varchar(6),
delytype enum('P' , 'F'),
deltdate date,
orderstatus enum('In Process' , 'Fulfilled' , 'BackOrder', 'Cancelled'),
check(orderno like 'O%'),
 foreign key(clientno) references client_master(clientno),
foreign key(salesmanno) references salesman_master(salesmanno)
);

create table sales_order_details(
	
orderno varchar(6),
productno varchar(6),
qtyordered int(8),
foreign key(orderno) references sales_order(orderno),
foreign key(productno) references product_master(productno)
);



insert into client_master values
('C00001' , 'Korth'  , 'mumbai' , 'maharastra' , 15000 ),
('C00002' , 'mamta'  , 'madras' , 'tamil nadu' , 0 ),
('C00003' , 'chhaya'  , 'mumbai' , 'maharastra' , 5000 ),
('C00004' , 'ashwini'  , 'bangalore' , 'karnataka' , 0 ),
('C00005' , 'hansel'  , 'mumbai' , 'maharastra' , 2000 ),
('C00006' , 'deepak'  , 'bangalore' , 'karnataka' , 0 );


insert into product_master values
('P00001' , 'T-Shirts' , 'Piece' , 200 , 50 , 350 , 250),
('P0345' , 	'Shirts' , 'Piece' , 150 , 50 , 500 , 350),
('P06734' , 'Cotton jeans' , 'Piece' , 100 , 20 , 600 , 450),
('P07865' , 'jeans' , 'Piece' , 100 , 20 , 750 , 500),
('P07868' , 'Trousers' , 'Piece' , 150 , 50 , 850 , 550),
('P07885' , 'pull overs' , 'Piece' , 80 , 30 , 700 , 450),
('P07965' , 'demin Shirts' , 'Piece' , 100 , 4 , 350 , 250),
('P07975' , 'lycra tops' , 'Piece' , 70 , 30 , 300 , 175),
('P08865' , 'skirts' , 'Piece' , 75 , 30 , 450 , 300);


insert into sales_order values
('O19001' ,	'C00001' ,	'2004-06-12',	'S00001',	'F', 	'2004-07-20', 	'In Process'	),
('O19002' ,	'C00002',	'2004-06-25',	'S00002',	'P'	,'2004-06-27', 	'Cancelled'		),
('O46865' ,	'C00003'	,'2004-02-18',	'S00003',	'F'	,'2004-02-20',	'Fulfilled'		),
('O19003'  ,	'C00001',	'2004-04-03',	'S00001',	'F'	,'2004-04-07',	'Fulfilled'		),
('O46866'  , 	'C00004',	'2004-05-20',	'S00002',	'P'	,'2004-05-22',	'Cancelled'		),
('O19008'  ,	'C00005',	'2004-05-24',	'S00004',	'F',	'2004-07-26',	'In Process'	);


insert into sales_order_details values
('O19001',	'P00001',	4),
('O19001',	'P07965',	2),
('O19001',	'P07885',	2),
('O19002',	'P00001',	10),
('O46865',	'P07868',	3),
('O46865',	'P07885',	3),
('O46865',	'P00001', 10),
('O46865',	'P0345',	4),
('O19003',	'P0345',	2),
('O19003',	'P06734',	1),
('O46866',	'P07965',	1),
('O46866',	'P07975',	1),
('O19008',	'P00001',	8),
('O19008',	'P07975',	5);

insert into salesman_master values
('S00001' ,	'Aman'	,'Mumbai'	,'Maharashtra'	,3000),
('S00002'	,'Omkar'	,'Mumbai'	,'Maharashtra'	,6700),
('S00003'	,'Ray'	,'Mumbai'	,'Maharashtra'	,4000),
('S00004'	,'Ashishh',	'Ahmedabad'	,'Gujarat'	,3500);



