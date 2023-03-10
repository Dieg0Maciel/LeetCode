"""
  We store in a hashMap the child node as key and the parent node as value. While looping through the list,
  if we find a node which is already a key in our hashMap, this node must be the beginning of the loop
"""

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        childParentMap = {}
        childParentMap[head] = None
        parent = head
        child = head.next
        while child:
            if child in childParentMap:
                return child
            childParentMap[child] = parent
            parent = child
            child = parent.next
        return None
