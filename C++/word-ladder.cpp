class Solution {
    //https://leetcode.com/problems/word-ladder/
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return answer1(beginWord, endWord, wordList);
        unordered_map<string,vector<int>> mp;
        int n = wordList.size();
        vector<bool> traveled(n, false);
        for(int i=0; i<n; i++) {
            string& str = wordList[i];
            int m = str.length();
            string key = str;
            for(int j = 0; j<m; j++) {
                char orig_char = key[j];
                for(int k=0;k<26;k++) {
                    char new_char = k + 'a';
                    if(new_char != orig_char) {
                        key[j]=new_char;
                        mp[key].push_back(i);
                    }
                }
                key[j] = orig_char;
            }
        }
        
        queue<pair<int,int>> q; //index to string in wordList,len
        for(auto& i:mp[beginWord]) {
            if(traveled[i] == false) {
                if(endWord == wordList[i]) {
                    return 1+1;
                }
                q.push({i,1});
                traveled[i] = true;                
            }
        }
        while(!q.empty()) {
            pair<int,int>& p = q.front();
            string &str = wordList[p.first];
            int len = p.second;
            if(endWord == str) {
                return len+1;
            }

            q.pop();
            for(auto& i:mp[str]) {
                if(traveled[i] == false) {
                    q.push({i,len+1});
                    traveled[i] = true;
                    
                }
            }
        }
        return 0;
    }
    
    int answer1(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,vector<int>> mp;
        int n = wordList.size();
        vector<bool> traveled(n, false);
        for(int i=0; i<n; i++) {
            string& str = wordList[i];
            int m = str.length();
            string key = str;
            for(int j = 0; j<m; j++) {
                char orig_char = key[j];
                for(int k=0;k<26;k++) {
                    char new_char = k + 'a';
                    if(new_char != orig_char) {
                        key[j]=new_char;
                        mp[key].push_back(i);
                    }
                }
                key[j] = orig_char;
            }
        }
        
        queue<pair<int,int>> q; //index to string in wordList,len
        for(auto& i:mp[beginWord]) {
            if(traveled[i] == false) {
                if(endWord == wordList[i]) {
                    return 1+1;
                }
                q.push({i,1});
                traveled[i] = true;                
            }
        }
        while(!q.empty()) {
            pair<int,int>& p = q.front();
            string &str = wordList[p.first];
            int len = p.second;
            if(endWord == str) {
                return len+1;
            }

            q.pop();
            for(auto& i:mp[str]) {
                if(traveled[i] == false) {
                    q.push({i,len+1});
                    traveled[i] = true;
                    
                }
            }
        }
        return 0;
    }
    
};

/* testcase
"hit"
"hot"
["hot","dot","dog","lot","log","cog"]
"hit"
"cog"
["hot","dot","dog","lot","log","cog"]
"hit"
"cog"
["hot","dot","dog","lot","log"]
"nape"
"mild"
["dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"]
*/

