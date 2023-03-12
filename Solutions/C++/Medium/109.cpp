/*
    * Find the middle node of the list and use it as the root
    * The child nodes are obtained recursively from the left and right side of the list respectively
    * Note: returned TreeNode* was allocated manually using new, assume caller calls delete.
*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            TreeNode* root = new TreeNode(head->val);
            return root; 
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* tmp = head;
        while (tmp->ext != slow) {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        root->left = sortedListToBST(head)
        root->right = sortedListToBST(slow->next)
      }
    }
};
/*
        return root
*/
