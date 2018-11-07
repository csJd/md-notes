## Mincut problem
***Def.*** A **st-cut (cut)** is a partition of the vertices into two disjoint sets, with s in one set A and t in the other set B.
***Def.***  Its **capacity** is the sum of the capacities of the edges from A to B.

***Minimum st-cut (mincut) problem.*** Find a cut of minimum capacity.

## Maxflow problem

***Input.***  An edge-weighted digraph, source vertex s, and target vertex t.
***Def.***  An **st-flow (flow)** is an assignment of values to the edges such that:

* Capacity constraint: 0 ≤ edge's flow ≤ edge's capacity.
* Local equilibrium: inflow = outflow at every vertex (except s and t).

***Def.*** The value of a flow is the inflow at t.(we assume no edge points to s or from t)
***Maximum st-flow (maxflow) problem.*** Find a flow of maximum value.

### Ford-fulkerson algorithm

***Initialization.*** Start with 0 flow.
***Augmenting path.*** Find an undirected path from *s* to *t* such that:

* Can increase flow on forward edges (not full).
* Can decrease flow on backward edge (not empty).

```
# Ford-fulkerson algorithm
Start with 0 flow.
While there exists an augmenting path:
 - find an augmenting path
 - compute bottleneck capacity
 - increase flow on that path by bottleneck capacity
```

