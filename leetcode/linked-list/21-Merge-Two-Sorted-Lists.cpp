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
private:
    ListNode* merge2SortedList(ListNode* l1, ListNode* l2){
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }

        if(l1 -> val <= l2 -> val){
            l1 -> next = merge2SortedList(l1 -> next, l2);
            return l1;
        }

        else{
            l2 -> next = merge2SortedList(l1, l2 -> next);
            return l2;
        }

        return NULL;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge2SortedList(list1, list2);
    }
};