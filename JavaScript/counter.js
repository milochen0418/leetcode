/**
 * @param {number} n
 * @return {Function} counter
 */
//https://leetcode.com/problems/counter/
var createCounter = function(n) {
    counter = n-1;
    return function() {
        counter = counter+1;
        return counter;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */