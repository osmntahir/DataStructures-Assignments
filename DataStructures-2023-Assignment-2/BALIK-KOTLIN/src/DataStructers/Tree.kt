package DataStructers
import Body.Cell
class Tree {
    var root: Cell? = null
    var elementCount = 0
    var counter = -1
    var array = arrayOfNulls<Int>(20)

    fun maxDepth(root: Cell?): Int {
        if (root == null || (root.left == null && root.right == null))
            return 0

        val leftDepth = maxDepth(root.left)
        val rightDepth = maxDepth(root.right)

        return if (leftDepth > rightDepth)
            leftDepth + 1
        else
            rightDepth + 1
    }

    fun minDepth(root: Cell?): Int {
        if (root == null || (root.left == null && root.right == null))
            return 0

        val leftDepth = minDepth(root.left)
        val rightDepth = minDepth(root.right)

        return if (leftDepth < rightDepth)
            leftDepth + 1
        else
            rightDepth + 1
    }

    fun isBalanced(root: Cell?): Boolean {
        return maxDepth(root) - minDepth(root) <= 1
    }

    init {
        root = null
        elementCount = 0
    }

    fun preorder(node: Cell?) {
        if (node != null) {
            preorder(node.left)
            preorder(node.right)
        }
    }

    fun postorder(node: Cell?) {
        if (node != null) {
            postorder(node.left)
            postorder(node.right)
            if (node.data % 2 == 0) {
                counter++
                array[counter] = node.data / 2
            } else {
                counter++
                array[counter] = node.data
            }
        }
    }

    fun insert(toInsert: Cell?) {
        var inserted = false
        var traverse: Cell?
        val newCell = Cell()
        traverse = root
        if (toInsert != null) {
            newCell.data = toInsert.data
            newCell.left = null
            newCell.right = null
        }
        if (root == null) {
            root = newCell
            elementCount++
            return
        }
        while (traverse != null && !inserted) {
            if (newCell.data <= traverse.data) {
                if (traverse.left != null) {
                    traverse = traverse.left
                } else {
                    traverse.left = newCell
                    inserted = true
                }
            } else if (newCell.data > traverse.data) {
                if (traverse.right != null) {
                    traverse = traverse.right
                } else {
                    traverse.right = newCell
                    inserted = true
                }
            } else {
                return
            }
        }
        if (inserted) {
            elementCount++
        }
    }
}
