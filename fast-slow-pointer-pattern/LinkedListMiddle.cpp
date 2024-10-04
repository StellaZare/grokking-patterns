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
     * Given the head of a Singly LinkedList, write a method to return the middle node of the LinkedList.
     * If the total number of nodes in the LinkedList is even, return the second middle node.
     * i.e. H -> [ ] -> [ ] -> [ ] -> [*] -> [ ] -> [ ] -> nullptr
     * 
     * Logic:
     *      Create a fast pointer that iterates though the list by 2 H->[*]->[ ]->[*]->[ ]->[*]->[ ]->*nullptr
     *      Create a fast pointer that iterates though the list by 1 H->[*]->[*]->[*]->[*]->[*]->[*]->*nullptr
     *      The fast pointer will reach the end of the list in half as many hops
     *          For even list: H -> [ ] -> [ ] -> [ ] -> [S] -> [ ] -> [ ] -> F nullptr
     *          For odd list: H -> [ ] -> [ ] -> [S] -> [ ] -> [F] -> nullptr
     * 
     *      So when F has reached the end of the list S is pointing to the middle element
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    ListNode *findMiddle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            // Increment fast by 2
            fast = fast->next->next;
            // Incremet slow by 1
            slow = slow->next;
        }

        return slow;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    std::cout << "Middle Node: " << sol.findMiddle(head)->val << std::endl;

    head->next->next->next->next->next = new ListNode(6);
    std::cout << "Middle Node: " << sol.findMiddle(head)->val << std::endl;

    head->next->next->next->next->next->next = new ListNode(7);
    std::cout << "Middle Node: " << sol.findMiddle(head)->val << std::endl;
}