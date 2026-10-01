class Solution {
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        // code here
        int n=duration.size();
        vector<int>indegree(n,0),time(n,0);
        
        vector<int>order;
        int ans=0;
        
        queue<int>q;
        
        
        vector<vector<int>>adj(n);
        for(int i=0;i<dependencies.size();i++){
            int u=dependencies[i][0],v=dependencies[i][1];
            
            //directed edge
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                time[i]=duration[i];
            }
        }
        
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            order.push_back(x);
            ans=max(ans,time[x]);
            
            
            for(auto it:adj[x]){
                time[it]=max(time[it],time[x]+duration[it]);
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        
        if(order.size()!=n)return -1;
        return ans;
    }
};
