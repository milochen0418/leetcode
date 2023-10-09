/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
    //https://leetcode.com/problems/count-houses-in-a-circular-street
    //article https://leetcode.com/problems/count-houses-in-a-circular-street/discuss/4148510/C%2B%2B-simple-array-approach
public:
    int houseCount(Street* street, int k) {
        for(int i = 0; i<k;i++) {
            street->closeDoor();
            street->moveRight();
        }
        int ans = 1;
        street->openDoor();
        street->moveRight();
        while(!street->isDoorOpen()) {
            ans++;
            street->moveRight();
        }
        return ans;
    }
};