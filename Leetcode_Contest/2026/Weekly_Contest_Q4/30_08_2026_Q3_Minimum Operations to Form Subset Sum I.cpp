class Solution {
public:

    vector<vector<int>>dp;

    int func(int i,vector<int>& nums, int sum){
        if(sum==0)return 0;
        if(i==nums.size())return 1e8;
        if(dp[i][sum]!=-1)return dp[i][sum];
        int nt=func(i+1,nums,sum);
        int x=nums[i];
        int ans=INT_MAX;
        int v=x;
        int cost=1;
        if(v<=sum){
            int take=func(i+1,nums,sum-v);
            ans=min(ans,take);
        }
        while(v/2>=1){
            v/=2;
            if(v<=sum){
                int res=cost+func(i+1,nums,sum-v);
                ans=min(ans,res);
            }
            cost++;
        }

        v=x;
        cost=1;

        while(2*v<=sum){
            v*=2;
            if(v<=sum){
                int res=cost+func(i+1,nums,sum-v);
                ans=min(ans,res);
            }
            cost++;   
        }
        return  dp[i][sum]=min(ans,nt);
        
    }
    
    int minOperations(vector<int>& nums, int sum) {
        dp.assign(nums.size()+1,vector<int>(sum+1,-1));
        int ans=func(0,nums,sum);
        if(ans==1e8)return -1;
        return ans;
    }
};
