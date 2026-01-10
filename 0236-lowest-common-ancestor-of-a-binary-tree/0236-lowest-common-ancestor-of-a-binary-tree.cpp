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
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> que;
        if(root==nullptr) return root;
        parent[root]=nullptr;
        que.push(root);
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
        unordered_set<TreeNode*> st;
        while(p!=nullptr){
            st.insert(p);
            p=parent[p];
        }
        while(q!=nullptr){
            if(st.count(q)){
                return q;

            }
            q=parent[q];
        }
        return nullptr;
    }
};