# Coursera Week 3

## Section1 Mergesort

### Bottom-up mergesort
```java
public class MergeBU
{
    private static void merge(...)
    { /* as before */ }
    public static void sort(Comparable[] a)
    {
        int N = a.length;
        Comparable[] aux = new Comparable[N];
        for (int sz = 1; sz < N; sz <<= 1)
            for (int lo = 0; lo < N-sz; lo += sz<<1)
                merge(a, aux, lo, lo+sz-1, Math.min(lo+sz+sz-1, N-1));
    }
}
```
