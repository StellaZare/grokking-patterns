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
