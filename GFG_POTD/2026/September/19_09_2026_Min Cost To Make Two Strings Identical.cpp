class Solution {
  public:
  
    vector<vector<int>>dp;
    int func(int i,int j,string &s1, string &s2){
        
        // one of the string over
        if(i<0 || j<0){
            return 0;
        }
        
        //visited state
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i]==s2[j]){
            return dp[i][j]=1+func(i-1,j-1,s1,s2);
        }
        
        
        //delete from i or delete from j
        return dp[i][j]=max(func(i-1,j,s1,s2),func(i,j-1,s1,s2));
    }
  
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        int m=s1.length();
        int n=s2.length();
        dp.assign(m+1,vector<int>(n+1,-1));
        
        int lcs=func(m-1,n-1,s1,s2);
        
        int ans=(m-lcs)*costS1 + (n-lcs)*costS2;
        return ans;
    }
};
