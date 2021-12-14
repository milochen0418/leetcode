// Challenge is here https://hackmd.io/@milochen0418/leetcode-277-find-the-celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    //knows(a,b) == true => a is not celebrity, b could be celebrity
    //knows(a,b) == false => a could be celebrity, b is not celebrity
    //So whetever you call knows(), then you can know who is not celebrity 
    int findCelebrity(int n) {
        int candidate = 0;
        for(int i = 1; i < n; i++) { 
            if(knows(candidate, i)) {
                candidate = i;
            }   
        }
        //right now, another i that compared with candidate is not celebrity.
        
        //Final checking of candidate
        for(int i = 0; i < n; i++) {
            if(i == candidate) continue;//avoid checking myself
            if(knows(candidate,i) == true) {
                return -1;
            }
            if(knows(i, candidate) == false) {
                return -1;
            }
        }
        return candidate;
    }
};