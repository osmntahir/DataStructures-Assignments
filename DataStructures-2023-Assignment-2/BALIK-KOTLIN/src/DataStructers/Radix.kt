package DataStructers

import java.util.Arrays

class Radix(numbers: IntArray) {
    private var numbers: IntArray
    private val queues: Array<Queue?>
    private val numberCount: Int
    init {
        numberCount = numbers.size
        this.numbers = IntArray(numberCount)
        for (i in 0 until numberCount) {
            this.numbers[i] = numbers[i]
        }
        queues = arrayOfNulls(10)
        for (i in 0 until 10) {
            queues[i] = Queue()
        }
    }

    fun sort(): IntArray {
        for (i in 0 until numberCount) {
            val lastDigit = numbers[i] % 10
            queues[lastDigit]?.add(numbers[i])
        }
        val maxDigitCount = getMaxDigitCount()
        var placeValue = 10
        for (i in 1 until maxDigitCount) {
            val lengths = getQueueLengths()
            for (j in 0 until 10) {
                var count = lengths[j]
                while (count != 0) {
                    val nextNumber = queues[j]?.getFront()
                    queues[j]?.remove()
                    val digit = (nextNumber!! / placeValue) % 10
                    queues[digit]?.add(nextNumber)
                    count--
                }
            }
            placeValue *= 10
        }
        var arrayIndex = 0
        for (i in 0 until 10) {
            while (!queues[i]?.isEmpty()!!) {
                numbers[arrayIndex] = queues[i]?.getFront()!!
                queues[i]?.remove()
                arrayIndex++
            }
        }
        return numbers
    }

    private fun getMaxDigitCount(): Int {
        var maxDigitCount = getDigitCount(numbers[0])
        for (i in 1 until numberCount) {
            val nextDigitCount = getDigitCount(numbers[i])
            if (maxDigitCount < nextDigitCount) {
                maxDigitCount = nextDigitCount
            }
        }
        return maxDigitCount
    }

    private fun getDigitCount(number: Int): Int {
        var digitCount = 0
        var tempNumber = number
        while (tempNumber != 0) {
            tempNumber /= 10
            digitCount++
        }
        return digitCount
    }

    private fun getQueueLengths(): IntArray {
        val lengths = IntArray(10)
        for (i in 0 until 10) {
            lengths[i] = queues[i]?.getElementCount()!!
        }
        return lengths
    }
}