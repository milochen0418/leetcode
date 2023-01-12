
class TrafficLight {
    //https://leetcode.com/problems/traffic-light-controlled-intersection
public:
    mutex m;
    int currRoadId = 1;//The Id= 1 is the roadA in default
    TrafficLight() {}
    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        m.lock();
        if(currRoadId != roadId){
            currRoadId = roadId;
            turnGreen();
        }        
        crossCar();
        m.unlock();
    }
};