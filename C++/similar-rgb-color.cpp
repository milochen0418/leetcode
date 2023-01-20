class Solution {
public:
    vector<int>mp={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    
    vector<int>hh = {0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255};
    string hhc = "0123456789abcdef";
    
    string to_hhc="000000000111111111111111112222222222222222233333333333333333444444444444444445555555555555555566666666666666666777777777777777778888888888888888899999999999999999aaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbcccccccccccccccccdddddddddddddddddeeeeeeeeeeeeeeeeefffffffff";
    
    string similarRGB(string color) {
        /*
        //Genearte to_hhc
        vector<int> to_hh = vector<int>(256,0);
        string to_hhc = "";
        for(int i = 0;i<256;i++) {
            int v = i;
            int idx=0, dist = abs(hh[0]-v);
            for(int i = 1;i<hh.size();i++) {
                if(abs(hh[i]-v)<dist) {
                    dist = abs(hh[i]-v);
                    idx = i;
                }
            }
            to_hh[i] = hh[idx];
            to_hhc.push_back(hhc[idx]);
        }
        //for(int i = 0;i<256;i++)printf("%d,",to_hh[i]);
        //printf("\n");
        cout<<to_hhc;
        */
        
        /*
        char r = find_closest_hh(color[1],color[2]);
        char g = find_closest_hh(color[3],color[4]);
        char b = find_closest_hh(color[5],color[6]);
        string ans = "#000000";
        ans[1]=ans[2]=r;
        ans[3]=ans[4]=g;
        ans[5]=ans[6]=b;
        */
        string ans = "#000000";
        char r = to_hhc[getVfromHH(color[1],color[2])];
        char g = to_hhc[getVfromHH(color[3],color[4])];
        char b = to_hhc[getVfromHH(color[5],color[6])];
        ans[1]=ans[2]=r;
        ans[3]=ans[4]=g;
        ans[5]=ans[6]=b;
        
        return ans;
        
    }
    char find_closest_hh (char b, char s) {
        int v = getVfromHH(b,s);
        int idx=0, dist = abs(hh[0]-v);
        for(int i = 1;i<hh.size();i++) {
            if(abs(hh[i]-v)<dist) {
                dist = abs(hh[i]-v);
                idx = i;
            }
        }
        return hhc[idx];
    } 
    
    int getVfromHH(char b,char s) {//b:big, s:small
        return mp[b]*16 + mp[s];
    }
};