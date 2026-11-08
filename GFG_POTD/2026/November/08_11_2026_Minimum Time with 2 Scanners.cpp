class Solution {
  public:
    int minTime(int n, int s1, int s2) {
        // code here
        
        int l=0;
        int h=n*max(s1,s2);
        
        int ans=h;
        while(l<=h){
            int mid=l+(h-l)/2;
            
            int cnt=mid/s1+mid/s2;
            
            if(cnt>=n){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
    }
};
