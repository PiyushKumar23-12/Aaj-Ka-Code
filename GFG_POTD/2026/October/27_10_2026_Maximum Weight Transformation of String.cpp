class Solution {
  public:
  
    vector<int>dp;
  
    int func(int i,string &s){
        if(i>=s.length())return 0;
        
        if(dp[i]!=-1)return dp[i];
        //single element
        int ans=1+func(i+1,s);
        
        
        //pair
        if(i+1<s.length()){
            int wt=(s[i]!=s[i+1])?4:3;
            ans=max(ans,wt+func(i+2,s));
        }
        return dp[i]=ans;
    }
  
    int getMaxWeight(string &s) {
        // code here
        dp.assign(s.length()+1,-1);
        return func(0,s);
    }
};
