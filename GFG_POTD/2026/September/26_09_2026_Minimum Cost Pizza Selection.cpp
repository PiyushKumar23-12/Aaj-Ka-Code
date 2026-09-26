class Solution {
  public:
  
  vector<int>dp;
  
  
    int func(int x, int s, int m, int l, int cs, int cm, int cl){
        //base case
        //pizza size atleast x;
        if(x<=0)return 0;
        
        //visited state
        if(dp[x]!=-1)return dp[x];
        int small=cs+func(x-s,s,m,l,cs,cm,cl);
        int medium=cm+func(x-m,s,m,l,cs,cm,cl);
        int large=cl+func(x-l,s,m,l,cs,cm,cl);
        
        return dp[x]=min({small,medium,large});
    }
  
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        dp.assign(x+1,-1);
        return func(x,s,m,l,cs,cm,cl);
    }
};
