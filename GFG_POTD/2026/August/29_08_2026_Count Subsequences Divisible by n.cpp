class Solution {
  public:
    
    const int mod=1e9+7;
    
    vector<vector<int>>dp;
    
    int func(int i,int num,string& s, int n){
        
        //base case
        if(i==s.length()){
            return num==0;
        }
        
        if(dp[i][num]!=-1)return dp[i][num];
        
        
        int nt=func(i+1,num,s,n);
        
        int d=s[i]-'0';
        // num=1
        // d=2
        // 12
        // 1*10+2
        int take=func(i+1,(num*10+d)%n,s,n);
        return dp[i][num]=(take+nt)%mod;
    }
  
    int countSubsequences(string& s, int n) {
        // code here
        
        //index num s n
        
        // val=0 
        // 0%n==0
        dp.assign(s.length()+1,vector<int>(n,-1));
        return func(0,0,s,n)-1;
    }
};
