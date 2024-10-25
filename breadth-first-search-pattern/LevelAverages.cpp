#include <iostream>
#include <queue>

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
     * Level Averages in a Binary Tree (easy)
     * 
     * Given a binary tree, populate an array to represent the averages of all of its levels.
     * 
     * Logic:
     *  start by pushing the root node
     *  for each level in the tree (until queue is empty):
     *      level size = queue.size()
     *      for i = 0 < level size:
     *          pop, process, push children if they exist
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     */
    std::vector<double> findLevelAverages(TreeNode *root) {
        std::vector<double> result;
        std::queue<TreeNode*> nodes;

        nodes.push(root);
        
        while(!nodes.empty()) {
            int level_size = nodes.size();
            double level_sum = 0;

            for (int n = 0; n < level_size; n++){
                // add current node to level sum
                level_sum += nodes.front()->val;
                // add children
                if (nodes.front()->left != nullptr) nodes.push(nodes.front()->left);
                if (nodes.front()->right != nullptr) nodes.push(nodes.front()->right);

                // remove the processes node
                nodes.pop();
            }
            result.push_back(level_sum/level_size);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    std::vector<double> result = sol.findLevelAverages(root);
    std::cout << "Level averages are: ";
    for (auto num : result) {
        std::cout << num << " ";
    }
}