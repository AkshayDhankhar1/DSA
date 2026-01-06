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
void find(TreeNode* temp,vector<int> &ans){
    if(temp==nullptr) return;
    find(temp->left,ans);
    ans.push_back(temp->val);
    find(temp->right,ans);
}
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* temp=root;
        vector<int> ans;
        find(temp,ans);
        return ans;
    }
};