-- pupulate employees
INSERT INTO employees VALUES('E01', '张三', '女', 32);
INSERT INTO employees VALUES('E02', '李四', '男', 28);
INSERT INTO employees VALUES('E03', '王五', '女', 42);
INSERT INTO employees VALUES('E04', '赵六', '男', 37);
INSERT INTO employees VALUES('E05', '陈七', '男', 51);

-- populate companies
INSERT INTO companies VALUES('C01', '阳光科技');
INSERT INTO companies VALUES('C02', '晨光科技');
INSERT INTO companies VALUES('C03', '未来科技');

-- populate works
INSERT INTO works VALUES('E01', 'C01', 3000);
INSERT INTO works VALUES('E01', 'C02', 4000);
INSERT INTO works VALUES('E02', 'C02', 5000);
INSERT INTO works VALUES('E02', 'C03', 2500);
INSERT INTO works VALUES('E03', 'C01', 3500);
INSERT INTO works VALUES('E04', 'C02', 3000);
INSERT INTO works VALUES('E05', 'C03', 2000);
