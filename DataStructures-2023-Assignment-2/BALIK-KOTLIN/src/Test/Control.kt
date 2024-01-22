package Test

import Body.Organ
import Body.Organism
import Body.System
import Body.Cell
import Body.Tissue
import java.io.File

import DataStructers.Radix

class Control {
    private val organism: Organism = Organism()
    fun readDataFromFile() {

        val filePath = "doc/data.txt"
        val file = File(filePath)

        try {

        } catch (e: Exception) {
            println("An error occurred while reading the file: ${e.message}")
        }

        val lines = file.readLines()

        var index = 0
        var system: System? = System()
        var organ: Organ? = Organ()

        for (line in lines) {
            val numbers = line.split(" ").map { it.toInt() }.toIntArray()
            val radix = Radix(numbers)
            val sortedNumbers = radix.sort()

            val tissue = Tissue()
            for (num in sortedNumbers) {
                val cell = Cell(num)
                tissue.addCell(cell)
            }

            organ?.binaryTree?.insert(tissue.getMiddleCell())

            index++

            if (index % 2000 == 0) {
                organism.addSystem(system)
                system = System()
            }

            if (index % 20 == 0) {
                system?.addOrgan(organ)
                organ = Organ()
            }
        }
    }

    fun performMutation() {
        var currentSystem: System? = organism.firstSystem
        while (currentSystem != null) {
            var currentOrgan: Organ? = currentSystem.firstOrgan
            while (currentOrgan != null) {
                if (currentOrgan.binaryTree?.root?.data?.rem(50) == 0) {
                    // Mutation operation

                    currentOrgan.binaryTree?.postorder(currentOrgan.binaryTree?.root)

                    currentOrgan.binaryTree?.root = null
                    for (i in 0 until (currentOrgan.binaryTree?.counter ?: 0)) {
                        val cell = Cell()
                        cell.data = currentOrgan.binaryTree?.array?.get(i) ?: 0
                        currentOrgan.binaryTree?.insert(cell)
                    }
                    currentOrgan = currentOrgan.next
                } else {
                    currentOrgan = currentOrgan.next
                }
            }
            currentSystem = currentSystem.next
        }
    }

    fun printOrganism() {
        var currentSystem = organism.firstSystem
        while (currentSystem != null) {
            var currentOrgan = currentSystem.firstOrgan
            while (currentOrgan != null) {
                if (currentOrgan.binaryTree?.isBalanced(currentOrgan.binaryTree?.root) == true) {
                    print(" ")
                } else {
                    print("#")
                }
                currentOrgan = currentOrgan.next
            }
            println()
            currentSystem = currentSystem.next
        }
    }
}