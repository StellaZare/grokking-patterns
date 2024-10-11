Merge Intervals Pattern
------------------------------------------------------------------

- Efficient technique to deal with overlappingintervals

- Given 2 intervals A and B there will be 6 different ways they can relate
    1. no overlap - A then B
    2. end of A overlaps the start of B
    3. A completely overlaps B
    4. end of B overlaps the start of A
    5. B completely overlaps A
    6. no overlap - B then A

### Sorting Intervals
To sort the intervals with a custom comparator, we need to define a comparator function than takes as input 2 intervals and returns a boolean value. The comparator function should return true if the first interval is less than the second one, and false otherwise.

If using a lamba function:
```C++
sort(intervals.begin(), intervals.end(), [](const Interval &x, const Interval &y) {
    // custom comparator returns true if x is less than y
    return x.start < y.start;
});

```

If using a custom function:
```C++
bool compare(const Interval &x, const Interval &y) {
    return x.start < y.start;
}

sort(intervals.begin(), intervals.end(), compare);
```

