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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp1 = head ;
        ListNode *temp2 = head ;
        int cnt = 1 ;
        while(temp2-> next) {
            if (cnt > n) {
                temp1 = temp1-> next ;
            }
            cnt++ ;
            temp2 = temp2-> next ;
        }
        if (cnt == n) {
            head = head-> next ;
            return head ;
        }
        temp1-> next = temp1-> next-> next ;
        return head ;
    }
};