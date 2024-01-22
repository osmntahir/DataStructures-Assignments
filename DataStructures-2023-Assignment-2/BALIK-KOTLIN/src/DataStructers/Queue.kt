package DataStructers

class Queue {
    private var first: Node? = null
    private var last: Node? = null
    private var elementCount = 0
    fun add(data: Int) {
        if (first == null) {
            first = Node(data)
            last = first
        } else {
            val newNode = Node(data)
            last?.next = newNode
            last = newNode
        }
        elementCount++
    }

    fun remove() {
        if (first != null) {
            val temp = first?.next
            first = null
            first = temp
            if (first == null) {
                last = null
            }
            elementCount--
        }
    }

    fun isEmpty(): Boolean {
        return first == null
    }

    fun getFront(): Int {
        if (first != null) {
            return first?.data ?: throw RuntimeException("Queue is empty")
        }
        throw RuntimeException("Queue is empty")
    }

    fun getElementCount(): Int {
        return elementCount
    }

    override fun toString(): String {
        val sb = StringBuilder()
        if (first == null) {
            sb.append("----QUEUE IS EMPTY----")
        } else {
            var temp = first
            while (temp != null) {
                sb.append(String.format("%5d", temp.data))
                temp = temp.next
            }
        }
        sb.append(System.lineSeparator())
        return sb.toString()
    }
}