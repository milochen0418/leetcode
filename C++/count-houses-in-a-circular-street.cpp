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