class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>dis(V,0);
        
        
        //TC IS VE 
        
        // SC IS V
        
        //V-1 iterations
        for(int i=0;i<V;i++){
            for(int j=0;j<edges.size();j++){
                int u=edges[j][0],v=edges[j][1],w=edges[j][2];
                
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                }
            }
        }
        
        
        //-ve cycle check
        for(int j=0;j<edges.size();j++){
                int u=edges[j][0],v=edges[j][1],w=edges[j][2];
                
                if(dis[v]>dis[u]+w){
                    //we can still reduce distance
                    
                    return true;
                    // dis[v]=dis[u]+w;
                }
            }
            return false;
    }
};
