class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        vector<vector<pair<int,int>>>adj(n+1);
        
        
        //create adj matrix
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            //normal edge
            adj[u].push_back({v,0});
            
            //reverse edge
            adj[v].push_back({u,1});
        }
        
        vector<int>dis(n+1,1e9);
        
        //min-heap
        
        //ELogV
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        dis[src]=0;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            
            auto [d,u]=pq.top();
            pq.pop();
            if(d!=dis[u])continue;
            
            for(auto &[v,cost]:adj[u]){
                if(d+cost<dis[v]){
                    dis[v]=d+cost;
                    pq.push({dis[v],v});
                }
            }
            
        }
        
        
        if(dis[dst]==1e9)return -1;
        return dis[dst];
    }
};
