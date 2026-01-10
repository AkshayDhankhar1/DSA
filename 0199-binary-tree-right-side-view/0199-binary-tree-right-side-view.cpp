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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(root==nullptr) return{};
        map<int,int> mpp;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.second;
            TreeNode* node=p.first;
            if(mpp.count(x)==0){mpp[x]=node->val;}
            if(node->right!=nullptr){
                q.push({node->right,x+1});
            }
            if(node->left!=nullptr){
                q.push({node->left,x+1});
            }
        }
        vector<int> ans;
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};