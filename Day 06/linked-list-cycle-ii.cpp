//https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>st;
        ListNode* curr = head;
        while(curr != NULL){
            st.insert(curr);
            curr = curr->next;
            if(st.find(curr) != st.end()) return curr;
        }

        return NULL;
    }
};
