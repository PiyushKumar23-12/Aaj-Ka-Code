class Solution {
  public:
    int subsequenceSum(string &s) {
        // code here
        
        const int mod=1e9+7;
        
        long long sum=0;
        for(char ch:s){
            sum+=ch-'0';
        }
        
        long long power=1;
        for(int i=1;i<=s.length()-1;i++){
            power=(power*2LL)%mod;
        }
        
        return (power*sum)%mod;
        
    }
};
