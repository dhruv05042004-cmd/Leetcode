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
    int pairSum(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *prev=nullptr;
        while(slow!=nullptr)
        {
            ListNode *front=slow->next;
            slow->next=prev;
            prev=slow;
            slow=front;
        }

        ListNode *head1=head;
        ListNode *head2=prev;
        int maxi=INT_MIN;
        while(head2!=nullptr)
        {
            int sum=head1->val+head2->val;
            head1=head1->next;
            head2=head2->next;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};