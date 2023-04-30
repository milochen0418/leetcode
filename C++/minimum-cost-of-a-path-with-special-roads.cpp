class Solution {
    //https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/
public:
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);

            if (hash1 != hash2) {
                return hash1 ^ hash2;             
            }

            // If hash1 == hash2, their XOR is zero.
              return hash1;
        }
    };    
    typedef long long ll;
    
    int total_size = 0;
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        /*
        
        start, target, sepcialRoads 裡面有的點點都變成 graph vertex set 
        0, 1, ..... n-1
        vertex set   
        mp_vc[0] = (startX, startY)
        mp_vc[1] = (targetX, targetY)
        mp_vc[2] = (roadiX, roadiY)
        
        
        edge set
        
        edges[n][n]
        start dijkstra algorithm, 
        start, target
        */
        int vcnt=0;    
        unordered_map<int,pair<int,int>> mp_vc;//vertex integer to xy-coordinator
        unordered_map<pair<int,int>,int,hash_pair> mp_cv;//xy-coordinator to vertex integer 
        
        
        pair<int,int> spair = make_pair(start[0],start[1]);
        pair<int,int> tpair = make_pair(start[0],start[1]);
        if(spair==tpair) return 0;
        mp_cv[spair] = vcnt++;
        mp_vc[vcnt-1] = spair;
        
        mp_cv[tpair] = vcnt++;
        mp_vc[vcnt-1] = tpair;
        
        for(auto &r: specialRoads) {
            pair<int,int> p1 = make_pair(r[0],r[1]);
            if(mp_cv.find(p1) == mp_cv.end()) {
                mp_cv[p1] = vcnt++;
                mp_vc[vcnt-1]=p1;
            }
            
            pair<int,int> p2 = make_pair(r[2],r[3]);
            if(mp_cv.find(p2) == mp_cv.end()) {
                mp_cv[p2] = vcnt++;
                mp_vc[vcnt-1]=p2;
            }
        }
        //So vertext set is [0..vcnt-1]
        
        int n = vcnt;
        total_size = n;
        vector<vector<ll>> edges = vector<vector<ll>>(n, vector<ll>(n,0));
        
        for(int i = 0; i<n;i++) {
            for(int j = 0; j<n;j++) {
                if(i==j) {
                    edges[i][j] = 0;
                    continue;
                }
                edges[i][j] = abs(mp_vc[i].first - mp_vc[j].first) + abs(mp_vc[i].second - mp_vc[j].second);
            }
        }
        for(auto &r: specialRoads) {
            pair<int,int> p1 = make_pair(r[0],r[1]);
            pair<int,int> p2 = make_pair(r[2],r[3]);
            int v1 = mp_cv[p1];
            int v2 = mp_cv[p2];
            ll dist = abs(r[0]-r[2]) + abs(r[1]-r[3]);
            if(dist<edges[v1][v2] ) edges[v1][v2] = dist;
        }
        
        
        
        ll ans = dijkstra(edges, 0);
        
        return (int)ans;
        
    }
    
    ll dijkstra(vector<vector<ll>>& graph , int src) {
        int V = graph.size();

                
       ll dist[V]; // The output array.  dist[i] will hold the shortest
        // distance from src to i

        bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
        // path tree or shortest distance from src to i is finalized

        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        // Distance of source vertex from itself is always 0
        dist[src] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < V - 1; count++) {
            // Pick the minimum distance vertex from the set of vertices not
            // yet processed. u is always equal to src in the first iteration.
            ll u = minDistance(dist, sptSet);

            // Mark the picked vertex as processed
            sptSet[u] = true;

            // Update dist value of the adjacent vertices of the picked vertex.
            for (int v = 0; v < V; v++)

                // Update dist[v] only if is not in sptSet, there is an edge from
                // u to v, and total weight of path from src to  v through u is
                // smaller than current value of dist[v]
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }

        // print the constructed distance array
        return dist[1];        
    }
    
    ll minDistance(ll dist[], bool sptSet[])
    {
        //int V = dist.size(); total_size
        int V = total_size;
        // Initialize min value
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }    
};