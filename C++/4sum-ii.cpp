class Solution {
    //https://leetcode.com/problems/4sum-ii
    //article https://leetcode.com/problems/4sum-ii/discuss/1742279/C%2B%2B-or-O(N2)-time-and-space-or-unordered_map
    //FB post https://www.facebook.com/groups/1451299754892511/posts/5035031756519275/
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), cnt = 0;        
        unordered_map<int,int> mp1, mp2;
        for(int i=0;i<n;i++) { 
            for(int j=0;j<n;j++) {
                mp1[nums1[i] + nums2[j]]+=1;
                mp2[nums3[i] + nums4[j]]+=1;
            }
        }      
        for(auto [key,val]: mp1) cnt += val * mp2[-1*key];
        return cnt;
    }
};


/*
[-30,-4,-4,-24,-31,9,-8,8,-30,-5,-17,5,-13,-2,-18,-25,7,-12,2,-21,-28,-20,2,-5,-18,-14,-10,-15,-11,-28,7,8,-23,-31,-7,-11,5,4,-24,-25,-4,-32,-23,-19,0,-31,-4,5,-7,7,7,2,10,-32,5,-7,-31,9,-21,-6,2,-9,7,7,-14,-4,-14,-15,-24,-26,5,-30,8,-31,-18,-16,-31,0,-10,-15,-14,-24,7,2,-27,-25,-3,3,-30,9,2,-19,-5,-22,-23,-31,-18,1,-16,0]
[-22,4,2,-18,-20,-23,4,6,-1,-10,-25,-19,-3,6,-21,2,-4,-11,6,-2,9,-18,-3,-7,-11,-12,-5,-18,0,5,9,-8,1,-12,-28,-1,5,-27,-16,-2,-19,8,-14,-24,-27,6,-21,8,-14,-8,-5,-25,0,-30,-24,-15,-11,-21,-11,-7,-22,-8,-7,-3,-26,-8,-4,-17,-22,-9,-14,-16,9,-32,-24,-9,9,-10,-21,-8,-4,-23,6,7,-9,-28,-26,-18,-12,0,-2,-24,3,-10,-11,-18,-3,-29,-17,-7]
[7,-31,1,-19,-28,-30,-10,-18,-4,-10,-1,-28,-6,-21,5,8,8,-20,-13,-14,-28,-32,4,-26,-7,-31,2,-5,-32,-2,-3,3,7,-4,8,9,5,1,-22,-30,-27,-8,-14,0,-9,-2,10,-3,-20,-7,4,5,5,-16,-1,10,-16,-9,-19,6,-13,-19,-27,-5,-8,9,-2,-26,-29,3,-25,-28,-23,-6,-8,-14,-20,-30,5,-32,-24,-2,-15,-26,-26,2,-17,-10,-26,4,-6,-31,-20,-8,-24,-28,-26,-12,2,0]
[8,-19,9,-12,-1,-11,-17,6,-23,6,3,-29,-17,9,-1,1,-2,6,7,-28,6,-28,-24,-4,-21,-8,-8,-14,-19,-10,8,-12,5,-5,9,-13,-19,-8,-1,-5,-4,-29,0,-10,5,-11,-6,-2,1,-11,7,-3,-1,5,-18,-24,-22,-20,6,-28,-5,-4,6,-7,-1,-6,9,-28,-13,-16,-2,-29,-19,2,-21,-20,-1,-3,-24,-15,2,-2,6,-15,-19,9,6,-2,2,-26,0,-26,-14,-27,-20,-29,-31,-23,6,0]
*/

/*
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
*/

/*
[-35,-6,88,58,-68,-10,86,30,-74,37,92,35,24,13,-54,26,24,-59,29,80,-25,55,-39,18,-7,42,-55,40,45,-90,-21,46,-60,23,-1,58,52,-81,-4,-61,-48,20,-51,-63,98,-22,-47,60,-62,-4,-78,91,33,-82,19,54,-2,-80,15,61,70,-42,96,95,-86,-26,-62,32,77,83,85,-92,100,-2,-55,0,-53,53,5,29,-63,-97,-94,15,41,-3,-94,6,-95,36,50,-19,-72,-11,-83,-68,61,-64,6,12,48,-79,83,100,19,2,-90,-17,9,-77,22,1,-15,62,-44,36,81,-61,-75,4,-32,-59,56,21,24,-24,-99,-78,-62,58,-61,84,54,25,-2,25,62,-3,3,-23,5,89,93,-30,36,-34,-65,84,-34,-57,37,11,2,49,48,-89,53,-74,-35,-70,44,15,53,-99,78,-94]
[31,-58,-16,-96,-77,-82,-19,16,19,-68,-52,61,-72,-99,-10,-89,29,20,-100,58,-48,-28,57,51,-34,53,28,56,-54,-15,75,24,81,13,39,52,-70,-9,61,-49,92,63,-75,17,-53,-50,-5,91,30,9,60,-99,30,-26,81,-84,-7,47,-66,42,84,66,0,-97,-17,0,3,31,-85,-29,23,18,52,46,5,-90,28,-11,12,-13,85,18,59,44,-53,8,16,-75,-73,17,25,-19,18,-21,25,35,56,13,77,-18,15,-88,-22,-19,58,-72,79,79,65,-46,-69,4,46,23,-30,53,100,-65,-83,18,64,1,97,87,42,27,-26,54,-56,7,-14,-25,-7,82,13,71,-87,-95,-27,-12,56,-99,-43,94,-6,17,-64,83,96,-24,-67,-66,24,-39,43,-100,89,42,-78,-90,-79,-75,-16,85,-74,-32]
[-46,-14,63,64,-10,-62,62,59,-47,-87,-43,95,35,-85,-1,-31,-8,13,-49,-6,-40,4,32,33,-36,91,-12,30,-100,86,60,50,90,-59,60,-78,99,-20,-22,-39,93,35,15,-34,-53,61,81,-57,-56,-94,53,44,-45,91,-98,-55,-24,-18,0,11,-5,-98,1,21,-53,51,6,41,-91,68,86,-1,53,-84,21,-4,73,-97,-8,-3,80,-38,-74,60,-89,-89,-25,-60,39,-14,-94,-73,10,88,-41,73,-3,8,-56,20,-12,-40,23,5,34,-82,80,58,63,-14,82,-22,81,-64,80,-60,76,21,81,58,73,-79,-51,-28,71,8,90,-71,31,22,68,24,-4,-83,62,-78,19,-100,4,-40,-48,-86,49,39,-89,-34,-6,-29,30,33,6,-15,87,45,-28,-7,-48,-88,-91,62,-40,-45,35,85,-98,-58]
[35,80,64,94,-74,27,16,-94,84,-22,-28,28,-72,56,-1,-21,-80,94,-69,-98,16,-65,35,-39,-72,-51,72,45,46,-44,54,36,-62,13,-79,58,7,1,94,57,90,0,-44,-72,53,-91,-32,-84,-25,1,66,-58,-28,23,-100,57,-40,35,81,-25,97,67,73,6,-52,27,-39,82,74,99,-25,-22,-3,-97,-34,-5,62,50,11,-43,38,95,-92,-1,47,78,-25,-37,98,93,-23,-31,94,59,-3,35,-30,1,-38,-37,-49,49,9,24,93,-19,77,-85,-51,-21,29,-22,-82,63,22,-71,85,13,88,42,-72,17,28,-49,-14,77,18,-79,-68,37,13,-94,60,91,87,39,39,28,75,4,57,64,61,-45,-35,95,29,67,-73,-58,6,60,70,69,-20,-81,-91,30,-58,99,96,-32,45,-92,20,60]
*/

/*
[-98,18,60,88,-29,88,-74,-91,39,-1,-34,-27,19,-46,-10,67,34,81,24,-48,51,-19,100,65,48,92,62,-18,-24,-76,17,70,-41,-22,-13,74,-41,14,-50,-56,62,24,-45,6,-41,-74,22,-58,-60,-46,-44,97,-86,5,-87,-84,-92,97,32,23,70,-74,-66,5,68,-4,-28,85,-2,94,-4,-3,21,4,86,-44,7,-61,67,-40,38,-40,-30,-12,-63,-82,95,23,-82,-78,-86,68,92,81,-64,-74,2,50,35,-54,-7,14,-48,-51,60,-3,51,-92,72,60,-86,-91,-13,42,19,-89,-53,76,-80,-38,-26,-4,72,-64,-1,-51,-1,-8,90,98,88,5,-34,92,32,-26,-56,-21,62,-59,59,43,-37,-61,-38,10,-66,-67,85,-22,-31,48,22,86,54,-13,-69,-16,-16,66,-18,-51,-75,5,-39,-64,-36,-44,-95,-74,-72,33,26,-26,37,-57,95]
[3,64,-74,5,-94,96,2,-52,32,46,-93,64,45,-33,12,56,-80,-52,-98,44,-93,60,-26,44,-96,-16,70,-85,6,19,42,-52,-94,-24,-90,-52,-40,6,68,-30,29,-79,14,94,-59,80,-100,-43,-15,-58,-97,36,-89,30,-72,46,-20,55,39,44,-91,-61,-6,-44,89,8,-43,53,-80,99,32,9,-19,75,58,33,-59,81,-94,28,34,-11,1,-100,26,82,-2,49,-14,62,63,-100,-99,98,-98,-48,-20,29,65,66,23,8,35,-47,-70,84,45,16,87,65,62,-35,45,-48,46,-21,67,-29,50,17,83,86,-87,93,-79,93,-5,19,-7,-24,18,-21,47,-42,-10,96,-93,-31,-16,94,-44,78,82,-90,21,-1,-8,-19,-4,23,42,-89,21,16,86,-28,32,95,-74,93,68,-62,71,77,20,-33,22,-81,-92,-87,17,18,-83,-63,56,9,-8]
[-66,-89,-40,88,-72,56,-18,82,-61,27,90,-97,81,-77,-63,-58,91,-8,84,-7,-62,84,-2,-68,-68,98,69,40,-74,74,48,5,95,-20,88,53,-17,63,33,9,-62,62,93,-29,-40,74,-86,-67,60,-48,15,91,56,31,9,5,-70,12,2,47,5,-78,100,-61,-19,-83,-47,91,-26,85,38,-27,83,-86,-10,-71,85,56,65,-73,94,-95,87,-98,-5,-13,46,35,91,-81,-92,86,3,-100,19,-56,4,-100,-13,-100,96,39,-79,-95,56,31,64,-2,57,-96,-31,37,-45,-89,-69,-52,-65,-46,-37,-34,72,-37,-23,-75,50,-70,13,52,-89,35,56,-56,-12,-97,-4,31,-9,11,-1,18,-59,-41,67,56,-50,-45,50,76,-89,98,-47,-36,-61,20,-93,72,44,-2,-17,-65,60,3,58,45,-13,-21,-73,-99,12,37,46,17,-58,24,-14,-41,-19]
[32,80,52,65,-13,-61,26,-39,-13,91,-70,-28,91,-17,-13,-28,-66,-38,-44,3,31,-43,85,37,51,-6,34,70,73,23,40,28,12,-12,100,100,-5,-23,70,41,-6,-84,74,-83,45,-90,-7,-96,8,-66,36,-70,-15,0,-24,-96,-57,61,98,82,8,55,92,5,-35,-82,81,94,48,72,44,-52,-42,68,-67,-85,-38,30,29,-68,99,3,60,-87,29,72,-53,-78,-59,-13,-70,71,62,-6,-3,90,-14,-85,58,24,29,63,-37,-8,30,-24,48,98,50,-86,45,-32,-67,49,-35,7,-21,51,-29,4,88,-23,2,-43,-60,-14,87,-64,24,9,-90,-4,82,-78,97,47,-48,25,-90,33,-75,-80,-59,-50,-52,29,46,59,-73,89,-52,-93,69,88,-92,14,-50,83,-36,90,81,-16,42,92,32,43,57,61,79,-41,-33,-3,19,-51,48,-41,79]
*/