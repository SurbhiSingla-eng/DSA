//floyds tortoise and hare algo
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
        if (!head || !head -> next){
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;
        while (fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast){
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle){
            return nullptr;
        }
        slow = head;
        while (slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }

};

// just return pointers 
