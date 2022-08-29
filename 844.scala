object Solution {
    def backspaceCompare(s: String, t: String): Boolean = {
        val compressStr = (x: String) => x.foldLeft("") { (res, c) => if (c == '#') res.dropRight(1) else res + c }
        compressStr(s) == compressStr(t)
    }
}