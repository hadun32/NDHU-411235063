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
        if (!head || !head->next)
            return head;

        ListNode* mid = getmid(head);
        ListNode* L = head;
        ListNode* R = mid->next;
        mid->next = nullptr;

        L = sortList(L);
        R = sortList(R);

        return merge(L, R);
    }

private:
    ListNode* getmid(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next; // 快慢找中點，讓偶數也可以對切

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // 回傳中點
    }
    ListNode* merge(ListNode* L, ListNode* R) {
        if (L == nullptr)
            return R;
        if (R == nullptr)
            return L; // 如果左邊或右邊沒有，不需要比大小，直接把剩下還有的回傳就好
        if (L->val < R->val) {
            L->next = merge(L->next, R);
            return L;
        } else {
            R->next = merge(L, R->next);
            return R;
        }
    }
};