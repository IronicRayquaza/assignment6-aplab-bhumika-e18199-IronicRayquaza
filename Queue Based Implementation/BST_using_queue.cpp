#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = nullptr;
    }

    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    void levelOrderTraversal() {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 6);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 8);
    tree.insert(tree.root, 12);
    tree.insert(tree.root, 17);

    cout << "Level Order Traversal: ";
    tree.levelOrderTraversal();

    return 0;
}
