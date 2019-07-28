CREATE TABLE dept_sal AS
SELECT deptno,COUNT(empno) AS total_emp,SUM(sal) AS total_sal FROM emp GROUP BY deptno;
DESC dept_sal;

--创建触发器
CREATE OR REPLACE TRIGGER emp_info
AFTER INSERT OR UPDATE OR DELETE ON emp

DECLARE
	CURSOR cur_emp IS
    SELECT deptno,COUNT(empno) AS total_emp,SUM(sal) AS total_sal
	FROM emp
	GROUP BY deptno;
BEGIN
	DELETE dept_sal;  --触发时首先删除映射表信息
	FOR v_emp IN cur_emp LOOP
		--DBMS_OUTPUT.PUT_LINE(v_emp.deptno || v_emp.total_emp || v_emp.total_sal);
		INSERT INTO dept_sal
		VALUES(v_emp.deptno,v_emp.total_emp,v_emp.total_sal);
	END LOOP;
END;
/

INSERT INTO emp(empno,deptno,sal) VALUES('123','10',10000);
SELECT * FROM dept_sal;
DELETE EMP WHERE empno=123;
SELECT * FROM dept_sal;
