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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // base case
        if (head == NULL)
        {
            return NULL;
        }

        // checking for reversing or not
        ListNode *temp = head;
        int cnt = 0;
        while (temp != NULL && cnt < k)
        {
            temp = temp->next;
            cnt++;
        }

        if (cnt != k)
            return head;

        // reversing in the window of size k
        ListNode *curr = head;
        ListNode *next = NULL;
        ListNode *prev = NULL;
        int count = 0;

        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // recursion call
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};