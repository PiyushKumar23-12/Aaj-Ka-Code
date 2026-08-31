class Solution {
  public:
    
    vector<int>dp;
    int func(int n,int i,int d,int c){
        
        // * insertion cost
        if(n==1)return i;
        
        if(dp[n]!=-1)return dp[n];
        
        // we insert all the n characters
        int ans=n*i;
        
        if(n%2==0){
            // best to go to n/2
            ans=min(ans,func(n/2,i,d,c)+c);
        }
        else{
            
            // delete
            ans=min(ans,func(n+1,i,d,c)+d);
            
            //insert
            ans=min(ans,func(n-1,i,d,c)+i);
        }
        return dp[n]=ans;
    }
  
    int minCost(int n, int i, int d, int c) {
        // code here
        
        // n -->1e6 copy  --> 2e6
        dp.assign(2*n,-1);
        return func(n,i,d,c);
    }
};
