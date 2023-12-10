/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
//https://leetcode.com/problems/counter-ii
var createCounter = function(init) {
    cnt = init;
    return {
        increment: function(){
            cnt=cnt+1;
            return cnt;
        },
        decrement: function(){
            cnt=cnt-1;
            return cnt;
        }, 
        reset: function(){
            cnt = init;
            return cnt;
        }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */