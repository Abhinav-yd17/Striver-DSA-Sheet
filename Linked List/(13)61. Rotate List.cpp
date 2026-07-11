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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0) return head;

        tail->next = head;

        int steps = len - k;
        ListNode* newLast = head;
        for (int i = 1; i < steps; i++) {
            newLast = newLast->next;
        }

        ListNode* newHead = newLast->next;
        newLast->next = NULL;

        return newHead;
    }
};
