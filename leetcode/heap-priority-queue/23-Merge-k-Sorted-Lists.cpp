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

    ListNode* partitionAndMerge(int st, int end, vector<ListNode*>& lists){
        if(st > end){
            return NULL;
        }
        if(st == end){
            return lists[st];
        }

        int mid = st + (end - st) / 2;
        ListNode* l1 = partitionAndMerge(st, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, end, lists);

        return merge2SortedList(l1, l2);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0){
            return NULL;
        }

        return partitionAndMerge(0, n-1, lists);
    }
};