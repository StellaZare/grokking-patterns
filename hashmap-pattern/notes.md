Intoduction to Hashing
------------------------------------------------------------------
Hashing: takes an input and returns a fixed sixe string as the hash value. Hash values are mostly unique.
Hash function: the function that converts input to the fixed length string output.

Common uses:
- Quick data retrieval 
- Data integrity checks

Hash Table (Maps): data structure that allows us to store and fetch data efficiently. Implements an associative array abstract data type.

Components of hash table:
- Keys: unique identifiers. Inputs to the hash function.
- Values: the actual data stored. Retrieved with the key.
- Hash function: transforms keys to hash values corresponding to a bucket.
- Bucket: a storage grouping in the hash table

Resolving collisions:
- Open addressing / Closed hashing: probing for the next available slot within the hash table itself. This approach is called open addressing since it opens up the entire hash table for finding an empty slot during insertion. It is also known as closed hashing because the insertion is restricted to existing slots within the table without using any external data structures.
    - Linear probing
    - Quadratic probing
    - Double hashing
    - Random probing

- Chaining / Open hashing: Each slot in the hash table points to a separate data structure, such as a linked-list. This linked-list or chain stores multiple elements that share the same hash index. When a collision occurs, new elements are simply appended to the existing list in the corresponding slot.
    - Pros: Dynamic memory(always has space and uses what it needs), simple, graceful
    - Cons: Memory overhead, cache inefficient, external fragmentation, memory allocation overhead