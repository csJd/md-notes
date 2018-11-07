## Section 1： Stacks and Queues

### Generic stack: array implementation

```java
public class AStack<Item> {
  private Item[] s;
  private int n = 0;
  public Astack(int capacity){
    s = (Item[]) new Object[capacity];
  }
  
  public boolean isEmpty(){
    return n == 0;
  }
  
  public void push(Item item){
    s[n++] = item;
  }
  
  public Item pop(){
    return s[--n];
  }
}
```

### Interview question 3

> Explain why Java prohibits generic array creation : Java arrays are covariant but Java generics are not: that is, String[] is a subtype of Object[], but Stack<String> is not a subtype of Stack<Object>.


### How to Implement RandomizedQueue.java

> Hint : Use an array representation (with resizing). To remove an item, swap one at a random position (indexed 0 through N-1 ) with the one at the last position (index N-1 ). Then delete and return the last object, as in ResizingArrayStack. 

## Section 2： Sorting

### Knuth shuffle

> Knuth shuffling algorithm produces a uniformly random permutation of the input array in linear time.
* In iteration i , pick integer r **between 0 and i** uniformly at random.
*  Swap a[i] and a[r].

### Convex hull

* geometric properties
  > Fact. Can traverse the convex hull by making only counterclockwise turns.
  > Fact. The vertices of convex hull appear in increasing order of polar angle with respect to point p with lowest y-coordinate.

* Graham scan
  * Choose point p with smallest y-coordinate.
  * Sort points by polar angle with p.
  * Consider points in order; discard unless it create a ccw turn.

* CCW Given three points a, b, and c, is a → b → c a counterclockwise turn?
    - Determinant (or cross product) gives 2x signed area of planar triangle.
    -  If signed area > 0, then a → b → c is counterclockwise.
    -  If signed area < 0, then a → b → c is clockwise.
    -  If signed area = 0, then a → b → c are collinear.


### Dijkstra 3-way partitioning

* Let v be partitioning item a[lo].
* Scan i from left to right.
    - (a[i] < v): exchange a[lt] with a[i]; increment both lt and i
    - (a[i] > v): exchange a[gt] with a[i]; decrement gt
    - (a[i] == v): increment i

