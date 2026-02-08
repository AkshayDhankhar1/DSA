/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int find(TreeNode* node){
    if(node==nullptr) return 0;
    return max(find(node->left)+1,find(node->right)+1);
}
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int l=find(root->left);
        int r=find(root->right);
        if(abs(l-r)>1) return false;
        bool x=true,y=true;
        x=isBalanced(root->left);
        y=isBalanced(root->right);
        if(!x || !y) return false;
        return true;
    }
};