class Solution {
  public:
    int countBT(int h) {
        // code here
        const int mod=1e9+7;
        
        long long a=1,b=1;
        
        for(int i=2;i<=h;i++){
            long long c=(a*b+b*a+b*b)%mod;
            a=b;
            b=c;
        }
        return b;
    }
};
