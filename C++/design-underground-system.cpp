class UndergroundSystem {
public:
    unordered_map<int,vector<pair<int,pair<bool, string>>>> mp; //mp = card_id: logs (vector<pair<int,pair<bool,string>>>)
    //log = vector of {t, {In/Out bool, stationName }}
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id].push_back({t, {true, stationName}});
    }
    
    void checkOut(int id, string stationName, int t) {
        mp[id].push_back({t, {false, stationName}});
    }
    
    double getAverageTime(string startStation, string endStation) {
        int total = 0; 
        long long sum = 0;
        //sorting 
        for(auto& [id,v]: mp) {
            /*
            sort(v.begin(), v.end(), [](auto& lhs, auto& rhs){
                return lhs.first < rhs.first;
            });*/
            
            for(int i = 0; i<v.size(); i+=2) {
                if(i+1>=v.size()) {
                    //cout<<"size over\n";
                    continue;
                }
                if(v[i].second.first == true && v[i+1].second.first == false) {
                    //cout<<"yes case\n";
                } else {
                    //cout<<"no case\n";
                }
                
                if(v[i].second.second == startStation) {
                    if(v[i+1].second.second == endStation) {
                        sum += (long long)(v[i+1].first - v[i].first);
                        total+=1;
                    }
                }
            }
        }
        double avg = (double)sum / (double)total;
        return avg;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */