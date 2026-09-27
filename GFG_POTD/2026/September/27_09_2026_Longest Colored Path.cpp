class Solution {
  public:
  
    vector<vector<int>>adj;
    
    vector<int>left,right;
    vector<int>vis;
    
    
    int dfs(int node,int par,string &s,char ch,vector<int>&temp){
        
        // sabse dur wala 
        int far=node;
        for(int v:adj[node]){
            if(v==par || s[v]!=ch)continue;
            
            //child 
            temp[v]=temp[node]+1;
            
            int nt=dfs(v,node,s,ch,temp);
            
            if(temp[nt]>temp[far]){
                far=nt;
            }
        }
        return far;
    }
    
    
  
    int longestPath(string& s, vector<vector<int>>& edges) {
        // code here
        
        //tree create
        
        int n=s.length();
        adj.resize(n,{});
        left.assign(n,0);
        right.assign(n,0);
        vis.assign(n,0);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        //we will now find components
        
        for(int i=0;i<n;i++){
            
            //yeh node pehle hi koi component ka part hai
            if(vis[i])continue;
            
            char ch=s[i];
            
            vector<int>comp;
            stack<int>st;
            st.push(i);
            vis[i]=1;
            
            //dfs call to find component
            while(!st.empty()){
                int u=st.top();
                st.pop();
                
                comp.push_back(u);
                for(int v:adj[u]){
                    //not visited and same color
                    if(!vis[v] && s[v]==ch){
                        vis[v]=1;
                        st.push(v);
                    }
                }
                
            }
            
            int val=comp[0];
            //first=9
            
            
            //extreme end
            int first=dfs(val,-1,s,ch,left);
            for(int u:comp){
                left[u]=0;
            }
            
            //distance of each node from starting
            
            int second=dfs(first,-1,s,ch,left);
            
            for(int u:comp){
                right[u]=0;
            }
            
            //1 cheez
            
            dfs(second,-1,s,ch,right);
 
        }
        
        
        int ans=1;
        
        for(int u=0;u<n;u++){
            //only 1 color
            
            ans=max(ans,max(left[u],right[u])+1);
            
            //2 colors
            
            for(int v:adj[u]){
                if(s[u]!=s[v]){
                    int a=max(left[u],right[u])+1;
                    int b=max(left[v],right[v])+1;
                    ans=max(ans,a+b);
                }
            }
        }
        return ans;
        
    }
};
