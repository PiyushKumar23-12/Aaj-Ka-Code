class Solution {
  public:
  
    const int mod=1e9+7;
    int prefixStrings(int n) {
        // code here
        
        vector<long long>dp(n+1,0);
        
        // "" 10
        dp[0]=1,dp[1]=1;
        
        
        //2 3 4 ... n
        
        for(int i=2;i<=n;i++){
            
            // i=3 
            // k=1 2 3
            
            
            
            for(int k=1;k<=i;k++){
                dp[i]=(dp[i]+dp[k-1]*dp[i-k])%mod;
            }
        }
        return dp[n];
        
    }
};
