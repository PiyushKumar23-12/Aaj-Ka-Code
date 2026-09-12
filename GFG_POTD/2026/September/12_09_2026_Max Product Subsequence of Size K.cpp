class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        // code here
        
        //nlogn
        sort(arr.begin(),arr.end());
        int ans=INT_MIN;
        
        int n=arr.size();
        // 0 2 4
        //k*k
        for(int x=0;x<=k;x+=2){
            int rt=k-x;
            
            int pro=1;
            
            //1st x elements from left
            for(int i=0;i<x;i++){
                pro=pro*arr[i];
            }
            
            //1st rt elements from right
            for(int i=0;i<rt;i++){
                pro=pro*arr[n-1-i];
            }
            
            ans=max(ans,pro);
        }
        return ans;
    }
};
