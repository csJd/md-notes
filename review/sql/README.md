# My Frequently Forgotten Facts (FFFs)

------

[See W3School ref. HERE](http://www.w3school.com.cn/sql/index.asp)

## 0. Tips

* `BETWEEN 1 AND 5` 包括两端的值（1 和 5）
* 通配符 `%` 表示任何字符出现任意次数，`?`（部分 DBMS 中是 `_`) 匹配任何字符刚好一次
* `WHERE` 过滤行， `HAVING` 过滤分组
* 子句顺序：`SELECT`, `FROM`, `WHERE`, `GROUP BY`, `HAVING`, `ORDER BY`

## 1. 各 DBMS 数据类型

详见 <http://www.w3school.com.cn/sql/sql_datatypes.asp>。

## 2. SQL Server 命令行工具 `sqlcmd` 的使用

``` cmd
sqlcmd -S .\SQLEXPRESS -U sa
```

See doc [here](https://msdn.microsoft.com/zh-cn/library/ms165702.aspx) and [here](https://msdn.microsoft.com/zh-cn/library/ms162773.aspx).
显示当前数据库所有表：

``` sql
select name from sysobjects where type='U'
go
```

SQL Server 不适合命令行使用，乖乖用 [SSMS](https://docs.microsoft.com/en-us/sql/ssms/download-sql-server-management-studio-ssms) 吧。

## 2. SQL Server 常用语句 [[Official doc here](https://docs.microsoft.com/en-us/sql/t-sql/statements/statements)]

``` sql
-- 建表
CREATE TABLE classes
(
    cno VARCHAR(5),
    cnum INT CHECK (cnum < 31), -- CHECK约束
    PRIMARY KEY (cno),
    FOREIGN KEY (dno) REFERENCES departments(dno)
      ON DELETE CASCADE ON UPDATE CASCADE -- 级联更改
);

-- 修改列
ALTER TABLE students ALTER COLUMN sname VARCHAR(20) NOT NULL;

-- 约束 http://www.w3school.com.cn/sql/sql_constraints.asp
-- 修改表外键约束
ALTER TABLE students ADD CONSTRAINT m_cascade
  FOREIGN KEY (cno) REFERENCES classes(cno)
  ON DELETE CASCADE ON UPDATE CASCADE;
-- 添加CHECK约束
ALTER TABLE students ADD CONSTRAINT c_check
  CHECK (sage < 30);
-- 删除约束
ALTER TABLE students DROP CONSTRAINT m_cascade;

-- 触发器 <https://docs.microsoft.com/en-us/sql/t-sql/statements/create-trigger-transact-sql>
CREATE TRIGGER u_cnum
ON students
AFTER INSERT
AS
UPDATE classes
SET cnum = cnum + 1
WHERE classes.cno = inserted.cno
```
