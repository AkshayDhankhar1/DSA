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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        if(temp1==nullptr){
            return temp2;
        }
        if(temp2==nullptr) return temp1;
        int sum=0;
        int carry=0;
        sum=temp1->val+temp2->val+carry;
            if(sum>9){
                carry=1;
                sum-=10;
            }
            else carry=0;
            ListNode* head=new ListNode(sum);
            ListNode* t1=head;
            if( carry==1&&temp1->next==nullptr && temp2->next==nullptr ){
                t1->next=new ListNode (1);
                // return head;
            }
        sum=0;
        temp1=temp1->next;
        temp2=temp2->next;
        while(temp1 && temp2){
            sum=temp1->val+temp2->val+carry;
            if(sum>9){
                carry=1;
                sum-=10;
            }else carry=0;
            ListNode* newnode=new ListNode(sum);
            if( carry==1&&temp1->next==nullptr && temp2->next==nullptr ){
                newnode->next=new ListNode (1);
                // return head;
            }
            t1->next=newnode;
            t1=t1->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            sum=temp1->val+carry;
            if(sum>9){
                carry=1;
                sum-=10;
            }else carry=0;
            ListNode* newnode=new ListNode(sum);
            if( carry==1&&temp1->next==nullptr){
                newnode->next=new ListNode (1);
                // return head;
            }
            t1->next=newnode;
            t1=t1->next;
            temp1=temp1->next;
        }
        while(temp2){
            sum=temp2->val+carry;
            if(sum>9){
                carry=1;
                sum-=10;
            }else carry=0;
            ListNode* newnode=new ListNode(sum);
            if( carry==1&&temp2->next==nullptr){
                newnode->next=new ListNode (1);
                // return head;
            }
            t1->next=newnode;
            t1=t1->next;
            temp2=temp2->next;
        }
        return head;
    }
};