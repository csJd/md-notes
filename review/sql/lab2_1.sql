DECLARE
	no integer;
	res emp%ROWTYPE;
BEGIN
	no := &no;
	SELECT * INTO res FROM emp
	WHERE emp.empno = no;
	DBMS_OUTPUT.PUT_LINE(' -- ENAME : '||res.ename);
	DBMS_OUTPUT.PUT_LINE(' -- JOB   : '||res.job);
	DBMS_OUTPUT.PUT_LINE(' -- SAL   : '||res.sal);
END;
/
