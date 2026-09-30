class Solution {
  public:
  
    const int mod=1e9+7;
    
    vector<vector<int>>dp;
    
    int func(int x,int y){
        //we have crossed origin
        if(x<0 || y<0)return 0;
        
        
        //origin reached
        if(x==0 && y==0)return 1;
        
        
        if(dp[x][y]!=-1)return dp[x][y];
        
        //recurrence
        return dp[x][y]=(func(x-1,y)+func(x,y-1))%mod;
    }
  
    int ways(int x, int y) {
        // code here
        dp.assign(x+1,vector<int>(y+1,-1));
        
        //TC is xy SC is xy
        return func(x,y);
    }
};
