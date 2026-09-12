Q1.
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans=0;
        map<int,vector<int>>m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }


        for(auto i:m){
            if(i.second.size()==3){
                if(i.second[1]-i.second[0]==i.second[2]-i.second[1])ans++;
            }
        }
        return ans;
    }
};


Q2.
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans=0;
        map<int,vector<int>>m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }


        for(auto i:m){

            //atleast 3 times
            if(i.second.size()>=3){
                set<int>st;
                for(int j=0;j<i.second.size()-1;j++){
                    st.insert(i.second[j+1]-i.second[j]);
                }
                if(st.size()==1)ans++;
            }
        }
        return ans;
    }
};


Q3.
class Solution {
public:

    vector<int>dp;

    int func(int n){

        // after exactly n days
        if(n==0){
            return 0;
        }


        //visited already
        if(dp[n]!=-1)return dp[n];


        int ans=1e8;

        //n =12
        // len=4
        // 1,2,3,4
        for(int len=1;(len*(len+1))/2<=n;len++){
            int points=(len*(len+1))/2;//sum of 1st n numbers 
            ans=min(ans,func(n-points)+len+1);
        }

        // finally stored
        return dp[n]=ans;
    }

    int minDays(int n) {
        dp.assign(n+1,-1);
        return func(n)-1;
    }
};



Q4.
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


//key --> pair<long long,long long>
//value --> nulltype
typedef tree<pair<long long,long long>,null_type,less<pair<long long,long long>>,
rb_tree_tag,tree_order_statistics_node_update>ordered_set;

class Solution {
public:
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        long long first=goal-k;
        long long second=goal+k;

        long long n=nums.size();

        if(k==0){
            // total subarrays
            return (1LL*n*(n+1))/2;
        }

        long long ans=0,csum=0;

        // multiset<long long>st;
        ordered_set st;
        st.insert({0,0});

        //n times
        int i=0;
        for(int x:nums){
            csum+=x;
            long long t1=csum-first;
            long long t2=csum-second;

            long long less=st.order_of_key({t1,-1});
            // less all values jo <t1 <=t1-1

            ans+=st.size()-less;

            // ans+=distance(st.lower_bound(t1),st.end());

            // ans+=distance(st.begin(),st.upper_bound(t2));

            ans+=st.order_of_key({t2,LLONG_MAX});

            st.insert({csum,i+1});
            i++;
        }
        return ans;

    }
};
