class Solution {
public:

    vector<vector<int>>dp;

    int func(int i,vector<int>& nums, int sum,vector<vector<pair<int,int>>>&v){
        // we cannot proceed as sum ==0
        if(sum==0)return 0;

        //invalid combination
        if(i==nums.size())return 1e8;

        if(dp[i][sum]!=-1)return dp[i][sum];
        //we don't take
        int ans=func(i+1,nums,sum,v);


        //what we can take
        //value steps
        for(int j=0;j<v[i].size();j++){
            int val=v[i][j].first,steps=v[i][j].second;
            if(val<=sum){
                int take=steps+func(i+1,nums,sum-val,v);
                ans=min(ans,take);
            }
        }
        return dp[i][sum]=ans;
    }
    
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        vector<vector<pair<int,int>>>poss(n);
        dp.assign(n+1,vector<int>(sum+1,-1));

        //n
        for(int i=0;i<n;i++){
            int v=nums[i];
            //number ---> minsteps
            map<int,int>m;
            int divsteps=0;


            //log v
            while(v>0){
                int cur=v;
                int mulsteps=0;


                // log sum
                while(cur<=sum){
                    int steps=divsteps+mulsteps;
                    if(m.find(cur)==m.end()){
                        m[cur]=steps;
                    }
                    else{
                        m[cur]=min(m[cur],steps);
                    }
                    cur*=2;
                    mulsteps++;
                }

                v/=2;
                divsteps++;
            }


            // for each index we store the number generated and min steps to generate that number
            for(auto j:m){
                poss[i].push_back({j.first,j.second});
            }

            
        }

        //n *sum
        int ans=func(0,nums,sum,poss);
        if(ans==1e8)return -1;
        return ans;
    }
};
