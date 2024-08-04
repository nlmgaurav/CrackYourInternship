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
    ListNode *merge(ListNode *a, ListNode *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        ListNode *res;
        if (a->val <= b->val)
        {
            res = a;
            res->next = merge(a->next, b);
        }
        else
        {
            res = b;
            res->next = merge(a, b->next);
        }
        return res;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0)
            return NULL;
        if (k == 1)
            return lists[0];
        int start = 0, end = k - 1, temp;
        while (end != 0)
        {
            start = 0;
            temp = end;
            while (start < temp)
            {
                lists[start] = merge(lists[start], lists[temp]);
                start++;
                temp--;
            }
            if (start >= temp)
                end = temp;
        }
        return lists[0];
    }
};