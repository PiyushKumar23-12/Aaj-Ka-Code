class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int dx[8]={2,2,-2,-2,1,1,-1,-1};
        int dy[8]={1,-1,1,-1,2,-2,2,-2};
        
        
        //x,y
        queue<pair<int,int>>q;
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<vector<int>>dis(n,vector<int>(n,0));
        
        //0 based indexing
        knightPos[0]--;
        knightPos[1]--;
        
        targetPos[0]--;
        targetPos[1]--;
        
        
        q.push({knightPos[0],knightPos[1]});
        vis[knightPos[0]][knightPos[1]]=1;
        dis[knightPos[0]][knightPos[1]]=0;
        
        
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            
            int x=curr.first,y=curr.second;
            
            if(x==targetPos[0] && y==targetPos[1])return dis[x][y];
            
            
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx<0 || nx>=n || ny<0 || ny>=n || vis[nx][ny])continue;
                
                vis[nx][ny]=1;
                q.push({nx,ny});
                dis[nx][ny]=dis[x][y]+1;
                
            }
            
        }
        return 0;
    }
};
