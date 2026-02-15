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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> temp;
        if(lists.size()==0) return nullptr;
        for(int i=0;i<lists.size();i++){
            if(lists[i]==nullptr) continue;
            ListNode* head=lists[i];
            while(head){
                temp.push_back(head);
                head=head->next;
            }
        }
        if (temp.empty()) return nullptr;
        sort(temp.begin(),temp.end(),[](const ListNode* a, const ListNode* b){
            return a->val < b->val;
        });
        for(int i=0;i<temp.size()-1;i++){
            temp[i]->next=temp[i+1];
        }
        temp.back()->next = nullptr;
        return temp[0];
    }
};