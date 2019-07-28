CREATE TABLE teachers
(
    tno VARCHAR(5),
    tname VARCHAR(20),
    tsex char(2),
    PRIMARY KEY (tno)
);

CREATE TABLE courses
(
    cno VARCHAR(5),
    cname VARCHAR(20),
    ctime INT,
    PRIMARY KEY (cno)
)

CREATE TABLE works
(
    tno VARCHAR(5),
    cno VARCHAR(5),
    wyear INT,
    wsemester char(2),
    PRIMARY KEY (tno, cno),
    FOREIGN KEY (tno) REFERENCES teachers(tno),
    FOREIGN KEY (cno) REFERENCES courses(cno)
)
