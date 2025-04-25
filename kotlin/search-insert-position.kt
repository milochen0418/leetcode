class Solution {
    fun searchInsert(nums: IntArray, target: Int): Int {
        var L:Int = 0
        var R:Int = nums.size - 1
        while(L<=R) {            
            val M:Int = (L+R)/2
            if(nums[L]>target) return L
            if(nums[R]<target) return R+1
            if(nums[M] == target) return M
            if(nums[M] > target) 
                R = M-1
            else 
                L = M+1
        } 
        return -1
    }
}