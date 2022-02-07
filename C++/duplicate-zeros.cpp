class Solution {
    //https://leetcode.com/problems/duplicate-zeros/
public:
    void duplicateZeros(vector<int>& arr) {
        /*
        for(auto it=arr.begin(); it!=arr.end(); it++) {
            if(*it == 0) {
                it = arr.insert(it, 0);
                it++;
            }
        } */
        int n = arr.size();
        for(int i=0;i<n;i++) {
            int val = arr[i];
            if(val==0) {
                int temp = 0;
                for(int j=i+1;j<n;j++) { //j=2 arr[j]==2, n=8
                    swap(temp, arr[j]);
                    //swap(temp=0, arr[2]=2 ) -> arr[2]=0, temp=2
                    //swap(temp=2, arr[3]=3 ) -> arr[3]=2, temp=3
                    //swap(temp=3, arr[4]=0 ) -> arr[4]=3, temp=0
                    //swap(temp=0, arr[5]=4 ) -> arr[5]=0, temp=4
                    //swap(temp=4, arr[6]=5 ) -> arr[6]=4, temp=5
                    //swap(temp=5, arr[7]=0 ) -> arr[7]=5, temp=0
                }
                i++;
            }
        }
    }
};