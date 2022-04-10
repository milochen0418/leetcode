class Solution {
    //https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/
public:
    string minimizeResult(string expression) {
        
        string&s = expression;
        int n = s.length();
        int plus_idx = 0;
        for(int i = 0; i<n;i++ ){
            if(s[i] == '+') plus_idx = i;
        }
        string lstr = s.substr(0,plus_idx);
        string rstr = s.substr(plus_idx+1);
        //cout<<lstr<<"\n";
        //cout<<rstr<<"\n";
        
        int ln = lstr.length();
        int rn = rstr.length();
        
        //LA * (LB + RB) * RA
        //"247+38",  ln=3, rn=2...  maximum li=ln-1, maximum ri=rn-1;
        //"247+38",  li = 1, ri=1  2(47+3)8  -> try this coding
        //"247+38",  li = 1, ri=0  2(47+38) 
        //"247+38",  li = 0, ri=0  (247+38)  -> try this coding
        //"247+38",  li = 2, ri=1  24(7+38) 
        
        pair<string,int> aa = getSome(lstr, rstr, 0, 0);
        
        long long min_int = (long long)INT_MAX+1;
        string min_str = "";
        for(int li=0;li<ln;li++) {
            for(int ri=0;ri<rn;ri++){
                pair<string,int> p = getSome(lstr, rstr, li, ri);
                if((long long)p.second < min_int) {
                    min_int = (long long)p.second;
                    min_str = p.first;
                }
                //cout<<"string = " <<p.first<<", int = "<<p.second<<"\n";
            }
        }
        return min_str;
        //return aa.first;
        
        //(1234+5678)
        int L = 0;  //0:(1234+,  1:1(234+, 2:12(34+, 3:123(4, 4:1234
        int R = n-1;
        return lstr;   
    }
    pair<string,int> getSome(string& lstr, string& rstr, int li, int ri) {
        //LA * (LB + RB) * RA
        int LA, LB, RB, RA;
        if(li==0) {
            LA = 1;  
            LB = stoi(lstr);
        } else {
            LA = stoi(lstr.substr(0,li));
            LB = stoi(lstr.substr(li));
        }
        if(ri == 0) {
            RA = 1;
            RB = stoi(rstr);
        } else {
            int rn = rstr.length();
            //int i = rn - ri + 1; //
            int i = rn - ri;
            //5678, rn = 4.  
            //ri=1, i=3
            //ri=2, i=2
            //ri=3, i=1
            RB = stoi(rstr.substr(0,i));
            RA = stoi(rstr.substr(i));
        }
                      
        int ans_int = LA*(LB+RB)*RA;
        //string ans_str = (to_string(LA)) + "(" + to_string(LB) + "+" + to_string(RB) + ")" + to_string(RA);
        string str_LA = (li==0)?"":to_string(LA);
        string str_RA = (ri==0)?"":to_string(RA);
        
        //string ans_str = (to_string(LA)) + "(" + to_string(LB) + "+" + to_string(RB) + ")" + to_string(RA);
        string ans_str = str_LA + "(" + to_string(LB) + "+" + to_string(RB) + ")" + str_RA;
        return {ans_str,ans_int};            
    }
        
};