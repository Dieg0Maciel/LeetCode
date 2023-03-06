class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result: List[List[int]] = []
        if not root:
            return result
        queue: List[Optional[TreeNode]] = []
        queue.append(root)
        while queue:
            qSize: int = len(queue)
            levelNodes: List[int] = []
            while qSize:
                node = queue.pop(0)
                qSize -= 1
                levelNodes.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            result.append(levelNodes)
        return result
