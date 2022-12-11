/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
    //https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
public:
    int search(const ArrayReader& reader, int target) {
        int L=0, R = 1e4-1;
        
        long long out_of_bound_ll= pow(2,31)-1;
        int out_of_bound = (int)out_of_bound_ll;
        
        while(L<=R) {
            
            int M = L + (R-L)/2;
            printf("L,M,R = %d, %d, %d\n", L,M,R);
            int v = reader.get(M); 
            if(v == target) return M;
            
            if(v < target) {
                L= M + 1;
            } else {
                R= M - 1;
            } 
        } 
        return -1;
    }
};