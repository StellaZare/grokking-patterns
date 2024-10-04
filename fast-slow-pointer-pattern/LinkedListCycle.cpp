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
     * LinkedList Cycle (easy)
     * 
     * Given the head of a Singly LinkedList, write a function to determine if the LinkedList has a cycle in it or not.
     * 
     * Logic:
     *      Create a fast pointer that iterates though the list by 2 H->[*]->[ ]->[*]->[ ]->[*]->[ ]->*nullptr
     *      Create a fast pointer that iterates though the list by 1 H->[*]->[*]->[*]->[*]->[*]->[*]->*nullptr
     *      While the fast pointer can continue to iterate 
     *          Increment pointer
     *          If slow == fast then fast has wrapped around using a cycle
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            // Increment fast by 2
            fast = fast->next->next;
            // Incremet slow by 1
            slow = slow->next;

            if (slow == fast)
            {
                // slow has caught up to fast
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    ListNode *head = new ListNode(1); 
    head->next = new ListNode(2); 
    head->next->next = new ListNode(3); 
    head->next->next->next = new ListNode(4); 
    head->next->next->next->next = new ListNode(5); 
    head->next->next->next->next->next = new ListNode(6); 
    std::cout << "LinkedList has cycle: " << sol.hasCycle(head) << std::endl;

    head->next->next->next->next->next->next = head->next->next; // Create a cycle by connecting the last node to the third node
    std::cout << "LinkedList has cycle: " << sol.hasCycle(head) << std::endl;

    head->next->next->next->next->next->next = head->next->next->next; // Create a cycle by connecting the last node to the fourth node
    std::cout << "LinkedList has cycle: " << sol.hasCycle(head) << std::endl;
}