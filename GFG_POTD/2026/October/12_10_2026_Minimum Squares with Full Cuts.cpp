class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int ans=0;
        while(m>0 && n>0){
            if(n>m){
                ans+=n/m;
                n%=m;
            }
            else{
                ans+=m/n;
                m%=n;
            }
        }
        return ans;
    }
};
