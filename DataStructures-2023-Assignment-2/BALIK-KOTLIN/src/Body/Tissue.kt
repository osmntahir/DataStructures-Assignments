package Body

class Tissue {
    private var first: Cell? = null
    private var cellCount: Int = 0
    constructor() {
        first = null
        cellCount = 0
    }

    fun printCells() {
        var current: Cell? = first

        while (current != null) {
            print("${current.data}  ")
            current = current.right
        }
    }

    fun addCell(cell: Cell?) {
        if (first == null) {
            first = cell
            cellCount++
            return
        }

        var current: Cell? = first
        while (current?.right != null) {
            current = current.right
        }
        current?.right = cell
        cellCount++
    }

    fun getMiddleCell(): Cell? {
        val position = cellCount / 2
        var index = 0
        var current: Cell? = first

        while (index < position) {
            current = current?.right
            index++
        }
        return current
    }
}