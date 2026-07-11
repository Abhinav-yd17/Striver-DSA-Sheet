#include<bits/stdc++.h>
using namespace std;    
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        fast = head->next->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};