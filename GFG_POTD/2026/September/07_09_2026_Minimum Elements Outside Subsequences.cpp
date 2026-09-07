class Solution {
  public:
  
    vector<vector<vector<int>>>dp;
    int func(int i,int incLast,int decLast,int n,vector<int>& arr){
        
        //Base Case
        // no more elements left;
        if(i==n)return 0;
        
        if(dp[i][incLast+1][decLast+1]!=-1)return dp[i][incLast+1][decLast+1];
        //not take
        int ans=1+func(i+1,incLast,decLast,n,arr);
        
        //increasing subsequence
        if(incLast==-1 || arr[incLast]<arr[i]){
            ans=min(ans,func(i+1,i,decLast,n,arr));
        }
        
        //increasing subsequence
        if(decLast==-1 || arr[decLast]>arr[i]){
            ans=min(ans,func(i+1,incLast,i,n,arr));
        }
        
        return dp[i][incLast+1][decLast+1]=ans;
        
    }
  
    int minCount(vector<int>& arr) {
        // code here
        int n=arr.size();
        dp.assign(n,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return func(0,-1,-1,n,arr);
        
    }
};
