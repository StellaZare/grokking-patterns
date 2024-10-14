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
     * Reverse a Sub-list (medium)
     * 
     * Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.
     * 
     * Logic:
     *      iterate through the list until the p-th element
     *      reverse list until reach q-th element or end of list
     * 
     *      curr = head; prev = null; element = 1;
     *      before_p = null; after_q = null; p = null; q = null;
     * 
     *      while have elements
     *          next = curr.next
     * 
     *          for nodes after p and before q flip the arrow
     *          if p < element <= q then:
     *              curr.next == prev
     *          if element = p-1 then: save before p
     *          if element = q+1 then: save after q can break
     *          if element = p then: save p
     *          if element = q then: save q
     * 
     *          prev=node
     *          node = next
     *          element++
     *              
     *      case: p is first element then before_p null at the end
     *      case: q is last element then after_q null at the end
     *      
     *      if (before_p == null) head = q
     *      else before_p.next = q
     *      
     *      p.next = after_q
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    ListNode *reverse(ListNode *head, int p, int q) {
        if (p == q) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int element = 1;

        ListNode* before_p = nullptr;
        ListNode* p_ptr = nullptr;
        ListNode* q_ptr = nullptr;
        ListNode* after_q = nullptr;

        while(curr != nullptr){
            next = curr->next;

            // save pointers
            if(element == p-1) before_p = curr;
            else if(element == p) p_ptr = curr;
            else if(element == q) q_ptr = curr;
            else if(element == q+1){
                after_q = curr;
                break;
            }

            // flip sublist elements
            if(p < element && element <= q){ 
                curr->next = prev;
            }

            // increment
            prev = curr;
            curr = next;
            element++;
        }

        if(p == 1) head = q_ptr;
        else before_p->next = q_ptr;

        p_ptr->next = after_q;

        return head;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *result = sol.reverse(head, 3, 5);
    std::cout << "Nodes of the reversed LinkedList are: ";
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;
}