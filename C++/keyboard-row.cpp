class Solution {
public:
    vector<int> v ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,4,2,1,2,2,2,1,2,2,2,4,4,1,1,1,1,2,1,1,4,1,4,1,4,0,0,0,0,0,0,2,4,4,2,1,2,2,2,1,2,2,2,4,4,1,1,1,1,2,1,1,4,1,4,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        
        /*
        //The code to generate pre-built table v
        vector<int> v = vector<int>(256,0);
        vector<string> rows = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL" ,"zxcvbnmZXCVBNM"};
        for(int i = 0;i<rows.size();i++) {
            string &s = rows[i];
            for(auto &c:s)  v[c]=1<<i;
        }
        for(int i = 0;i<256;i++) printf("%d,",v[i]);
        */
        for(auto &s:words) {
            int val = 0;
            for(auto &c:s) val|=v[c];
            if(val==1 || val==2 || val==4) ans.push_back(s);
        }
        
        return ans;
    }
};