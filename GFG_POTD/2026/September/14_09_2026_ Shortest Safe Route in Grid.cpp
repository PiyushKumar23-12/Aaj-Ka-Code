class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        
        //m*n
        int m=mat.size();
        int n=mat[0].size();
        
        
        // directions
        // i,j
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        //mn4
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //landmine cell
                
                //neighbours bhi dangerous hai we cannot take it
                if(mat[i][j]==0){
                    for(int k=0;k<4;k++){
                        int ni=i+dx[k];
                        int nj=j+dy[k];
                        
                        if(ni<0 || nj<0 || ni>=m || nj>=n || mat[ni][nj]==0)continue;
                        mat[ni][nj]=-1;
                    }
                }
            }
        }
        
        
        // 0--> landmine pehle se hai
        // 1--> landmine nhi hai uska neighbours mei bhi nhi hai
        //-1 landmine mere paas nhi hai lekin mera neighbours mei hai
        
        //mn
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==-1){
                    mat[i][j]=0;
                }
            }
         }
         
         queue<vector<int>>q;
         vector<vector<int>>dis(m,vector<int>(n,-1));
         
         
        //left most column
        
        //m
        for(int i=0;i<m;i++){
            if(mat[i][0]==1){
                 q.push({i,0});
                 dis[i][0]=1;
            }
        }
        
        
        // bfs mn4
        
        int ans=1e8;
        
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            
            int x=cur[0],y=cur[1];
            //rightmost column
            if(y==n-1){
                ans=min(ans,dis[x][y]);
            }
            
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                        
                if(nx<0 || ny<0 || nx>=m || ny>=n || mat[nx][ny]==0 || dis[nx][ny]!=-1)continue;
                
                q.push({nx,ny});
                dis[nx][ny]=dis[x][y]+1;
            }
        }
        
        if(ans==1e8)return -1;
        return ans;
    }
};
