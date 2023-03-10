/*
  We store in a hashMap the child node as key and the parent node as value. While looping through the list,
  if we find a node which is already a key in our hashMap, this node must be the beginning of the loop
*/

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        std::map<ListNode*, ListNode*> childParentMap;
        ListNode* childParentMap[head] = nullptr;
        ListNode* parent = head;
        ListNode* child = head->next;
        while (child) {
            if (childParentMap.find(child) != childParentMap.end()) {
                return child;
            }
            childParentMap[child] = parent;
            parent = child;
            child = parent->next;
        }
        return nullptr;
    }
};
