DFS

class Solution {
public:

    void dfs(int node, vector<vector<pair<int,int>>>& adj,
             vector<int>& vis, int val, int& cnt) {

        vis[node] = 1;
        cnt++;

        for (auto [v, w] : adj[node]) {
            if (!vis[v] && w <= val) {
                dfs(v, adj, vis, val, cnt);
            }
        }
    }

    vector<int> maximumWeight(int n, vector<vector<int>> edges,
                              vector<int>& queries) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> ans;

        for (int x : queries) {

            vector<int> vis(n + 1, 0);
            long long total = 0;

            for (int i = 1; i <= n; i++) {

                if (!vis[i]) {

                    int cnt = 0;

                    dfs(i, adj, vis, x, cnt);

                    total += 1LL * cnt * (cnt - 1) / 2;
                }
            }

            ans.push_back(total);
        }

        return ans;
    }
};


DSU

class Solution {
  public:
  
    vector<int>par,size;
    
    int findPar(int u){
        if(u==par[u])return u;
        return par[u]=findPar(par[u]);
    }
    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {
        // code here
        par.assign(n+1,0);
        size.assign(n+1,1);
        
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        
        sort(edges.begin(),edges.end(),[](const vector<int>&a,const vector<int>&b){
            return a[2]<b[2];
        });
        
        
        vector<pair<int,int>>q;
        
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        
        sort(q.begin(),q.end());
        
        vector<int>ans(q.size());
        
        
        int j=0;
        for(int i=0;i<q.size();i++){
            int val=q[i].first,idx=q[i].second;
            long long tot=0;
            
            while(j<edges.size() && edges[j][2]<=val){
                int u=edges[j][0],v=edges[j][1];
                
                int pu=findPar(u);
                int pv=findPar(v);
                
                if(pu==pv){
                    j++;
                    continue;
                }
                
                if(size[pu]>=size[pv]){
                    size[pu]+=size[pv];
                    size[pv]=0;
                    par[pv]=pu;
                }
                else{
                    size[pv]+=size[pu];
                    size[pu]=0;
                    par[pu]=pv;
                }
                j++;
            }
            
            for(int i:size){
                tot+=(i*(i-1))/2;
            }
            
            ans[idx]=tot;
        }
        
        return ans;
        
        
    }
};
