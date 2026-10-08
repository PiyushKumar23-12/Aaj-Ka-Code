class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        // code here
        
        int ans=0;
        int l=0;
        int windowsum=0;
        sort(arr.begin(),arr.end());
        
        for(int r=0;r<arr.size();r++){
            windowsum+=arr[r];
            
            
            //actual sum=arr[r]*(r-l+1)
            while(arr[r]*(r-l+1)-windowsum>k){
                windowsum-=arr[l];
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
