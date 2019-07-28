select * from s;                         /*s
SNO   SNAME                STATUS     CITY
----- -------------------- ---------- ----------
S1    精益                 20         天津
S2    盛锡                 10         北京
S3    东方红               30         北京
S4    丰泰盛               20         天津
S5    为民                 30         上海*/

select * from p;/*p
PNO   PNAME                COLOR          WEIGHT
----- -------------------- ---------- ----------
P1    螺母                 红                 12
P2    螺栓                 绿                 17
P3    螺丝刀               蓝                 14
P4    螺丝刀               红                 14
P5    凸轮                 蓝                 40
P6    齿轮                 红                 30*/

select * from j;/*j
JNO   JNAME                CITY
----- -------------------- --------------------
J1    三建                 北京
J2    一汽                 长春
J3    弹簧厂               天津
J4    造船厂               天津
J5    机车厂               唐山
J6    无线电厂             常州
J7    半导体厂             南京*/

select * from spj;              /*SPJ
SNO   PNO   JNO          QTY
----- ----- ----- ----------
S1    P1    J1           200
S1    P1    J3           100
S1    P1    J4           700
S1    P2    J2           100
S2    P3    J1           400
S2    P3    J2           200
S2    P3    J4           500
S2    P3    J5           400
S2    P5    J1           400
S2    P5    J2           100
S3    P1    J1           200
S3    P3    J1           200
S4    P5    J1           100
S4    P6    J3           300
S4    P6    J4           200
S5    P2    J4           100
S5    P3    J1           200
S5    P6    J2           200
S5    P6    J4           500*/

select sname,city from s;
/*1.1
SNAME                CITY
-------------------- ----------
精益                 天津
盛锡                 北京
东方红               北京
丰泰盛               天津
为民                 上海*/

select pname,color,weight from p;
/*1.2
PNAME                COLOR          WEIGHT
-------------------- ---------- ----------
螺母                 红                 12
螺栓                 绿                 17
螺丝刀               蓝                 14
螺丝刀               红                 14
凸轮                 蓝                 40
齿轮                 红                 30*/

select distinct pno from spj where sno = 'S1';
/*1.3
PNO
-----
P1
P2*/

select pname, qty from p,spj
where jno = 'J2' and spj.pno = p.pno;
/* 1.4
PNAME                       QTY
-------------------- ----------
螺栓                        100
螺丝刀                      200
凸轮                        100
齿轮                        200*/


select distinct spj.pno from spj, s
where spj.sno = s.sno and city = '上海';
/*1.5
PNO
-----
P2
P3
P6*/

select distinct spj.jno from spj,s,j
where spj.sno = s.sno and s.city = '上海';
/*1.6
JNO
-----
J1
J2
J4*/

select jno from j
where not exists
(
	select spj.* from spj,s
	where s.sno = spj.sno and j.jno = spj.jno and s.city = '天津'
);
/*1.7
JNO
-----
J5
J6
J7
*/


select distinct sno from spj
where jno = 'J1';
/*2.1
SNO
-----
S1
S2
S3
S4
S5*/

select distinct sno from spj
where jno = 'J1' and pno = 'P1';
/*2.2
SNO
-----
S1
S3
*/


select distinct sno from spj, p
where jno = 'J1' and p.pno = spj.pno and p.color = '红';
/*2.3
SNO
-----
S1
S3*/


select jno from j
where not exists
(
	select spj.* from spj,s,p
	where spj.sno = s.sno
	and spj.jno = j.jno
	and spj.pno = p.pno
	and s.city = '天津'
	and p.color = '红'
);
/*2.4
JNO
-----
J2
J5
J6
J7*/


select distinct jno from spj a
where not exists
(
	select * from spj b
	where b.sno = 'S1' and not exists
	(
		select * from spj c
		where c.jno = a.jno and b.pno = c.pno
	)
);
/* 2.5
JNO
-----
J4*/


create view spq (sno, pno, qty)
as
select sno,pno,qty from spj, j
where spj.jno = j.jno and j.jname = '三建';

select distinct pno,
(
	select sum(qty)
	from spq
	where b.pno = a.pno
) qty
from spq b;
/*3.1
PNO          QTY
----- ----------
P1           400
P3           800
P5           500*/

select * from spq where sno = 'S1';
/*3.2
SNO   PNO          QTY
----- ----- ----------
S1    P1           200
*/
