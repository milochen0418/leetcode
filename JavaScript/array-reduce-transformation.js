/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
//https://leetcode.com/problems/array-reduce-transformation
var reduce = function(nums, fn, init) {
    return nums.reduce(fn,init);
};