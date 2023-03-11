"""
    * Find the middle node of the list and use it as the root
    * The child nodes are obtained recursively from the left and right side of the list respectively
"""

class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        if head is None:
            return None
        if head.next is None:
            return TreeNode(head.val)
        slow: Optional[ListNode] = head
        fast: Optional[ListNode] = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        tmp: Optional[ListNode] = head
        while tmp.next != slow:
            tmp = tmp.next
        tmp.next = None
        root: TreeNode = TreeNode(slow.val)
        root.left = self.sortedListToBST(head)
        root.right = self.sortedListToBST(slow.next)
        return root
