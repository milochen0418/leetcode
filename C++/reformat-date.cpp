class Solution {
    //https://leetcode.com/problems/reformat-date
public:
    string reformatDate(string date) {
        int n = date.length();
        vector<string> mon_old= {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        vector<string> mon_new = {
            "01","02","03","04","05","06",
            "07","08","09","10","11","12"
        };
        
        
        char buff[10];
        
        string ans;
        string s;
        int cnt=0;
        for(int i = 0;i<n;i++) {
            if(date[i]!=' ')s.push_back(date[i]);
            
            if(date[i]==' ' || i+1>=n) {
                if(cnt==0){
                    int day = 0;
                    for(int j=0;j<s.length();j++) 
                        if('0'<=s[j] && s[j]<='9') 
                            day=day*10+s[j]-'0';
                    sprintf(buff,"%02d\0", day);
                    ans = string(buff);
                } else if(cnt==1) {
                    for(int j=0;j<mon_old.size();j++) {
                        if(mon_old[j]==s) {
                            //ans.append(mon_new[j]);
                            ans = mon_new[j] + "-" + ans;
                            break;
                        }
                    }
                } else {
                    int year = 0;
                    for(int j=0;j<s.length();j++) 
                        if('0'<=s[j] && s[j]<='9') 
                            year=year*10+s[j]-'0';
                    sprintf(buff,"%04d\0", year);
                    //ans.append(string(buff));
                    ans = string(buff) + "-" + ans;
                    return ans;
                }
                
                s="";
                cnt++;
            } 
                
        }
        return ans;
        
    }
};