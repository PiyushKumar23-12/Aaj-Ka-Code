class Solution {
  public:
  
    const int mod=1e9+7;
    
    vector<long long>dp;
    
    long long func(int h){
        if(h<=1)return 1;
        
        if(dp[h]!=-1)return dp[h];
        
        long long a=func(h-1)%mod;
        
        long long b=func(h-2)%mod;
        
        long long c=((2*a)%mod*b+a*a)%mod;
        return dp[h]=c;
    }
  
    int countBT(int h) {
        // code here
        dp.assign(h+1,-1);
        return func(h);
    }
};
