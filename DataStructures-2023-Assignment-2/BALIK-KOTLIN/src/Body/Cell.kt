package Body

class Cell {
    var data: Int = 0
    var right: Cell? = null
    var left: Cell? = null
    constructor() {}

    constructor(data: Int) {
        this.data = data
    }
}