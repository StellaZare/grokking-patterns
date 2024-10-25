#include <queue>
#include <iostream>

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
    public:
    /**
     * Connect Level Order Siblings (medium)
     * 
     * Given a binary tree, connect each node with its level order successor. 
     * The last node of each level should point to a null node.
     * 
     * Logic:
     *  put the root in the queue
     *  while queue not empty 
     *      get the size of the level
     *      for n in level:
     *          curr_node = queue.front();
     *          queue.pop();
     *          if (n < level-1) curr_node.next() = new top
     *          else leave as null
     *          if not nullptr push children
     * 
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     */
    TreeNode* connect(TreeNode* root) {
        std::queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int level_size = nodes.size();
            for(int n = 0; n < level_size; n++){
                TreeNode* curr_node = nodes.front();
                nodes.pop();

                if (n < level_size - 1) {
                    curr_node->next = nodes.front();
                } else {
                    curr_node->next = nullptr;
                }

                if (curr_node->left != nullptr) nodes.push(curr_node->left);
                if (curr_node->right != nullptr) nodes.push(curr_node->right);
            }
        }
        return root;
    }
};

// level order traversal using 'next' pointer
static void printLevelOrder(TreeNode *root) {
    TreeNode *nextLevelRoot = root;
    while (nextLevelRoot != nullptr) {
        TreeNode *current = nextLevelRoot;
        nextLevelRoot = nullptr;
        while (current != nullptr) {
            std::cout << current->val << " ";
            if (nextLevelRoot == nullptr) {
                if (current->left != nullptr) {
                    nextLevelRoot = current->left;
                } else if (current->right != nullptr) {
                    nextLevelRoot = current->right;
                }
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    root = sol.connect(root);
    std::cout << "Level order traversal using 'next' pointer: " << std::endl;
    printLevelOrder(root);
}