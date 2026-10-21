class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int csum=1e8;
        int ans=1e8;
        
        for(int i=0;i<n;i++){
            csum=min(csum+arr[i],arr[i]);
            ans=min(ans,csum);
        }
        return ans;
    }
};
