# [Coursera Week-1](https://www.coursera.org/learn/algorithms-part1/home/week/1)



## Section 1 : Introduction

* Course introduction (3:28). In the video, a video compression artifact has removed the path between the two nodes.
* Course introduction (6:46). In the video, the link to the booksite should be http://algs4.cs.princeton.edu.
* C ourse introduction (7:52). In the video, the link to the booksite should be http://introcs.cs.princeton.edu.
* Quick-Find, slide 14. Find: return id of p.
* Quick-Union, slide 23. Find: return root of p.
* Quick-Union Improvements, slide 35. There are N = 11 nodes (and not 10).
* Quick-Union Improvements, slide 35. The given tree could not have been created using weighted quick union.
* Quick-Union Improvements (6:35). Video is missing semicolon with the statement int i = root(p).
* Quick-Union Improvements (10:55). Video says "Ackermann function" instead of "inverse Ackermann function."
* Mathematical Models, slide 28, 30, 32. Number of increments should be 1/2 N (N+1) to N^2.



## Section 2 : Union-Find
### 1. M union-find operations on a set of N objects
| algorithm                     | worst-case time |
| ----------------------------- | --------------- |
| quick-find                    | M N             |
| quick-union                   | M N             |
| weighted QU                   | N + M log N     |
| QU + path compression         | N + M log N     |
| weighted QU + path compressio | N + M lg* N     |

### 2.  My Implementation

```java
public class UnionFindSet {
    private int[] id;

    public UnionFindSet() { }

    public UnionFindSet(int n) {
        id = new int[n];
        init();
    }

    public void init() {
        for (int i : id) {
            id[i] = -1;
        }
    }

    private int findRoot(int i) {
        return id[i] < 0 ? i : (id[i] = findRoot(id[i]));
    }

    public boolean connected(int i, int j) {
        return findRoot(i) == findRoot(j);
    }

    public void merge(int i, int j) {
        int ri = findRoot(i);
        int rj = findRoot(j);
        if(ri == rj) {
            return;
        }
        if(id[ri] < id[rj]) {
            id[ri] = id[ri] + id[rj];
            id[rj] = ri;
        } else {
            id[rj] = id[ri] + id[rj];
            id[ri] = rj;
        }
    }
}
```

### 3. Assessment : [Percolation](http://coursera.cs.princeton.edu/algs4/assignments/percolation.html)
* 完成[Percolation类](https://github.com/csJd/learning-algs4/blob/master/src/Percolation.java)：利用`algs4`提供的`WeightedQuickUnionUF`类完成渗透检测，完成各个函数的实现
* 完成[PercolationStats类](https://github.com/csJd/learning-algs4/blob/master/src/PercolationStats.java),输入n和trials，即在n*n的图上进行trials次随机试验，试验过程如下：
    * 将图上所有的点设置为`blocked`
    * 每次在图上随机选取一个点，对该点进行open操作，直到整个图发生渗透（有一个从最高处到最低处的连同块）
    * 记录open点的个数
    * 计算输出trails次试验的样本均值，样本标准差等统计量

    ​

## Section 3 : Theory of algorithms
### 1. Commonly-used notations in the theory of algorithms

| notation  | provides          | example | used to                   |
| --------- | ----------------- | ------- | ------------------------- |
| Big Theta | asymptotic        | Θ(N²)   | classify algorithms       |
| Big Oh    | Θ(N²) and smaller | O(N²)   | develop upper bounds      |
| Big Omega | Θ(N²) and larger  | Ω(N²)   | develop lower bounds      |
| Tilde     | leading term      | ~ 10 N² | provide approximate model |

![](https://github.com/csJd/csJd.github.io/raw/res/coursera-week1-p1.png)

### 2. 3-SUM 问题的O(N²)解法

```java
Array.sort(arr);
for (int i = 0; i < arr.length; ++i){
  int j = i + 1;
  int k = arr.lenth - 1;
  while (j < k){
    if (arr[i] + arr[j] + arr[k] > 0){
      --k;
    } else if (arr[i] + arr[j] + arr[k] < 0){
      ++j;
    } else {
      // i, j, k is an answer;
    }
  }
}
```



### 3. Egg drop problem

**Egg drop.** Suppose that you have an n-story building (with floors 1 through n) and plenty of eggs. An egg breaks if it is dropped from floor T or higher and does not break otherwise. Your goal is to devise a strategy to determine the value of T given the following limitations on the number of eggs and tosses:

- Version 0: 1 egg, ≤T tosses.
- Version 1: ∼1lgn eggs and ∼1lgn tosses.
- Version 2: ∼lgT eggs and ∼2lgT tosses.
- Version 3: 2 eggs and ∼2√n tosses.
- Version 4: 2 eggs and ≤c√T tosses for some fixed constant c.

```
Version 0: sequential search.
Version 1: binary search.
Version 2: find an interval containing T of size ≤2T, then do binary search.
Version 3: find an interval of size n√, then do sequential search. Note: can be improved to ∼2√n tosses.
Version 4: 1+2+3+…+t∼12t2. Aim for c=2√2.
```

