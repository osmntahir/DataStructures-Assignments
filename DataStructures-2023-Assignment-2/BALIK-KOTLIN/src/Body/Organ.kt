package Body
import DataStructers.Tree

class Organ {
    var binaryTree: Tree? = Tree()
    var next: Organ? = null
    constructor() {
        binaryTree = Tree()
        next = null
    }
}