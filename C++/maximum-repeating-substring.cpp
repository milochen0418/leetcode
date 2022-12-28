class Solution {
    //https://leetcode.com/problems/maximum-repeating-substring
    //article https://leetcode.com/problems/maximum-repeating-substring/discuss/2961354/C%2B%2B-or-find-all-word-first
public:
    int maxRepeating(string sequence, string word) {
        int maxk = 0, k = 0, i = 0, n = word.length();
        vector<int> v; //save all start index of every substring that equal to word 
        unordered_set<int> s;
        for(int j = 0;j<sequence.length();j++) {
            char c = sequence[j];
            if(c==word[0]) {
                int i = 0;
                while(i<n && sequence[j+i]==word[i])i++;
                if(i==n) {
                    v.push_back(j);
                    s.insert(j);
                }
            }
        }
        
        for(auto &i:v) {
            int j=i;
            k = 0;
            while(s.find(j) != s.end()) {
                s.erase(j);
                j=i+(n*++k);
            }
            maxk = max(maxk, k);
        }
        return maxk;        
    }
};

/* 
Error Case
"bbaabaabaabaaabbbaaabaababbabbaabbabbbabbabbabbbbabaababbbaaaababbbabbaababababbabbbaabbaabbbb"
"bba"

Successful cases
"ababc"
"ab"
"ababc"
"ba"
"ababc"
"ac"
"aaabaaaabaaabaaaabaaaabaaaabaaaaba"
"aaaba"
"bbaa"
"ba"

*/