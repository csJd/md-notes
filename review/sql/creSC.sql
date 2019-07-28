create table Student
(
	Sno char(9) primary key,
	Sname char(20) unique,
	Ssex char(2),
	Sage smallint,
	Sdept char(20)
);

create table Course
(
	Cno char(4) primary key,
	Cname char(40),
	Cpno char(4),
	Ccredit smallint,
	foreign key (Cpno) references Course(Cno)
);

create table SC
(
	Sno char(9),
	Cno char(4),
	Grade smallint,
	primary key (Sno,Cno),
	foreign key (Sno) references Student(Sno),
	foreign key (Cno) references Course(Cno)
);

