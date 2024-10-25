#include <iostream>

class TreeNode {
    public:
    int val = 0;
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
     * Binary Tree Path Sum (easy)
     * 
     * Given a root of the binary tree and an integer ‘S’, 
     * return true if the tree has a path from root-to-leaf such that 
     * the sum of all the node values of that path equals ‘S’. 
     * Otherwise, return false.
     * 
     * Logic: (try recursive)
     *      Base Case: leaf node
     *          return if the running sum up to this point + value of node == target
     * 
     *      Otherwise:
     *          left = boolean result of recursing on the left subtree
     *          right = boolean result of recursing on the right subtree
     * 
     *          return left or right  
     */
    static bool hasPath(TreeNode *root, int sum) {
        return hasPathRecursive(root, 0, sum);
    }

    private:
    static bool hasPathRecursive(TreeNode* node, int running_sum, int target){
        bool is_leaf = (node->left == nullptr && node->right == nullptr);
        int curr_sum = running_sum + node->val;
        
        // base case: leaf node
        if (is_leaf) {
            return (curr_sum == target);
        }

        // otherwise:
        bool found_left, found_right;
        if(node->left != nullptr){ 
            // check left subtree
            found_left = hasPathRecursive(node->left, curr_sum, target);
        }
        if(node->right != nullptr){
            // check right subtree
            found_right = hasPathRecursive(node->right, curr_sum, target);
        }

        return (found_left || found_right);
    }
};