/*
$ g++ -std=c++11 test4.cpp -o test4.out
$ ./test4.out > qq4.txt
$ cat qq4.txt
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
    printf("\n\nstring primegaps_str = \"");
    for(int i = 0;i<n;i++) {
        maxv = max(maxv, primegaps[i]);
        minv = min(minv, primegaps[i]);
        //printf("%d", i%10);
        char c = 35+(primegaps[i]/2);
        int b = (int)((c-35)*2);
        b = b==0?1:b;
        //if(i>=1 && b!=primegaps[i]) {
        if(b!=primegaps[i]) {
            printf("\n\nStop early\n\n");
            return 0;
        }
        printf("%c", c);
        if(c=='\\') printf("%c",c);
    }
    printf("\";\n\n");
    printf("minV = %d, maxV=%d\n", minv, maxv);
    string s;
    //printf("primegaps.size() = %d\n",(int)primegaps.size());
    //minV = 1, maxV=114 
    printf("\"");
    for(int i = 35;i<=35+(114/2);i++){
        unsigned char c = (unsigned int)((unsigned int)i);
        printf("%c",c);
        if(c=='\\') printf("%c",c);
    }
    printf("\"");
    printf("\n");

    //unordered_map<int,int> mp;
    vector<int> mp = vector<int>(256,0);
    for(auto &i:primegaps) {
        mp[i]++;
    }
    for(int j = 0;j<256;j++) {
        s = "";
        int i = mp[j];
        if(i<50) 
            s ="O____";
        else if(i<100)
            s ="OO___";
        else if(i<150)
            s ="OOO__";
        else if(i<200)
            s ="OOOO_";
        else
            s ="OOOOO";
            
        printf("%3d: %s ->%d\n",j,s.c_str(), mp[j]);
    }
    return 0;
}





