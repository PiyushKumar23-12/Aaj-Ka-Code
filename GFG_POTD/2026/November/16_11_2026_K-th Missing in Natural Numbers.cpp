class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        // code here
        
        sort(arr.begin(),arr.end());
        
        
        int l=0,h=arr.size()-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            int given=arr[mid];
            int expected=mid+1;
            
            int missing=given-expected;
            if(missing>=k){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return l+k;
        
    }
};
