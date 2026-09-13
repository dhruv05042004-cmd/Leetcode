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
        ListNode *a=l1;
        ListNode *b=l2;
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;

        int sum=0;
        int carry=0;
        while(a!=nullptr || b!=nullptr || carry!=0)
        {
            sum=carry;
            if(a!=nullptr) 
            {
                sum+=a->val;
                a=a->next;
            }
            if(b!=nullptr)
            {
                sum+=b->val;
                b=b->next;
            }
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            carry=sum/10;
        }
        return dummy->next;
        
    }
};