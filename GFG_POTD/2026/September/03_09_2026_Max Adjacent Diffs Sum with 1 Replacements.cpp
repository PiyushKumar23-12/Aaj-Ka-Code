class Solution {
  public:
  
  
    vector<vector<int>>dp;
      
  
    int func(int i,vector<int>& arr,int prev){
        // we have traversed each element
        if(i==arr.size())return 0;
        
        if(dp[i][prev]!=-1)return dp[i][prev];
        
        int x=1;
        if(prev==0){
            x=arr[i-1];
        }
        
        int takevalue=abs(arr[i]-x)+func(i+1,arr,0);
        
        int takeone=abs(1-x)+func(i+1,arr,1);
        
        return dp[i][prev]=max(takevalue,takeone);
    }
  
    int maxDiffSum(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        dp.assign(n+1,vector<int>(2,-1));
        
        
        //TC 2n
        
        // Sc is 2n
        
        // handle case 0 
        return max(func(1,arr,0),func(1,arr,1));
        
    }
};
