class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val n = nums.size
        for(i in 0 until n) 
            for(j in i+1 until n)
                if(nums[i] + nums[j] == target)
                    return intArrayOf(i,j)
        throw IllegalArgumentException("no two-sum solution")
    }
}