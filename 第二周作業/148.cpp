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
    ListNode* sortList(ListNode* head) {
        if ( head==nullptr || head->next==nullptr)return head;
        ListNode* mid=findmid(head);
        ListNode* lefthalf=head;
        ListNode* righthalf=mid->next;
        mid->next=nullptr; // 斷開連結，形成兩個獨立串列
        //遞迴排序 (Divide)
        ListNode* leftsort=sortList(lefthalf);
        ListNode* rightsort=sortList(righthalf);
        //合併
        return merge(leftsort,rightsort);
    }
private:
    ListNode* findmid(ListNode* head)
    {
        //找中點，用快慢指標法
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow=slow->next; //走一步
            fast=fast->next->next; //走兩步
        }
        return slow;
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode dummy(0); //虛擬頭節點，方便操作，當新隊伍的起點，之後放排序好的
        ListNode* tail=&dummy; //永遠指向新隊伍的最後一個節點
        while (l1 && l2) {
        if (l1->val < l2->val) //比較小的接在tail的next
        {
            tail->next = l1;
            l1 = l1->next; //l1往後一步
        } else 
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next; //往後移到新隊伍的末端
    }
    tail->next = l1 ? l1 : l2; // 把剩下的接上去，如果l1不是空的，那將l1assign給tail->next
    return dummy.next;
    }
};