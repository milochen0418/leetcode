class ParkingSystem {
    //https://leetcode.com/problems/design-parking-system
public:
    vector<int> a;
    ParkingSystem(int big, int medium, int small) {
        a = {0, big, medium, small};
    }
    
    bool addCar(int carType) {
        if(a[carType]==0) return false;
        a[carType]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */