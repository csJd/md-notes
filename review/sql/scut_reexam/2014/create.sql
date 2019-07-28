CREATE TABLE remunerations
(
    rno VARCHAR(5),
    rwage int,
    PRIMARY KEY (rno)
);

CREATE TABLE teachers
(
    tno VARCHAR(5),
    tname VARCHAR(20),
    tdept VARCHAR(20),
    rno VARCHAR(5),
    PRIMARY KEY (tno),
    FOREIGN KEY (rno) REFERENCES remunerations(rno)
      ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE courses
(
    cno VARCHAR(5),
    cname VARCHAR(20),
    ctime int,
    tno VARCHAR(5),
    PRIMARY KEY (cno),
    FOREIGN KEY (tno) REFERENCES teachers(tno)
      ON DELETE CASCADE ON UPDATE CASCADE
);
