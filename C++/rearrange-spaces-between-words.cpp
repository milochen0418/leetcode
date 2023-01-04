class Solution {
    //https://leetcode.com/problems/rearrange-spaces-between-words
public:
    string reorderSpaces(string text) {
        int n=text.length(), space_cnt=0;//cnt of space
        vector<string> wv;
        string t;
        for(int i = 0; i<n; i++) {
            if(text[i]==' ') 
                space_cnt++;
            else 
                t.push_back(text[i]);
            if(i==n-1 || text[i]==' ') {
                if(t.length()>0){
                    wv.push_back(t);  
                    t="";
                } 
            }            
        }
         
        if(wv.size()==0)
            return string(space_cnt,' ');
        else if(wv.size()==1) 
            return wv[0].append(string(space_cnt, ' '));
        else {
            string ans;
            int gap = space_cnt/(wv.size()-1);
            int remained = space_cnt%(wv.size()-1);        
            for(int i = 0;i<wv.size();i++) {
                ans.append(wv[i]);
                if(i<wv.size()-1) 
                    ans.append(string(gap,' '));
                else
                    ans.append(string(remained,' '));
            }
            return ans;            
        }        
    }
};