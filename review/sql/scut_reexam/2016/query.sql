-- 条件查询
SELECT dname 系名称, cspec 专业名称, sname 学生名字
 FROM students s, classes c, departments d
 WHERE s.cno = c.cno AND c.dno = d.dno
 AND dname = 'dname' AND cspec = 'cspec' AND sname LIKE '%s%';

-- 统计每个系学生人数
SELECT dname 系名称, COUNT(*) 人数
 FROM departments d, classes c, students s
 WHERE d.dno = c.dno AND s.cno = c.cno
 GROUP BY d.dno;

-- 按入学年份统计学生人数
SELECT cyear 入学年份, COUNT(*) 人数
 FROM classes c, students s
 WHERE c.cno = s.cno
 GROUP BY cyear;
