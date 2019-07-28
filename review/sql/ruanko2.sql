create database rk_questiondb;
use rk_questiondb;

create table t_question
(
	ID int primary key auto_increment,
	Type int not null check(type in(0,1)),
	ItemContent varchar(50) not null,
	Analysis varchar(200),
	Del int not null default 0 check(Del in(0,1))
);

desc t_question;

/*
create table t_option
(
	ID int not null primary key auto_increment,
	QID int not null,
	Num int not null check(Num in(0,1,2,3)),
	OptionContent varchar(100) not null,
	Istrue int not null check (IsTrue in (0,1)),
	Del int not null default 0 check(Del in(0,1)),
	foreign key(QID) references t_question(ID)
);
*/

create table t_option
(
	ID int not null primary key auto_increment,
	QID int not null,
	Num in not null check(Num in(0,1,2,3)),
	OptionContent varchar(100) not null,
	IsTrue int not null check(isTrue in(0,1)),
	Del int not null default 0 check(Del in(0,1)),
	foreign key(QID) references t_question(ID)
);

insert into t_question(ID,Type,ItemContent,Analysis,Del)
values(1,0,'数据库系统的核心是','数据库知识',0);
insert into t_question(Type,ItemContent,Analysis,Del)
select Type,ItemContent,Analysis,Del from t_question where ID = 1;


insert into t_option(QID,Num,OptionContent,IsTrue) values (1,0,'数据模型',1);
insert into t_option(QID,Num,OptionContent,IsTrue) values (1,1,'数据库管理系统',0);
insert into t_option(QID,Num,OptionContent,IsTrue) values (1,2,'数据库',0);
insert into t_option(QID,Num,OptionContent,IsTrue) values (1,3,'数据库管理员',0);

desc t_question;
alter table t_question add Point float(3,1) default '0';
desc t_question;
alter table t_question modify column Point int;
desc t_question;
alter table t_question change Point Score int;
desc t_question;
alter table t_question drop Score;
desc t_question;
drop table t_question cascade;

create view v_question as select ID,ItemContent from t_question;
drop view v_question;

create unique index QueID on t_question(ID);
drop index QueID on t_question;

select ques.ID, ques.ItemContent, opt.Num, opt.OptionContent, opt.IsTrue
from t_question ques, t_option opt
where opt.QID = ques.ID;

select * from t_question where Analysis in
(select Analysis from t_question where ID = 2);

select * from t_question where Point >
(select AVG(Point) from t_question);

selext ID from t_question where exists
(select * from t_option where QID = q_question.ID);








update t_question set Point = 1 where ID = 1;
update t_question set Point = Point + 1;
update t_option set Del = 
(select Del from t_question where t_option.QID == t_question.ID);










