object Solution {
    val maximum69Number = (num: Int) => { num + num.toString.map(_.asDigit).foldLeft(0)((delta, n) => {if (n == 6 && delta == 0) 3 else delta * 10}) }
}