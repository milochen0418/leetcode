/*
$ g++ -std=c++11 test5.cpp -o test5.out
$ ./test5.out > qq5.txt
$ cat qq5.txt
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#include "primegaps.hpp"
//vector<int> primegaps;
int main()
{
    //primegaps = vector<int>({1,2,2,4,2,4});
    int n = primegaps.size();
    printf("size = %d\n", n);
    int maxv = INT_MIN, minv=INT_MAX;
    printf("minV = %d, maxV=%d\n", minv, maxv);
    string s;

    //figure out the maximum distance of prime gap 
    vector<vector<int>> mp = vector<vector<int>>(256,vector<int>()); 
    vector<int> mp_dist = vector<int>(256,0); 
    for(int i = 0;i<primegaps.size();i++) {
        vector<int> &v= mp[primegaps[i]];
        v.push_back(i);
        if(v.size()>=2) { 
            int nn = v.size();
            mp_dist[primegaps[i]] = max(mp_dist[primegaps[i]], v[nn-1] - v[nn-2] );
        }
    }
    for(int i = 0;i<256;i++) {
        printf("%3d:repeat=%5d, max_distance=%d\n", i, (int)mp[i].size(), mp_dist[i] );
    }


    return 0;
}





