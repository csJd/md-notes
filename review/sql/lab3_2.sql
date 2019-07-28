CREATE TABLE test
(
	t_id   NUMBER(4),
	t_name VARCHAR2(20),
	t_age NUMBER(2),
	t_sex CHAR
);

CREATE TABLE test_log
(
	l_user   VARCHAR2(15),
	l_type   VARCHAR2(15),
	l_date   VARCHAR2(30)
);

CREATE OR REPLACE TRIGGER test_trigger
AFTER DELETE OR INSERT OR UPDATE ON test

DECLARE
v_type test_log.l_type%TYPE;
BEGIN
	IF INSERTING THEN --INSERT触发
		v_type := 'INSERT';
		DBMS_OUTPUT.PUT_LINE('记录已经成功插入，并已记录到日志');
	ELSIF UPDATING THEN --UPDATE触发
		v_type := 'UPDATE';
		DBMS_OUTPUT.PUT_LINE('记录已经成功更新，并已记录到日志');
	ELSIF DELETING THEN
		v_type := 'DELETE';
		DBMS_OUTPUT.PUT_LINE('记录已经成功删除，并已记录到日志');
	END IF;
	INSERT INTO test_log VALUES(user,v_type,
        TO_CHAR(sysdate,'yyyy-mm-dd hh24:mi:ss'));
END;
/
