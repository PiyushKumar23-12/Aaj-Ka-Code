//MEMOIZATION
class Solution {
  public:
  
    vector<vector<int>> dp;

    int func(int i,vector<vector<int>>& mat,int last){
        if(i==mat.size())return 0;
        
        
        if (dp[i][last + 1] != -1)
            return dp[i][last + 1];
        int ans=INT_MAX;
        for(int j=0;j<=2;j++){
            if(last!=j){
                int res=mat[i][j]+func(i+1,mat,j);
                ans=min(ans,res);
            }
        }
        return dp[i][last + 1]=ans;
    }
  
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        dp.assign(n, vector<int>(4, -1));
        return func(0,mat,-1);
    }
};

//TABULATION
int minCost(vector<vector<int>>& mat) {
        int n = mat.size();

        dp.assign(n + 1, vector<int>(4, 0));

        for (int day = n - 1; day >= 0; day--) {

            for (int last = -1; last <= 2; last++) {

                int ans = INT_MAX;

                for (int choice = 0; choice < 3; choice++) {

                    if (choice != last) {

                        ans = min(ans,
                            mat[day][choice] +
                            dp[day + 1][choice + 1]);
                    }
                }

                dp[day][last + 1] = ans;
            }
        }

        return dp[0][0];
    }


//SPACE OPTIMIZATION
int minCost(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        //prev day ka store
        // n ka values ko store kar raha hai
        vector<int>dp(4,0);
        
        
        
        // base case already covered
        // dp.assign(n+1,vector<int>(4,0));
        
        //loop in reverse direction
        
        //n *4*3=12n
        // Sc is n*4
        
        //space Optimization
        //tabulation code
        
        // 4
        
        // for a current day we only require day+1 ka value
        for(int day=n-1;day>=0;day--){
            //n-1 ka store karega
            vector<int>curr(4,0);
            // column order no significant
            for(int last=-1;last<=2;last++){
                int ans=INT_MAX;
                for(int i=0;i<=2;i++){
                //last --> 1st 
                // j!=1st
                    if(last!=i){
                        //we take ith shop so for next day it becomes last
                        //0 wala 1index
                        // i+1
                        
                        
                        int res=mat[day][i]+dp[i+1];
                        ans=min(ans,res);
                    }
                }
                curr[last+1]=ans;
            }
            //we will update our dp
            
            // n-2 uske liye day+1 n-1
            dp=curr;
        }
        
        return dp[0];
        // return func(0,mat,-1);
    }
