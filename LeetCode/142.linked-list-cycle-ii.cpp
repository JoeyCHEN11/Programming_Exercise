#ifndef struct ListNode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
#endif
/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (50.54%)
 * Likes:    13097
 * Dislikes: 912
 * Total Accepted:    1.2M
 * Total Submissions: 2.4M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given the head of a linked list, return the node where the cycle begins. If
 * there is no cycle, return null.
 * 
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is
 * connected to (0-indexed). It is -1 if there is no cycle. Note that pos is
 * not passed as a parameter.
 * 
 * Do not modify the linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of the nodes in the list is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * pos is -1 or a valid index in the linked-list.
 * 
 * 
 * 
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
/*         unordered_set<ListNode*> check;

        ListNode* p = head;
        while (p!=nullptr && !(check.find(p)!=check.end())){
            check.insert(p);
            p = p->next;
        }
        
        return p; */
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr ){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }
        
        if(fast == nullptr || fast->next == nullptr) return nullptr;

        slow = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
// @lc code=end

