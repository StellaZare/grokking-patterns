#include <stack>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
    public:
    /**
     * Remove Nodes From Linked List (medium)
     * 
     * Given the head node of a singly linked list, modify the list such that 
     * any node that has a node with a greater value to its right gets removed. 
     * The function should return the head of the modified list.
     * 
     * Logic:
     *      (suppose we have an array)
     *      given stack 'sk'
     *      for element 'e' in the array 
     *          while sk is not empty and e is larger than sk.top: pop the top
     *          push e 
     * 
     *      for element in sk: pop and add to list 'l'
     *      reverse l and return it
     * 
     *      (for linked list)
     *      after reversing 'l'
     *      given pointer 'p' to head
     *      for element 'e' in l
     *          while p.value != e: free
     */
    ListNode* removeNodes(ListNode* head) {
        std::stack<ListNode*> sk {};

        ListNode* curr = head;
        while(curr != nullptr){
            while(!sk.empty() && sk.top()->val < curr->val) sk.pop();

            sk.push(curr);

            curr = curr->next;
        }

        ListNode* new_head = nullptr;

        while(!sk.empty()){
            ListNode* to_add = sk.top();

            to_add->next = new_head;
            new_head = to_add;

            sk.pop();
        }

        return new_head;
    }
};

int main() {
    Solution solution;

    // Creating the linked list 5 -> 3 -> 7 -> 4 -> 2 -> 1
    ListNode* head1 = new ListNode(5);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(7);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(2);
    head1->next->next->next->next->next = new ListNode(1);
    head1 = solution.removeNodes(head1);

    // Printing the modified list: 7 -> 4 -> 2 -> 1
    ListNode* node = head1;
    while (node) {
        std::cout << node->val;
        if (node->next) {
            std::cout << " -> ";
        }
        node = node->next;
    }
    std::cout << std::endl;

    return 0;
}