Fast & Slow Pointers Pattern
------------------------------------------------------------------

- Also known as the Hare & Tortoise Algorithm
- Uses 2 pointers that move through the data structure at different speeds
- Algorithm proves the pointers are bound to meet
- Useful when dealing with cyclic arrays or linked lists

## Typical Structure

- The fast pointer is increment by 2s

- The slow pointer is increment by 1s


``` C++
ListNode* slow = head;
ListNode* fast = head;

while (fast != nullptr && fast->next != nullptr)
{
    // Increment fast by 2
    fast = fast->next->next;
    // Incremet slow by 1
    slow = slow->next;
    
    ...
}
```