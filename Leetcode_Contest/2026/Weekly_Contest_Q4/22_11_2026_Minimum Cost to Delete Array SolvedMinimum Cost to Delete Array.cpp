class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        long long ans=nums[0]+nums[n-1];

        vector<int>v;
        for(int i=1;i<n-1;i++){
            v.push_back(nums[i]);
        }

        sort(v.begin(),v.end());

        int i=1;
        while(i<v.size()){
            ans=min(ans,ans+v[i]+v[i-1]);
            i+=2;
        }
        return ans;
    }
};
