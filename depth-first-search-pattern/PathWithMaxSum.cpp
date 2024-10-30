#include <iostream>
#include <limits>

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
    /**
     * Problem Challenge 2: Path with Maximum Sum (hard)
     * 
     * Find the path with the maximum sum in a given binary tree. 
     * Write a function that returns the maximum sum.
     * A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root. 
     * The path must contain at least one node.
     * 
     * Thinking:
     *      for each node:
     *          left sum = 0 if no left child else recurse on left
     *          right sum = 0 if not right child else recurse on right
     * 
     *          max sum to leaf = max(left sum, right sum) + current value
     * 
     *          sum path through node = left sum + right sum + current value
     *          compare with global max
     * 
     *          return the max sum to leaf
     */
    public:
    int findMaximumPathSum(TreeNode *root) {
        int globalMaximumSum = std::numeric_limits<int>::min();
        maxSumToLeaf(root, globalMaximumSum);
        return globalMaximumSum;
    }

    private:
    int maxSumToLeaf(TreeNode* node, int& globalMaximumSum){
        int leftSum = (node->left == nullptr) ? 0 : maxSumToLeaf(node->left, globalMaximumSum);
        int rightSum = (node->right == nullptr) ? 0 : maxSumToLeaf(node->right, globalMaximumSum);

        int maxSumToLeaf = std::max(leftSum, rightSum) + node->val;

        int pathSum = std::max({
            leftSum + rightSum + node->val,
            leftSum + node->val,
            rightSum + node->val,
            node->val,
        });
        globalMaximumSum = std::max(globalMaximumSum, pathSum);

        return maxSumToLeaf;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    std::cout << "Maximum Path Sum: " << sol.findMaximumPathSum(root) << std::endl;
    
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    std::cout << "Maximum Path Sum: " << sol.findMaximumPathSum(root) << std::endl;
    
    root = new TreeNode(-1);
    root->left = new TreeNode(-3);
    std::cout << "Maximum Path Sum: " << sol.findMaximumPathSum(root) << std::endl;
}