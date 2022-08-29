object Solution {
    def removeDuplicates(nums: Array[Int]): Int = {
      val length = nums.length
      if (length <= 1) return length

      var count = 1
      var (l, r) = (0, 0)
      for (i <- (1 until length)) {
        if (nums(i) != nums(i - 1)) {
          nums(count) = nums(i)
          count += 1
        }
      }
      count
    }
}