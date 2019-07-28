UPDATE emp
SET comm = 0 WHERE comm IS NULL;
DECLARE
	addcomm emp.comm%type;
	CURSOR emp_cs IS SELECT DISTINCT deptno FROM emp;

BEGIN
	FOR e IN emp_cs LOOP
		IF e.deptno = 30 THEN  addcomm := 150;
		ELSIF e.deptno = 20 THEN addcomm := 250;
		ELSIF e.deptno = 10 THEN addcomm := 350;
		END IF;
		UPDATE emp
		SET comm = comm + addcomm WHERE deptno = e.deptno;
	END LOOP;
	COMMIT;
END;
/
