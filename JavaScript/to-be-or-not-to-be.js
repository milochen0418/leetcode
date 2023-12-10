/**
 * @param {string} val
 * @return {Object}
 */
//https://leetcode.com/problems/to-be-or-not-to-be
var expect = function(val) {
    return {
        toBe : function(beVal){
            if(val === beVal) {
                return true;
            } else {
                throw new Error("Not Equal");
            }
        }, 
        notToBe : function(beVal) {
            if(val !== beVal) {
                return true;
            } else {
                throw new Error("Equal");
            }    
        }
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */