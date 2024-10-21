Intoduction to Stacks
------------------------------------------------------------------

Last In First Out (LIFO) Data Structure

Operations:
- push: add element to the stack
- pop: remove element from stack
- peek: look at the top element without removing it
- isEmpty

Overflow: adding to a full stack
Underflow: removing from an empty stack

Applications of Stacks
- memory management (call stack)
- evaluating arithmetic expressions
- backtracking algorithms
- DFS 
- borwser history

Language specific implementation: `std::stack`

```C++
#include <stack>

std::stack<T> s;

s.push(x);    // Return void
s.size();     // Return size_t
s.pop();      // Return void
s.top();      // Return reference
s.empty();    // Returns bool
```

Intoduction to Monotonic Stacks
------------------------------------------------------------------
- Special type of stack, which maintains a specific ordering of elements. 
- Ensures a de/increasing order of elements by enforcing push/pop rules
- Especially useful for "Next smaller/larger" element problems

Types of MS
1. Monotonically Increasing: element values increasing i.e. largest value at the top
2. Monotonically Decreasing: element values decreasing i.e. smallest value at the top
