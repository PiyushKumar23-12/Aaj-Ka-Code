class Solution {
  public:
  
    vector<vector<int>>suff;
    
    const int mod=1e9+7;
    
    int dp[201][201][201];
    
    int n,m;
    
    int solve(int r,int c,int k){
        
        //k-1 cuts
        if(k==1){
            if(suff[r][c]>0)return 1;
            return 0;
        }
        
        if(dp[r][c][k]!=-1) return dp[r][c][k];
        
        long long ans=0;
        
        
        //horizontal cut
        for(int nr=r+1;nr<n;nr++){
            if(suff[nr][c]==suff[r][c]){
                continue;
            }
            ans=(ans+solve(nr,c,k-1))%mod;
        }
        
        //vertical cut
        
        for(int nc=c+1;nc<m;nc++){
            if(suff[r][nc]==suff[r][c])continue;
            ans=(ans+solve(r,nc,k-1))%mod;
        }
        
        return dp[r][c][k]=ans;
    }
    
    int findWays(vector<vector<int>>& matrix, int k) {
        // code here
        n=matrix.size();
        m=matrix[0].size();
        
        suff.assign(n+1,vector<int>(m+1,0));
        
        memset(dp,-1,sizeof(dp));
        
        
        //suffix matrix -> right side ya down side mei 1 hai ki nhi
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suff[i][j]=matrix[i][j]+suff[i+1][j]+suff[i][j+1]-suff[i+1][j+1];
            }
        }
        
        return solve(0,0,k);
        
        
    }
};
