#include <iostream>
#include <vector>

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
    public:
    /**
     * Path With Given Sequence (medium)
     * 
     * Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.
     * 
     * Thinking: easier the sequence must be presetn "root to leaf" specifically
     *      so at each level of the tree there is exactly one value we are looking for
     * 
     *      let idx = 0, node = root and sequence = sequence
     *      recursive:
     *      let found = node.value == sequence.at(idx)
     *      if not found: return false
     * 
     *      if found and leaf node: return true
     * 
     *      if found and not leaf node: 
     *          found left = recurse on left child
     *          found right recurse on right child
     *          return found left or right
     *  
     */
    bool findPath(TreeNode *root, const std::vector<int> &sequence) {
        return findPathRecursive(root, 0, sequence);
    }

    private:

    bool findPathRecursive(TreeNode* node, int seq_idx, const std::vector<int>& seq){
        bool is_leaf = (node->left == nullptr && node->right == nullptr);
        bool is_match = (node->val == seq.at(seq_idx));

        if (!is_match) return false;
        else if (is_match && is_leaf) return true;
        else {
            bool left_child_match = (node->left == nullptr) ? false : findPathRecursive(node->left, seq_idx+1, seq);
            bool right_child_match = (node->right == nullptr) ? false :findPathRecursive(node->right, seq_idx+1, seq);
            return left_child_match || right_child_match;
        }  
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);

    std::cout << "Tree has path sequence: " 
        << sol.findPath(root, std::vector<int>{1, 0, 7}) << std::endl;
    std::cout << "Tree has path sequence: " 
        << sol.findPath(root, std::vector<int>{1, 1, 6}) << std::endl;
}