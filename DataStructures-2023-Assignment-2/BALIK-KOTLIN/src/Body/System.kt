package Body

class System {
    var firstOrgan: Organ? = null
    var next: System? = null
    var organCount = 0
    fun printOrgans() {
        var current = firstOrgan
        while (current != null) {
            println("Organ: ${current.binaryTree?.root?.data}")
            current = current.next
        }
    }

    fun addOrgan(newOrgan: Organ?) {
        if (firstOrgan == null) {
            firstOrgan = newOrgan
            organCount++
            return
        }

        var current = firstOrgan
        while (current!!.next != null) {
            current = current.next
        }
        current.next = newOrgan
        organCount++
    }

}