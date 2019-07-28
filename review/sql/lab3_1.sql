CREATE OR REPLACE TRIGGER del_emp_deptno
BEFORE DELETE ON dept
FOR EACH ROW
BEGIN
	DELETE FROM emp WHERE deptno=:OLD.deptno;
END;
/

SELECT empno, ename, deptno FROM emp
WHERE deptno = 20;
DELETE FROM emp WHERE deptno = 20;
SELECT ename, deptno FROM emp
WHERE deptno = 20;
