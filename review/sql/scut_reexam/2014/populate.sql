-- populate remunerations
INSERT INTO remunerations VALUES ('Z01', 80);
INSERT INTO remunerations VALUES ('Z02', 60);
INSERT INTO remunerations VALUES ('Z03', 40);

-- populate teachers
INSERT INTO teachers VALUES ('T01', '张三', '计算机', 'Z01');
INSERT INTO teachers VALUES ('T02', '李四', '物理', 'Z02');
INSERT INTO teachers VALUES ('T03', '王五', '数学', 'Z02');
INSERT INTO teachers VALUES ('T04', '赵六', '计算机', 'Z03');

-- populate courses
INSERT INTO courses VALUES ('C01', '数据库', 64, 'T01');
INSERT INTO courses VALUES ('C02', '大学物理', 56, 'T02');
INSERT INTO courses VALUES ('C03', '高等数学', 80, 'T03');
INSERT INTO courses VALUES ('C04', '操作系统', 60, 'T04');
INSERT INTO courses VALUES ('C05', '线性代数', 50, 'T03');
INSERT INTO courses VALUES ('C06', '微积分', 40, 'T03');
INSERT INTO courses VALUES ('C07', '数据结构', 60, 'T04');
