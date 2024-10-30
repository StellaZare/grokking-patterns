#include <iostream>
#include <vector>
#include <algorithm>

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
    /**
     * Problem Challenge 1: Tree Diameter (medium)
     * 
     * Given a binary tree, find the length of its diameter. 
     * The diameter of a tree is the number of nodes on the longest path between any two leaf nodes. 
     * The diameter of a tree may or may not pass through the root.
     * 
     * Note: You can always assume that there are at least two leaf nodes in the given tree.
     * 
     * Thinking:
     *      traverse the tree
     *      for each node 
     *          determine the maximum distance (# of nodes) from the node to a leaf
     *          if leaf = 1
     *          else = max (func(left), func(right)) + 1
     *          
     *          determine the maximum diameter through the node
     *          func(left) + func(right) + 1
     *          compare with gloal max
     * 
     */
    public:
    int findDiameter(TreeNode *root) {
        int treeDiameter = 0;
        findDiameterRecursive(root, treeDiameter);
        return treeDiameter;
    }

    private:
    int findDiameterRecursive(TreeNode* node, int& treeDiameter){

        if (node->left == nullptr && node->right == nullptr){
            // at leaf node
            return 1;
        }

        int leftToLeaf = (node->left == nullptr) ? 0 : findDiameterRecursive(node->left, treeDiameter);
        int rightToLeaf = (node->right == nullptr) ? 0 : findDiameterRecursive(node->right, treeDiameter);

        int nodesToLeaf = std::max(leftToLeaf, rightToLeaf) + 1;

        int pathThroughNode = leftToLeaf + rightToLeaf + 1;
        if (pathThroughNode > treeDiameter) treeDiameter = pathThroughNode;

        return nodesToLeaf;
    }
};