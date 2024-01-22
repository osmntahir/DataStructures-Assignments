package Test

import java.util.*
import java.util.Scanner


fun main() {
    val control = Control()

    control.readDataFromFile()
    println("                 ORGANISM ")
    control.printOrganism()


    while (true) {
        println("Press ENTER key...")
        val scanner = Scanner(System.`in`)
        val input = scanner.nextLine()
        if (input.isBlank()) {
            // Mutation operations
            println("                 ORGANISM (UNDERWENT MUTATION) ")
            control.performMutation()

            control.printOrganism()
            break
        } else {
            println("You didn't press the ENTER key! Please press the ENTER key.")
        }
    }

    println("Program ended.")
}
