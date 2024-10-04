Sliding Window Pattern
------------------------------------------------------------------

- Useful when asked to find or calculate a property of contiguous subsets of a given subsets

i.e. Given an array, find the average of each subarray of ‘K’ contiguous elements in it.


## Typical structure: 


- Uses 2 pointers: one pointing to the start of the subarray, the other pointing to the end
- The end pointer is increment with every iteration of the larger loop iterating the complete subsets

- The start pointer is increment when a certain criteria is met


``` C++
int start = 0;
while (int end = 0; end < arr.size(); end++)
{
    ...
    if / while (condition) 
    { 
        ...
        start++; 
    }
}
```

## Useful Data Structures

- A `unordered_map` can be used in tandem to keep track of the number of elements in the subset and their frequency

```C++
#include<unordered_map>
...
std::unordered_map<key, value> map {};

map.size()      // returns the number of keys
map[key]        // access the value (creates it if not there)
map.at(key)     // access the value (throws if not there)
map.erase(key)  // erases the key value
map.find(key)   // returns iterator to element or map.end() if not found
```



