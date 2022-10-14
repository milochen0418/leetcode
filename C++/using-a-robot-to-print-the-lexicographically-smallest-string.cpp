class Solution {
    //https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
/*
    Observation: 
    [zza -> azz]
    push z(z)
    push z(zz)
    push a(zza), pop a(zz)
    pop(z)
    pop(z)
    
    
    [bac -> abc]
    push b(b), 
    push a(ba), pop a(b)
    pop b()
    push c(c)
    pop c()    
    
    [bdda -> addb]
    push b(b),
    push d(bd),
    push d(bdd),
    push a(bdda), pop a(bdd)
    pop d(bd)
    pop d(b)
    pop b()
*/

/* Err case
    Input 
    "vzhofnpo"

    vzhofnpo
    fhnoopvz

    My Output
    "fopnohzv"

    Expected:
    "fnohopzv"



    vzhofnpo



    h 

    ofnpo -> fnoop  Yes


    Sorted ss = fhnoop

    hofnpo - > fnohop Yes   Mine is ->fopnoh .. Err

    fhnoop (sorted)
    [hofnpo -> fnohop]
    push h(h) _fhnoop
    push o(ho) _fhnoop
    push f(hof), pop f(ho) f_hnoop -> fh_noop (because all h is in stack)
    push n(hon), pop n(ho) fhn_oop
    
    pop o(h) 
    pop h()
    
    push p(p), 
    push o(po),
    
    pop o(p),
    pop p(),

*/
    
public:
    string robotWithString(string s) {
        string ss = s;
        sort(ss.begin(), ss.end());
        printf("ss = %s\n", ss.c_str());
        int si = 0;
        
        string ans;
        stack<char> stk;
        for(auto &c:s) {
            bool isWrite = false;
            if(c == ss[si]) {
                ans.push_back(c);
                si++;
                isWrite = true;
            }
            while(!stk.empty()) {
                if(stk.top() == ss[si]) {
                    ans.push_back(stk.top());
                    stk.pop();
                    si++;
                } else {
                    break;
                }
            }
            if(!isWrite) {
                stk.push(c);
            }
        }
        
        while(!stk.empty()){
            char c = stk.top();
            ans.push_back(c);
            stk.pop();
        }
        return ans;
            
    }
};