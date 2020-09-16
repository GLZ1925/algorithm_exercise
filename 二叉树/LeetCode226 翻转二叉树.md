# 翻转二叉树
#1. 题目描述
翻转一棵二叉树。

示例：

    输入：

         4
       /   \
      2     7
     / \   / \
    1   3 6   9
    
    输出：

         4
       /   \
      7     2
     / \   / \
    9   6 3   1

# 2.解题思路
递归调用翻转函数，先翻转左右子树，然后将左右子树交换

# 3.代码
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        // 左子树翻转
        TreeNode* leftTree = invertTree(root->left);
        // 右子树翻转
        TreeNode* rightTree = invertTree(root->right);
        // 交换左右子树
        root->left = rightTree;
        root->right = leftTree;
        return root;
    }
};
```