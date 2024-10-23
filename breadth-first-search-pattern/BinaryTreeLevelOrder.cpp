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
     * Binary Tree Level Order Traversal (easy)
     * 
     * Given a binary tree, populate an array to represent its level-by-level traversal. 
     * You should populate the values of all nodes of each level from left to right in separate sub-arrays.
     * 
     * Example:
     *      1
     *     / \
     *    3   5         => [[1], [3, 5]]
     * 
     * Logic:
     *      Start with a breadth first traversal
     *      let queue 'nodes' be a queue of treeNodes
     *      let queue 'levels' be a queue of ints
     *      
     *      add root to nodes
     *      add '0' to levels
     *      while(queue not empty)
     *          currNode = nodes pop
     *          currLevel = levels pop
     *      
     *          results.at(currLevel).push_back(currNode.Value)
     * 
     *          nodes push currNode left and right
     *          levels puch currlevel+1 and currlevel+1
     *          
     */
    std::vector<std::vector<int>> traverse(TreeNode *root) {
        std::vector<std::vector<int>> result;
        
        std::queue<TreeNode*> nodesQueue {};
        std::queue<int> levelsQueue {};

        nodesQueue.push(root);
        levelsQueue.push(0);

        int seenLevel = -1;

        while(!nodesQueue.empty()){
            TreeNode* currNode = nodesQueue.front();
            int currLevel = levelsQueue.front();

            // add the current nodes value to the correct list
            if (currLevel == seenLevel + 1) {
                result.push_back({currNode->val});
                seenLevel++;
            } else{
                result.at(currLevel).push_back(currNode->val);
            }
            // add the left and right child to the queue
            if (currNode->left != nullptr) {
                nodesQueue.push(currNode->left);
                levelsQueue.push(currLevel+1);
            }

            if (currNode->right != nullptr) {
                nodesQueue.push(currNode->right);
                levelsQueue.push(currLevel+1);
            }

            nodesQueue.pop();
            levelsQueue.pop();
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
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    std::vector<std::vector<int>> result = sol.traverse(root);
    std::cout << "Level order traversal: ";
    for (auto vec : result) {
        for (auto num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}