Cyclic Sort Pattern
------------------------------------------------------------------

- Useful for problems involving arrays containing numbers in a given range

> **Example**: You are given an unsorted array containing n numbers taken from the range 1 to n. 
>The array can have duplicates, which means that some numbers will be missing. Find all the missing numbers.

- The Cyclic Sort Pattern follows a specific approach:
    1. Traverse the array one number at a time
    2. If the current element is not at the correct index, swap it with the number at its correct index
    3. Repeat this process until we have traversed the entire array

**Note**: If all numbers in the range are present, then you can complete step 2 by comparing the current element with the current index. If they are not equal, swap them.

However is there are duplicates, you need to check 'if the spot for the correct element already contains the correct element.

So, if the current element is `e` you want to check if `arr[e-1] == e` if it is,then you have a duplicate and you can skip the swap.
