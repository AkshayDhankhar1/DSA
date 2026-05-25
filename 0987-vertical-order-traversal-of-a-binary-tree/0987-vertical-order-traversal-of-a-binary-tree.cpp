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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr) return{};
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> mp;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node=it.first;
            int x= it.second.first;
            int y=it.second.second;
            mp[x][y].insert(node->val);
            if(node->left!=nullptr){
                q.push({node->left,{x-1,y+1}});
            } 
            if(node->right!=nullptr){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto it : mp){
            vector<int> res;
            for(auto that : it.second){
                res.insert(res.end(),that.second.begin(),that.second.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};