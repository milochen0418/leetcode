class Solution {
public:

    int maxConsecutive(int bottom, int top, vector<int>& special) {
        vector<int>& v = special;
        v.push_back(bottom-1);
        v.push_back(top+1);
        sort(v.begin(), v.end());
        int n = v.size();
        int max_v = 0;
        cout<<v[0]<<" ";
        for(int i = 1 ; i<n;i++) {
            cout<<v[i]<<" ";
            max_v = max(max_v, v[i]-v[i-1]-1);
        }
        cout<<"\n";
        return max_v;
        
    }
    int maxConsecutiveUnorderedSet(int bottom, int top, vector<int>& special) {
        unordered_set<int> ss; //all special
        for(auto&i :special ) ss.insert(i);
        int max_cnt = 0;
        int cnt = 0;
        int i ;
        for(i = bottom; i<=top;i++) {
            //cout<<"i="<<i<<" ";
            if(ss.find(i)==ss.end()) {
                cnt++;
                //cout<<"cnt++->cnt="<<cnt<<"\n";
            } else {
                //printf("max_cnt = max(max_cnt=%d, cnt=%d) -> ");
                max_cnt = max(max_cnt,cnt);
                cnt = 0;
                //cout<<"max_cnt="<<max_cnt<<"\n";   
            }
        }
        if(cnt!=0) max_cnt = max(max_cnt,cnt);
        return max_cnt;
    }
};