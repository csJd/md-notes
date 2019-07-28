create table s
(
	sno char(5) primary key,
	sname char(20),
	status char(10),
	city char(10)
);

create table p
(
	pno char(5) primary key,
	pname char(20),
	color char(10),
	weight smallint
);

create table j
(
	jno char(5) primary key,
	jname char(20),
	city char(20)
);

create table SPJ
(
	sno char(5),
	pno char(5),
	jno char(5),
	qty smallint,
	primary key (sno,pno,jno),
	foreign key (sno) references s(sno),
	foreign key (pno) references p(pno),
	foreign key (jno) references j(jno)
);

