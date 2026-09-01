class Solution {
  public:
    int palindromicStrings(int n, int k) {
        // code here
        int ans=0;
        const int mod=1e9+7;
        
        
        //TC IS n*(n/2)
        for(int len=1;len<=n;len++){
            int x=(len+1)/2;
            
            
            long long pro=1;
            for(int j=0;j<x;j++){
                pro=(pro*(k-j))%mod;
            }
            ans=(ans+pro)%mod;
        }
        return ans;
    }
};
