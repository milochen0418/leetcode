class Solution {
    //https://leetcode.com/problems/can-place-flowers
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //0 0
        //00 0
        //000 1
        //0000 1
        //00000 2
        //000000 2
        //0000000 3
        /*
        8,7 -> 3
        6,5 -> 2
        4,3 -> 1
        2,1 -> 0
        When there are z zero, then (z-1) / 2 is the number it can contribute
        */
        int z_cnt = 1;
        int i = 0; 
        int planted_cnt = 0; 
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] != 0 || i + 1 >= flowerbed.size() ) {
                if(flowerbed[i]  == 0 && i + 1 >= flowerbed.size() ) {
                    z_cnt+=2;
                }
                if(z_cnt != 0) {
                    planted_cnt += (z_cnt-1) / 2; 
                    z_cnt = 0;   
                }               
            } else {
                z_cnt++;  
            }
        }
        if(n > planted_cnt) {
            return false;
        } else {
            return true;
        }
    }
};