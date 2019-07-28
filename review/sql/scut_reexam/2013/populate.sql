-- populate teachers
INSERT INTO teachers VALUES ('T01', '张三', '男');
INSERT INTO teachers VALUES ('T02', '李四', '女');
INSERT INTO teachers VALUES ('T03', '王五', '男');
INSERT INTO teachers VALUES ('T04', '赵六', '女');

-- populate courses
INSERT INTO courses VALUES ('C01', '数据结构', 64);
INSERT INTO courses VALUES ('C02', '操作系统', 64);
INSERT INTO courses VALUES ('C03', '网络原理', 48);
INSERT INTO courses VALUES ('C04', '数据库', 48);

-- populate works
INSERT INTO works VALUES ('T01', 'C01', 2010, '春');
INSERT INTO works VALUES ('T01', 'C02', 2010, '秋');
INSERT INTO works VALUES ('T02', 'C01', 2011, '春');
INSERT INTO works VALUES ('T03', 'C01', 2011, '秋');
INSERT INTO works VALUES ('T04', 'C02', 2011, '春');
INSERT INTO works VALUES ('T04', 'C03', 2010, '春');
INSERT INTO works VALUES ('T04', 'C04', 2012, '秋');
