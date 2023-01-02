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
typedef unsigned long long ull;
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
    vector<int> mp_max_dist = vector<int>(256,0); //index distance of primegap
    vector<int> mp_max_pdist = vector<int>(256,0); //real distance of two prime
    vector<int> mp_min_dist = vector<int>(256,100000); 
    vector<float> mp_avg_dist = vector<float>(256,0.0f);
    for(int i = 0;i<primegaps.size();i++) {
        vector<int> &v= mp[primegaps[i]];
        v.push_back(i);
        if(v.size()>=2) { 
            int nn = v.size();
            mp_max_dist[primegaps[i]] = max(mp_max_dist[primegaps[i]], v[nn-1] - v[nn-2] );
            mp_min_dist[primegaps[i]] = min(mp_min_dist[primegaps[i]], v[nn-1] - v[nn-2] );
        } 
    }
    for(int i = 0;i<256;i++) {
        ull sum_dist = 0;
        //figure out avg index distance
        if(mp[i].size()>=2) {
            //for(auto &val:mp[i])sum_dist+=val;
            for(int j =1;j<mp[i].size();j++) {
                sum_dist+=(mp[i][j] - mp[i][j-1]);
            }
            double avg_double = sum_dist / mp[i].size()-1;
            mp_avg_dist[i] = (float) avg_double;
        }
        //figure out prime distance
        if(mp[i].size()>=2) {
            
            for(int j =1;j<mp[i].size();j++) {
                int sum = 0;
                int lidx = mp[i][j-1];
                int ridx = mp[i][j]; 
                for(int idx=lidx;idx<=ridx;idx++) sum+=primegaps[idx];
                mp_max_pdist[i] = max(mp_max_pdist[i], sum);
            }
        }

    }
    for(int i = 0;i<256;i++) {
        //prime gap only >=2 for all prime>=3
        if(i%2==0)
            printf("%3d:repeat=%5d, max_dist=%5d, min_dist=%5d, avg_dist=%5.0f, max_pdist=%5d\n", i, (int)mp[i].size(), mp_max_dist[i],  mp_min_dist[i]==100000?-1:mp_min_dist[i], mp_avg_dist[i], mp_max_pdist[i]);
    }


    return 0;
}





