class Solution {
  public:
  
    vector<vector<int>>dp;
    
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    
    
    int func(int i,int j,vector<vector<int>> &mat){
        if(dp[i][j]!=-1)return dp[i][j];
        
        int res=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            
            if(ni<0 || nj<0 || ni>=mat.size() || nj>=mat[0].size())continue;
            
            if(mat[ni][nj]>mat[i][j]){
                res=max(res,1+func(ni,nj,mat));
            }
        }
        dp[i][j]=res;
        return res;
    }
    
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        // code here
        
        dp.assign(n,vector<int>(m,-1));
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                    ans=max(ans,func(i,j,matrix));
                }
            }
        }
        
        return ans;
        
    }
};
