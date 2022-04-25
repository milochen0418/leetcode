class Solution {
    //https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //O(n)
        //special processing for double half-target in sequence
        if(target %2 == 0) {
            int half = target/2;
            for(int i = 0; i < numbers.size(); i++) {
                if(numbers[i] == half) {
                    if(i+1<numbers.size() && numbers[i+1] == half) {
                        vector<int> ans = vector<int>(2,1);
                        ans[0] += i;
                        ans[1] += i+1;
                        return ans;
                    }
                }
            }
        }
        
        
        //O(n)
        //process vector<int> a as sorting sequence without repeating and kill half-target
        vector<int> a;
        
        //Don't kill. half-target repeat, but remove duplicate
        /*
        int prev = numbers[0];
        a.push_back(prev);
        for(int i = 1; i<numbers.size();i++) {
            if(prev==numbers[i]) continue;
            if(target%2==0 && target/2 == numbers[i]) continue;
            a.push_back(numbers[i]);
            prev = numbers[i];
        }*/
        //remove all number that have another duplicate in same array
        for(int i = 0 ;i<numbers.size();i++) {
            if(i+1<numbers.size() && numbers[i+1]==numbers[i]) {
                int duplicate = numbers[i];
                while(i<numbers.size() && duplicate == numbers[i]) i++;
            } else {
                a.push_back(numbers[i]);
            }
        }
        
        
        //print trim array a
        cout<<"a=[ ";
        for(int i = 0;i<a.size();i++){
            printf("%d, ", a[i]);
        }
        cout<<"]\n";
        
        
        //Do 2-sum in O(n log n) on array a
        
        int index1 = 0;
        int index2 = 0;
        for(int i = 0; i<a.size();i++) {
            
            int val = target - a[i]; 
            int L = 0, R = a.size()-1;
            
            while(L<=) {
                int M = L + (R-L)/2;
                if(a[M] == val) {
                    index1 = i;
                    index2 = M;
                    break;
                } else if(target < a[M]){
                    R = M-1;
                } else {
                    L = M+1;
                }
            }
            if(index1>0 && index2>0) break;
        }
        printf("real ans = [%d, %d]\n", numbers[23], numbers[31]);
        
        //O(n) convert index1 in a into index1 in numbers;
        for(int i = 0;i<numbers.size();i++) {
            if(numbers[i] == a[index1]) {
                index1 = i;
                break;
            }
        }
        
        
        //O(n) convert index2 in a into index1 in numbers;
        for(int i = 0;i<numbers.size();i++) {
            if(numbers[i] == a[index2]) { 
                index2 = i;
                break;
            }
        }
        
        vector<int> ans = vector<int>(2,1);
        ans[0] += index1;
        ans[1] += index2;
        sort(ans.begin(), ans.end());
        //return vector<int>(2,-1);
        
        //return a;
        return ans;
        
    }
};