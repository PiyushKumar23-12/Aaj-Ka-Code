class Solution {
  public:
  
    vector<vector<int>>suff;
    
    const int mod=1e9+7;
    
    int dp[201][201][201],dp_below[201][201][201],dp_right[201][201][201];
    
    int next_row[201][201],next_col[201][201];
    
    int n,m;
    
    int solve(int r,int c,int k){
        
        //k-1 cuts
        if(k==1){
            if(suff[r][c]>0)return 1;
            return 0;
        }
        
        
        
        if(dp[r][c][k]!=-1) return dp[r][c][k];
        
        long long ans=0;
        
        
        if(next_row[r][c]<n){
            ans=(ans+sum_below(next_row[r][c],c,k-1))%mod;
        }
        
        if(next_col[r][c]<m){
            ans=(ans+sum_right(r,next_col[r][c],k-1))%mod;
        }
        
        //horizontal cut
        // for(int nr=r+1;nr<n;nr++){
        //     if(suff[nr][c]==suff[r][c]){
        //         continue;
        //     }
        //     ans=(ans+solve(nr,c,k-1))%mod;
        // }
        
        // //vertical cut
        
        // for(int nc=c+1;nc<m;nc++){
        //     if(suff[r][nc]==suff[r][c])continue;
        //     ans=(ans+solve(r,nc,k-1))%mod;
        // }
        
        
        
        return dp[r][c][k]=ans;
    }
    
    int sum_below(int r,int c,int k){
        if(r==n)return 0;
        
        if(dp_below[r][c][k]!=-1)return dp_below[r][c][k];
        
        return dp_below[r][c][k]=(solve(r,c,k)+sum_below(r+1,c,k))%mod;
    }
    
    int sum_right(int r,int c,int k){
        if(c==m)return 0;
        
        if(dp_right[r][c][k]!=-1)return dp_right[r][c][k];
        
        return dp_right[r][c][k]=(solve(r,c,k)+sum_right(r,c+1,k))%mod;
    }
    
    int findWays(vector<vector<int>>& matrix, int k) {
        // code here
        n=matrix.size();
        m=matrix[0].size();
        
        suff.assign(n+1,vector<int>(m+1,0));
        
        // memset(dp,-1,sizeof(dp));
        // memset(dp_below,-1,sizeof(dp));
        // memset(dp_right,-1,sizeof(dp));
        
        // 201*201*201==8*1e6
        // 24e6
        // 4 bytes
        
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int l=0;l<=k;l++){
                    dp[i][j][l]=-1;
                    dp_below[i][j][l]=-1;
                    dp_right[i][j][l]=-1;
                }
            }
        }
        
        
        //suffix matrix -> right side ya down side mei 1 hai ki nhi
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suff[i][j]=matrix[i][j]+suff[i+1][j]+suff[i][j+1]-suff[i+1][j+1];
            }
        }
        
        
        //next valid cut row wise
        for(int c=0;c<m;c++){
            //iske baad no row
            next_row[n-1][c]=n;
            
            for(int i=n-2;i>=0;i--){
                
                if(suff[i+1][c]<suff[i][c]){
                    next_row[i][c]=i+1;
                }
                else{
                    next_row[i][c]=next_row[i+1][c];
                }
            }
        }
        
        //next valid cut col wise
        
        for(int r=0;r<n;r++){
            //iske baad no row
            next_col[r][m-1]=m;
            
            for(int i=m-2;i>=0;i--){
                
                if(suff[r][i+1]<suff[r][i]){
                    next_col[r][i]=i+1;
                }
                else{
                    next_col[r][i]=next_col[r][i+1];
                }
            }
        }
        
        return solve(0,0,k);
        
        
    }
};
