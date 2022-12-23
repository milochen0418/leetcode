class Solution {
    //https://leetcode.com/problems/faulty-sensor
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        if(sensor1==sensor2) return -1;
        int n = sensor1.size();
        int wellPair12=wellPair(sensor1, sensor2), wellPair21=wellPair(sensor2, sensor1);
        
        if(wellPair12<0 && wellPair21<0) return -1;
        if(wellPair12>=0 && wellPair21>=0) return -1;
        if(wellPair12>=0) {
            printf("sensor 1 correct\n");
            return wellPair12;
        }
        if(wellPair21>=0) {
            printf("sensor 2 correct\n");
            return wellPair21;
        }
        return -1;
    }
    //return drtopped index if the following two condition satisfied.
    //(1)the first argument is correct sensor
    //(2)the second argument is incorrect sensor 
    int wellPair(vector<int>& correct, vector<int>& incorrect) {
        int n = correct.size();
        int i = 0; 
        while(correct[i]==incorrect[i])i++;
        int dropped_idx = i;//the index of dropped value in correct[]
        while(i+1<n && correct[i+1]==incorrect[i]) i++;
        if(i+1!=n) return -1;
        if(correct[dropped_idx] == incorrect[n-1])return -1;
        return dropped_idx;
    }
};

/*
Errro for the testcase 
[2,3,2,2,3,2]
[2,3,2,3,2,7]
Output:3 
Expected:2
*/