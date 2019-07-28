create database rk_userdb;
use rk_userdb;

create table t_user
(
	id int primary key auto_increment,
	username char(50),
	password char(50),
	role int check (role in (1,2)),
	del int default 1 check (role in (0,1))
);

insert into t_user values(1,'admin','admin',1,0);
select * from t_user;



