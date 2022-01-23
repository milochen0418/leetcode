class Solution {
    //https://leetcode.com/problems/sequential-digits/
public:
    vector<int> sequentialDigits(int low, int high) {
        //return step1(low,high);
        //Two case for fit overflow issue
        //10
        //1000000000
        //372591426
        //841554424
        
        vector<int> v;        
        int temp_val = low;
        while(true) {
            int maxd = 1; 
            int inc = 1;
            int base = 1;
            int i=2;
            while((temp_val/10)/(maxd)>0) {
                maxd*=10;
                inc=(inc*10)+1;
                base = base*10+i;
                i++;
                if(i>10) return v; ////it's enough to return answer v when i>10
                
            }
            
            for (int i = 0; i<(10-base%10); i++) {
                int val = inc*i+base;
                if(low<=val && val<=high) {
                    v.push_back(val);    
                }
            }
            
            
            if(temp_val/high>0) break;
            if(temp_val > INT_MAX/10) return v; //it's enough to return answer when temp_val*10 can cause overflow
            temp_val*=10;
        }
        return v;
    }
    
    vector<int> step1(int low, int high) {
        vector<int> v;
        int temp_val = 100000000;
        int maxd = 1; 
        int inc = 1;
        int base = 1;
        int i=2;
        while((temp_val/10)/(maxd)>0) {            
            maxd*=10;
            inc=(inc*10)+1;
            base = base*10+i;
            i++;
        }
        v.push_back(maxd);
        v.push_back(inc);
        v.push_back(base);
        v.push_back(-1);
        for (int i = 0; i<(10-base%10); i++) {
            v.push_back(inc*i+base);
        }
        return v;
    }
};