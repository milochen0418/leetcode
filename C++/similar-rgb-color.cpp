class Solution {
public:
    vector<int>mp={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,11,12,13,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    
    vector<int>hh = {0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255};
       string hhc = "0123456789abcdef";
    //{"00","11","22","33","44","55","66","77","88","99","aa","bb","cc","dd","ee","ff"};
    string similarRGB(string color) {
        char r = find_closest_hh(color[1],color[2]);
        char g = find_closest_hh(color[3],color[4]);
        char b = find_closest_hh(color[5],color[6]);
        string ans = "#000000";
        ans[1]=ans[2]=r;
        ans[3]=ans[4]=g;
        ans[5]=ans[6]=b;
        
        
        return ans;
        
        /*
        //Generate mp by the following code
        vector<int> mp = vector<int>(256,0);
        for(int i =0;i<=9;i++) mp[i+'0']=i;
        for(int i='a';i<='f';i++) mp[i]=i-'a'+10;
        for(int i='A';i<='F';i++) mp[i]=i-'A'+10;
        for(int i=0;i<256;i++) printf("%d,",mp[i]);
        */
        
        /*
        //Generate hh = {0,17,34,51,68,85,102,119,136,0,170,187,204,221,238,255};
        string a = "0123456789abcdef";
        printf("\ngenerate hh = ");
        for(int i = 0;i<a.length();i++) printf("%d,",getVfromHH(a[i],a[i]));
        */
        return "";   
    }
    char find_closest_hh (char b, char s) {
        int v = getVfromHH(b,s);
        //printf("v = %d, ", v);
        int idx=0, dist = abs(hh[0]-v);
        for(int i = 1;i<hh.size();i++) {
            if(abs(hh[i]-v)<dist) {
                dist = abs(hh[i]-v);
                idx = i;
            }
        }
        //printf("dist = %d, idx=%d\n",dist,idx);
        return hhc[idx];
    } 
    
    int getVfromHH(char b,char s) {//b:big, s:small
        return mp[b]*16 + mp[s];
    }
};