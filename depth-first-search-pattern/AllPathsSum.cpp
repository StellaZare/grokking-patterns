#include <iostream>
#include <vector>

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
     * All Paths for a Sum (medium)
     * 
     * Given a binary tree and a number ‘S’, find all paths from root-to-leaf 
     * such that the sum of all the node values of each path equals ‘S’.
     * 
     * Logic:
     *      base case: at a leaf
     *      if (sum - node value == 0) then add node value to path and add path to all paths
     * 
     *      otherwise:
     *      sum -= node value
     *      add node value to path
     *      if left child: findPathRecursive(left child, sum, path, all paths)
     *      if right child: findPathRecursive ...
     * 
     */
    std::vector<std::vector<int>> findPaths(TreeNode *root, int sum) {
        std::vector<std::vector<int>> allPaths;
        findPathsRecursive(root, sum, {}, allPaths);
        return allPaths;
    }

    private:
    void findPathsRecursive(TreeNode* node, int sum, std::vector<int> path, std::vector<std::vector<int>>& allPaths){
        bool is_leaf = (node->left == nullptr) && (node->right == nullptr);
        sum -= node->val;
        path.push_back(node->val);

        if (is_leaf){
            if (sum == 0) allPaths.push_back(path);
            return;
        }

        if (node->left != nullptr) findPathsRecursive(node->left, sum, path, allPaths);
        if (node->right != nullptr) findPathsRecursive(node->right, sum, path, allPaths);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    int sum = 23;
    std::vector<std::vector<int>> result = sol.findPaths(root, sum);
    std::cout << "Tree paths with sum " << sum << ": " << std::endl;
    for (auto vec : result) {
        for (auto num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}