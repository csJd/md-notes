CREATE TABLE employees
(
    eno VARCHAR(5),
    ename VARCHAR(20),
    esex  VARCHAR(5),
    eage INT,
    PRIMARY KEY (eno)
);

CREATE TABLE companies
(
    cno VARCHAR(5),
    cname VARCHAR(20),
    PRIMARY KEY (cno)
);

CREATE TABLE works
(
    eno VARCHAR(5),
    cno VARCHAR(5),
    salary INT,
    PRIMARY KEY (eno, cno),
    FOREIGN KEY (eno) REFERENCES employees(eno) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (cno) REFERENCES companies(cno) ON DELETE CASCADE ON UPDATE CASCADE
);
