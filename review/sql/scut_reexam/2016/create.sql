CREATE TABLE departments
(
    dno VARCHAR(5),
    dname VARCHAR(20),
    PRIMARY KEY (dno)
);

CREATE TABLE classes
(
    cno VARCHAR(5),
    cspec VARCHAR(20),
    dno VARCHAR(5),
    cyear INT,
    cnum INT CHECK (cnum < 31),
    PRIMARY KEY (cno),
    FOREIGN KEY (dno) REFERENCES departments(dno)
);

CREATE TABLE students
(
    sno VARCHAR(5),
    sname VARCHAR(20),
    -- sname VARCHAR(20) NOT NULL,
    sdate DATE,
    cno VARCHAR(5),
    PRIMARY KEY (sno),
    FOREIGN KEY (cno) REFERENCES classes(cno)
    -- FOREIGN KEY (cno) REFERENCES classes(con) ON DELETE CASCADE ON UPDATE CASCADE
);

ALTER TABLE students ALTER COLUMN sname VARCHAR(20) NOT NULL;
ALTER TABLE students ADD CONSTRAINT m_cascade
  FOREIGN KEY (cno) REFERENCES classes(cno)
  ON DELETE CASCADE ON UPDATE CASCADE;
-- 删除约束就是 ALTER TABLE students DROP CONSTRAINT m_cascade
