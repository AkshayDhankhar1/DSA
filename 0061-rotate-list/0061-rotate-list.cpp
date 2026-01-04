/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        if(head==nullptr) return head;
        vector<ListNode*> stor;
        while(temp){
            stor.push_back(temp);
            temp=temp->next;
        }
        int n= stor.size();
        if(k==n) return head;
        if(k>n){
            k=k%n;
        }
        reverse(stor.begin(),stor.begin()+n-k);
        reverse(stor.begin()+n-k,stor.end());
        reverse(stor.begin(),stor.end());
        for(int i=0;i<n;i++){
            if(i==n-1){
                stor[i]->next=nullptr;
            }
            else{
                stor[i]->next=stor[i+1];
            }
        }
        return stor[0];
        
        
    }
};