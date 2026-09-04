class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int ans=0,sum=0,l=0,r=0;
        
        int n=arr.size();
        //we find the 1st combination starting from index 0
        // 0,1,2...m-1
        
        //O(M)
        while(r<m){
            sum+=arr[r];
            r++;
        }
        
        // 1,2,....m
        //2,3,..m+1
        ans=sum;
        
        
        //O(N)
        //now we use concept of sliding window
        while(l<n){
            sum+=arr[r%n];
            sum-=arr[l];
            l++;
            r++;
            ans=max(ans,sum);
        }
        return ans;
    }
};
