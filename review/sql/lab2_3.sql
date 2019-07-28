DECLARE
	addsal real:=0;
	sjob emp.job%type;

BEGIN
	SELECT job INTO sjob FROM emp
	WHERE ename = 'SCOTT ';

	IF sjob = 'MANAGER ' THEN addsal := 0.20;
	ELSIF sjob = 'SALESMAN ' THEN addsal := 0.15;
	ELSIF sjob = 'ANALYST ' THEN addsal := 0.07;
	END IF;
	
	UPDATE emp SET sal = sal * (1 + addsal)
	WHERE ename = 'SCOTT ';

	COMMIT;
END;
/
