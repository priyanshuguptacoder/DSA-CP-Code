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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL){
            return {-1, -1};
        }

        int prevVal = head -> val;
        head = head -> next;

        vector<int> pos;
        int cnt = 2;

        while(head -> next != NULL){
            if((head -> val > prevVal && head -> val > head -> next -> val) || (head -> val < prevVal && head -> val < head -> next -> val)){
                pos.push_back(cnt);
            }

            prevVal = head -> val;
            head = head -> next;
            cnt++;
        }

        if(pos.size() <= 1){
            return {-1, -1};
        }

        if(pos.size() == 2){
            return {pos[1] - pos[0], pos[1] - pos[0]};
        }

        int mini = INT_MAX, maxi = pos[pos.size() - 1] - pos[0];
        for(int i=1; i<pos.size(); i++){
            mini = min(mini, pos[i] - pos[i-1]);
        }
        
        return {mini, maxi};
    }
};