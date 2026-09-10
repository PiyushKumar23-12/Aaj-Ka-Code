class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
        
        //lcm must be a multiple of gcd
        if(y%x!=0)return 0;
        
        
        long long pro=1LL*x*y;
        
        long long ans=0;
        
        // we will traverse all possible values jo a ka ho sakta hai
        
        //O(y-a)*log func
        for(long long a=x;a<=y;a++){
            if(pro%a==0){
                long long b=pro/a;
                if(gcd(a,b)==x){
                    ans++;
                }
            }
        }
        return ans;
    }
};
