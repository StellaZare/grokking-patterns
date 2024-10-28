#include <iostream>
#include <vector>
#include <queue>

class TreeNode {
    public:
    int val = 0;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
    public:
    /**
     * Count Paths for a Sum (medium)
     * 
     * Given a binary tree and a number ‘S’, find all paths in the tree such that 
     * the sum of all the node values of each path equals ‘S’. 
     * Please note that the paths can start or end at any node but 
     * all paths must follow direction from parent to child (top to bottom).
     * 
     * Thinking:
     *      let path be the path being considered = {}
     *      let sum = target
     * 
     *      Recursive:
     *      add the current node to the path
     *      subtract current node value from sum
     *      
     *      while (sum < 0):
     *          the current path is larger than target
     *          remove the front node in path
     *          add the front node value to the sum 
     *      if (sum == 0): 
     *          the current path needs to be counted
     * 
     *      check the children
     *      
     *      return count + left count + right count
     *      
     */
    int countPaths(TreeNode *root, int S) {
        return countPathRecursive(root, {}, S);
    }

    private:
    int countPathRecursive(TreeNode* node, std::vector<int> path, int sum){
        int count = 0;

        path.push_back(node->val);
        sum -= node->val;

        while (sum < 0){
            sum += path.front();
            path.erase(path.begin());
        }
        if (sum == 0){
            count = 1;
        }

        int count_left = (node->left == nullptr) ? 0 : countPathRecursive(node->left, path, sum);
        int count_right = (node->right == nullptr) ? 0 : countPathRecursive(node->right, path, sum);

        return count + count_left + count_right;
    }
};
