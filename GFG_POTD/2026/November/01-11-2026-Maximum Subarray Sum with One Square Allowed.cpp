class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        
        //DP+ kadane
        int ans=-1e3,alsq=-1e3,nosq=-1e3;
        
        for(int i=0;i<arr.size();i++){
            alsq=max({alsq+arr[i],nosq+arr[i]*arr[i],arr[i]*arr[i]});
            
            nosq=max({nosq+arr[i],arr[i]});
            
            ans=max({ans,alsq,nosq});
        }
        
        return ans;
    }
};
