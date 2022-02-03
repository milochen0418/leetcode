class Solution {
    //https://leetcode.com/problems/find-substring-with-given-hash-value
    //Modulo Math : https://en.wikipedia.org/wiki/Modulo_operation
    //Math https://jamboard.google.com/d/1Vx8Tqk-Aph_FftKULHNIsJxdeQCciE5OHTStAwuoiEg/edit?usp=sharing
    //Jamboard https://jamboard.google.com/d/1Vx8Tqk-Aph_FftKULHNIsJxdeQCciE5OHTStAwuoiEg/viewer

    //article https://leetcode.com/problems/find-substring-with-given-hash-value/discuss/1741682/C%2B%2B-or-O(N)-or-create-simple-solution-step-by-step-from-basic-math
    //FB post https://www.facebook.com/groups/1451299754892511/posts/5034261479929636/
/*

"leetcode"
7
20
2
0
"xmmhdakfursinye"
96
45
15
21
"kfedcbdngvlykqyrbvwbnaassgjifjxtawlafhcpjtpzfnbsqfasohevbbhkwmtnmixolfepkjmcbadqcljmsbonrngsgfqwzqiisbiwiqgtqtqddukgtjymbxzmtxrobuhkdxmdmqccrauzkrjisstznnkhupiandekzcchsrzwintkkzhvqomqmnbasynmvtxwydcvwoukqmgrpmgzqancuzapgncasxnbyznlrdvcbomdptjftgxdzeqzyavfdpseoxpvohpxtikyjfvskxyqbubgnseraxtrcrwjxloxymhqgaxwbbvzhjsbncqrlpdbiuakdjzjrbclhxgnjjyfrqyjchlsdrcwtdoktviqwjctlmzqemumgmjufcbixkfhzkugsvnkrrakccguybwhmuexiemqusltaaqrswsezccqzaputgaabrjdeihmkpzbojnusmhkwjdxvgiexwdkkazhhmlalgzvxgqgncfytrxuhkwhwcxhmlbvkhjcnyztepwnlpthozdqexvhxpvheopjrsjzkqrstczffkhkikelwydcbnghfiibeyabgegdgaqvasujmggltkvokmnsmontjzsmzoeeqenafvurbnbwqbizvaqxfgnoxasctfrwvqmoufvpajdkethlvbhbehxahcpcizocbchwfznhuqtblwepeqdhycrovqosmxxeeqaffjvvclmpcqdugndexexcykyusetuamymszlteobxkestwbzubpstbwrstuovlybycevedzgurqvlgkouvavcukccgixixsrndurvrkfegegnchbhockujlafxexlxhgysraviztkjymiqxrlldcixvfnzrpserrqycbfmesqbltywmandcqtluccbisfqzosbvedqhsxepdjevaasylvjmfpvyxqvclaalgxytiukyarojmzyovmiunkvqhkouhxxhbemavagrhteofpowvlpdunjjpwgcjibagfswrzwkgrwklppchvtukzncvoqorlsskyghkhrazwvyqqjfygmduhsfkrseddgmtdvlqeruxogmyttdqmdpmscspatkoifauivwjtbwisiiqztrllfqnjvbagrfylrpjudjmvwhdkhahyxlsfbkuuyofryfgblllzeacfiqqawridcbtqnroxwuqhyspqmwhxmjztqokofnkfvupcykszthicdgjbrgafpztktrcwtayoulnjaazigkinnpttghhyboiczvtswenshlmqyelnwhzqlswblqssiiynypfcxerlykpiyimkoodimdfdlzbwmlwflylcqwaflivqeonjswvowxgeoafmppodmfbvooodtnzgmhfnchenaaywqevklrpgajbmbxgiopofghlouhjfarjxlclcullsgyzhohowtragbkaebrvbkmxfxughlirtikheojbrrgxtqldfdnqxndzvfgajiltnqnuwavxbrvuiycsizunlglwnivpseyfwmgydmmpzhxkdtpuzpddacjmjhvncdoicedkimdgaqobdfagpggvjemstqbsshynyvhdyslgldvkapqgusmnuroqxcivjifkhrotomxodficktxmcytkbqitrlalpbtphowfgtzgfacabjodvivgykorvmxhzpqvskolkbfpbdgowlighossrlwiomgohfhgklmlnekniqfjmvvqvmimkeddfxnxwzzroospxvndynetghkgrakuslukqsrdtmjkblwrmwhzzojcwwogrjvnftdwwpoqcjqimvjbwgqgpeffjnwlzdyhkhwmvpwpcmjmdqneexqwcrvdxsfsnidwyflwxwngczklprhoazeeqwclrqvnicfvrtbqailbwrqxadxslouwdjycidupemdwhpkqekaxxprtdtmjficrhlvqidvgwkllaowyyajkxugqiztbpzvjqtpuyugkvdfcaczzruskvucsxtvroljnjojuzncatgnypbzwvilbajqqnjovqxcfunwwbxgshrjlajwveaswqegidfnedpxqdreddvawrpbllkcshlafnxyocbmwacytvgtoonlkukqhxwbfxcfnbgmrfcnkvtxmygiyjoyoljd"
71717
94536
1149
39999
"fbxzaad"
31
100
3
32
"bzzrtrrpppigevriaooetwawtnfwddgdvoldxucsbyaufhygdxpnxupmvwbryzlgiuierypzqvwiywqlwiygyj"
76
4
60
2
"abc"
7
10
1
1
*/
    
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        return answer3(s, power, modulo, k, hashValue);
        
        const int s_len = s.length();
        long mod = (long)modulo;
        long pow = long(power) % mod;
        vector<long> p(k,1);
        for(int i=1;i<k;i++) { 
            p[i] = ( p[i-1] * pow ) % mod; 
            //By blue point (1) of picture explanation.
        }
        
        vector<long> vs(s_len);
        for(int i=0;i<s_len;i++) {
            vs[i] = (s[i]-'a'+1) % mod;
        }
        
        /*
        for(int idx = 0; idx < s_len-k+1; idx++) {
            int H = 0;
            for(int i=0; i<k; i++) {
                int pos = i + idx;
                int item = (vs[pos]*p[i]) % modulo;
                H = (H + item) % modulo;
            }
            
            if ( H == hashValue ) {
                return s.substr(idx,k);
            }
        }
        */
        
        pair<int, int> pos_len = {-1, -1};
        long H = 0;
        for(int i=0;i<k;i++) {
            int pos = i + s_len-k;
            long item = (vs[pos]*p[i]) % mod; 
            ////By blue point (2) of picture explanation.
            H = (H + item) % mod;
        }
        if ( H == hashValue ) {
            pos_len = {s_len-k,k};
        }
        /*
        [0,1,2] k=3
        [0,1,2,3,4] len_s=5
            [0 1 2] start_idx = 2;  2=len_s-k
          [0 1 2] 
        [0 1 2]
        */  
        for(int i = (s_len-k) -1; i >= 0; i--) {
            long removed_factor = vs[k+i]*p[k-1] % mod;
            //By blue point(3) of picture explanation.
            long added_factor = vs[i];
            //By blue point(4) of picture explanation.
            H = (mod + H - removed_factor) % mod;
            H = (pow * H) % mod;
            H = (H + added_factor) % mod;
            if (H == hashValue ) {
                pos_len = {i,k};
            }
        }        
        return s.substr(pos_len.first, pos_len.second);        
    }
    
    string answer(string s, int power, int modulo, int k, int hashValue) {
        const int s_len = s.length();
        long mod = (long) modulo;
        long pow = long(power) % mod;
        vector<long> p(k,1);
        for(int i=1;i<k;i++) { 
            p[i] = ( p[i-1] * pow ) % mod; 
        }
        
        vector<long> vs(s_len+k,0);
        for(int i=0;i<s_len;i++) {
            vs[i] = (s[i]-'a'+1) % mod;
        }
        
        pair<int, int> pos_len = {-1, -1};
        long H = 0;
        /*
        for(int i=0;i<k;i++) {
            int pos = i + s_len-k;
            long item = (vs[pos]*p[i]) % mod; 
            ////By blue point (2) of picture explanation.
            H = (H + item) % mod;
        }
        if ( H == hashValue ) {
            pos_len = {s_len-k,k};
        }
        */
        
        //for(int i = (s_len-k) -1; i >= 0; i--) {
        for(int i = s_len -1; i >= 0; i--) {        
            long removed_factor = vs[k+i]*p[k-1] % mod;
            long added_factor = vs[i];
            H = (mod + H - removed_factor) % mod;
            H = (pow * H) % mod;
            H = (H + added_factor) % mod;
            if ( i<= (s_len-k)  && H == hashValue) {
                pos_len = {i,k};
            }
        }
        return s.substr(pos_len.first, pos_len.second);        
    }
    
    
    string answer2(string s, int power, int modulo, int k, int hashValue) {
        const int s_len = s.length();
        long mod = (long) modulo;
        long pow = long(power) % mod;
        vector<long> p(k,1);
        //tailed k elements is dummy
        vector<long> vs(s_len+k,0); 
        
        //figure out power number in mod
        for(int i=1;i<k;i++) 
            p[i] = ( p[i-1] * pow ) % mod; 
        //set vector vs to represent string s in mod
        for(int i=0;i<s_len;i++) 
            vs[i] = (s[i]-'a'+1) % mod;
        
        pair<int, int> pos_len = {-1, -1};
        long H = 0;
        for(int i = s_len -1; i >= 0; i--) {
            //remove factor of moving slide window
            H = (mod + H - (vs[k+i]*p[k-1] % mod)) % mod;
            //add factor of moving slide window
            H = ((pow * H) % mod + vs[i]) % mod;
            // figure out result if hashValue match
            if ( i<= (s_len-k)  && H == hashValue) 
                pos_len = {i,k};
        }
        return s.substr(pos_len.first, pos_len.second);
    }
    
    
    string answer3(string s, int power, int modulo, int k, int hashValue) {
        const int s_len = s.length();
        long mod = (long) modulo;
        long pow = long(power) % mod;
        vector<long> p(k,1);
        //tailed k elements is dummy
        vector<long> vs(s_len+k,0); 
        //figure out power number in mod
        for(int i=1;i<k;i++) 
            p[i] = ( p[i-1] * pow ) % mod; 
        //set vector vs to represent string s in mod
        for(int i=0;i<s_len;i++) 
            vs[i] = (s[i]-'a'+1) % mod;
        
        pair<int, int> len_pos = solve(p, vs, s_len, pow, mod, k, hashValue);
        return s.substr(len_pos.first,  len_pos.second);        
    }
    
    pair<int, int> solve(vector<long>& p, vector<long>&vs, const int s_len, long pow, long mod, int k, int hashValue) {
        pair<int, int> pos_len = {-1, -1};
        long H=0;
        for(int i = s_len -1; i >= 0; i--) {
            //remove factor of moving slide window
            H = (mod + H - (vs[k+i]*p[k-1] % mod)) % mod;
            //add factor of moving slide window
            H = ((pow * H) % mod + vs[i]) % mod;
            // figure out result if hashValue match
            if ( i<= (s_len-k)  && H == hashValue) 
                pos_len = {i,k};
        }
        return pos_len;
    }

};