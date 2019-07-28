DECLARE
	a real;
	b real;
	c real;
	ave real;
	pro real;

BEGIN
	a := &a;
	b := &b;
	c := &c;
	ave := (a + b + c) / 3;
	pro := a * b * c;
	DBMS_OUTPUT.PUT_LINE(' AVE = ' || ave);
	DBMS_OUTPUT.PUT_LINE(' PRODUCT = ' || pro);
END;
/
