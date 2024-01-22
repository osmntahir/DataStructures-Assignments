package Body

class Organism {
    var firstSystem: System? = System()
    constructor() {
        firstSystem = null
    }

    fun addSystem(newSystem: System?) {
        if (firstSystem == null) {
            firstSystem = newSystem
            return
        }

        var current: System? = firstSystem
        while (current?.next != null) {
            current = current.next
        }
        current?.next = newSystem
    }

    override fun toString(): String {
        return "Organism(firstSystem=$firstSystem)"
    }
}