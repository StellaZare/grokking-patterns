Intoduction to Two Heaps Pattern
------------------------------------------------------------------

- given a set of elements that we can divide into 2 disjoint sets
- need to know the smallest element in once subset and the largest in the other

MAX heap ordered from largest at the root and smallest at the leaves
```C++
std::priority_queue<T> name {};
```

MIN heap oderes from smallest at the root and largest at the leaves
```C++
std::priority_queue<T, std::vector<T>, greater<T>> name {};
```