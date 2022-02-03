class Solution {
    //https://leetcode.com/problems/find-substring-with-given-hash-value
    //Modulo Math : https://en.wikipedia.org/wiki/Modulo_operation
    //Math https://jamboard.google.com/d/1Vx8Tqk-Aph_FftKULHNIsJxdeQCciE5OHTStAwuoiEg/edit?usp=sharing
    //Jamboard https://jamboard.google.com/d/1Vx8Tqk-Aph_FftKULHNIsJxdeQCciE5OHTStAwuoiEg/viewer
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
        return answer(s, power, modulo, k, hashValue);
        
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
};