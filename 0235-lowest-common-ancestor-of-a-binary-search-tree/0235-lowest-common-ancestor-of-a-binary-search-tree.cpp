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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return root;
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> que;
        que.push(root);
        parent[root]=nullptr;
        while(!que.empty()){
            TreeNode* node=que.front();
            que.pop();
            if(node->left!=nullptr){
                parent[node->left]=node;
                que.push(node->left);
            }
            if(node->right!=nullptr){
                parent[node->right]=node;
                que.push(node->right);
            }
        }
        unordered_set<TreeNode*> parent1;
        while(p){
            parent1.insert(p);
            p=parent[p];
        }
        while(q){
            if(parent1.find(q) !=parent1.end()){
                return q;
            }
            q=parent[q];
        }
        return nullptr;
    }
};