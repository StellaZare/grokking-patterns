#include <iostream>

class ListNode {
    public:
    int val = 0;
    ListNode *next;

    ListNode(int value) {
        this->val = value;
        next = nullptr;
    }
};

class Solution {
    public:
    /**
     * Problem Challenge 1: Palindrome LinkedList (medium)
     * 
     * Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.
     * Your algorithm should use constant space 
     * and the input LinkedList should be in the original form once the algorithm is finished. 
     * The algorithm should have O(N) time complexity where ‘N’ is the number of nodes in the LinkedList.
     * 
     * Logic:
     *      As seen in the LinkedList middle problem, we can find the end and the middle of a linked list in O(N/2)
     *      slow and fast start at the head
     *      while (fast is not the last node OR not the second to last node) slow += 1; fast += 2;
     * 
     *      Now we have a pointer to the end and middle of the LL
     *      Initilize another pointer 'start' pointing at the head
     *      While the start != fast and start != middle
     *      Check they are the same; move start forward and fast backward;
     * 
     *      even: H -> [ ] -> [ ] -> [<s>] -> [ ] -> [f] -> null
     * 
     *      odd:  H -> [ ] -> [<s] -> [f>] -> [ ] -> null
     */
    bool isPalindrome(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            // TODO: Write your code here
        }
    }
};
