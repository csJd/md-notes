-- populate departments
INSERT INTO departments VALUES ('1', '数学');
INSERT INTO departments VALUES ('2', '计算机');
INSERT INTO departments VALUES ('3', '化学');

-- populate classes
INSERT INTO classes VALUES ('101', '软件', '2', 2012, 25);
INSERT INTO classes VALUES ('102', '微电子', '2', 2013, 28);
INSERT INTO classes VALUES ('111', '无机化学', '3', 2012, 20);
INSERT INTO classes VALUES ('112', '高分子化学', '3', 2013, 19);
INSERT INTO classes VALUES ('121', '统计数学', '1', 2013, 11);

-- populate students
INSERT INTO students VALUES ('8101', '张三', '1996-7-9', '101');
INSERT INTO students VALUES ('8102', '钱四', '1996-2-6', '121');
INSERT INTO students VALUES ('8105', '李飞', '1994-1-21', '102');
INSERT INTO students VALUES ('8201', '张飞', '1996-2-25', '111');
INSERT INTO students VALUES ('8302', '周瑜', '1996-6-15', '112');
INSERT INTO students VALUES ('8203', '王亮', '1997-5-27', '111');
INSERT INTO students VALUES ('8305', '董庆', '1996-4-2', '102');
INSERT INTO students VALUES ('8409', '赵龙', '1995-6-1', '101');
