class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int n=arr.size();
        
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        
        if(n<=totalTime){
            return arr[n-1];
        }
        
        int ans=0;
        
        for(int i=0;i<=n-totalTime;i++){
            int r=arr[i+totalTime-1];
            int l=(i>0)?arr[i-1]:0;
            ans=max(ans,r-l);
        }
        return ans;
    }
};
