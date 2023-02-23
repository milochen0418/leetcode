class Solution {
    //https://leetcode.com/problems/accounts-merge/
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
            
        unordered_map<string, int> mp_mail_int;//mail to its ID int
        vector<string> mp_int_mail;//mail ID to its mail string. 
        vector<vector<int>> accs = vector<vector<int>>(accounts.size(),vector<int>());
        int cnt=0;
        for(int j = 0;j < accounts.size();j++) {
            vector<string>& acc = accounts[j];
            int n = acc.size();
            for(int i = 1;i<n;i++) {
                if(mp_mail_int.find(acc[i]) == mp_mail_int.end()){
                    mp_mail_int[acc[i]] = cnt++;
                    mp_int_mail.push_back(acc[i]);
                }
                accs[j].push_back(mp_mail_int[acc[i]]);
            }
        }
        
        //print data structure 
        /*
        for(int i = 0; i<accs.size();i++) {
            vector<int> & acc = accs[i];
            printf("%s, ", accounts[i][0].c_str());
            for(auto &i: acc) printf("%s, ", mp_int_mail[i].c_str());
            printf("\n");
        }*/

        
        unordered_map<int,vector<int>> mp_mail_to_accid_vec; //mail_id to the vec of acc_id that own the mail_id
        for(int acc_id = 0; acc_id<accs.size();acc_id++) {
            vector<int>& acc = accs[acc_id];
            for(auto &mailid: acc) 
                mp_mail_to_accid_vec[mailid].push_back(acc_id);
        }
        
        vector<unordered_set<int>> ans_mail_ids;
        vector<int> ans_accid;
        
        vector<int> visited = vector<int>(accs.size(), 0);
        function<void(int)> dfs = [&](int acc_id){
            if(visited[acc_id]) return;
            visited[acc_id] = 1;
            vector<int>& mail_ids = accs[acc_id];
            for(int & mail_id: mail_ids) {
                ans_mail_ids.back().insert(mail_id);
            }
            
            for(int &mail_id: mail_ids) {
                vector<int>& acc_ids = mp_mail_to_accid_vec[mail_id];
                for(int &acc_id: acc_ids) dfs(acc_id);
            }
        };
        
        for(int acc_id = 0 ; acc_id<accs.size(); acc_id++) {
            if(visited[acc_id] == 0) {
                ans_accid.push_back(acc_id);
                ans_mail_ids.push_back(unordered_set<int>());
                dfs(acc_id);
            }
        }
        
        //Generate answer from ans_accid and ans_mail_ids;
        //printf("ans_accid.size() = %d, ans_mail_ids.size() = %d,\n",ans_accid.size(), ans_mail_ids.size());        
        int n = ans_accid.size();
        for(int i = 0; i<n;i++) {
            ans.push_back(vector<string>());
            ans[i].push_back(accounts[ans_accid[i]][0]);
            vector<int> mail_v;
            for(auto & mail_id : ans_mail_ids[i]) 
                mail_v.push_back(mail_id);
            sort(mail_v.begin(), mail_v.end(), [&](auto &lhs, auto &rhs) {
                return mp_int_mail[lhs] < mp_int_mail[rhs];
            });
            for(auto & mail_id: mail_v) 
                ans[i].push_back(mp_int_mail[mail_id]);
        }
        
        
        return ans;
    }
};