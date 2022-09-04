class Solution {
    //https://leetcode.com/problems/check-distances-between-same-letters/
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> dist = vector<int>(26,0);
        for(int i = 0; i<26;i++) {
            char keyc = (char)('a' + i);
            //"abaccb"  cidx1=0, cdix2=2  2-0-1 =1 dist[0]->1
            //cidx1 = 1, cdix2 = 5 , 5-1-1 =3, dist[1] -> 3
            
            int cidx1 = -1;
            int cidx2 = -1;
            for(int j = 0;  j< s.length();j++) {
                if(s[j] == keyc) {
                    if(cidx1 == -1) {
                        cidx1 = j;
                    } else {
                        cidx2 = j;
                    }
                }
            }
            int distv = cidx2-cidx1-1;
            dist[i] = distv;
            //if(cidx1 == -1) dist[i] = 0;
        }
        /*
        printf("dist = ");
        for(int i=0;i<dist.size();i++) {
            printf("%d, ",  dist[i]);
        }
        printf("\n");
        */
        bool flag = true;
        for(int i = 0; i < 26;i++) {
            if(dist[i]==-1) continue;
            if(dist[i] != distance[i]) flag = false;
        }
        return flag;
        
        //return dist == distance;
    }
};