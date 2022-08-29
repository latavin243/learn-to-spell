object Solution {
    val removeElement = (nums: Array[Int], v: Int) => nums.foldLeft(0)((ptr, x) => if (x == v) ptr else { nums(ptr) = x; ptr + 1 })
}