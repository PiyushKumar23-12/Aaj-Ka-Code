class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        int n=nums.size();

        vector<int>unset(32,-1),left(n,-1),right(n,n),unset1(32,n);


        for(int i=0;i<n;i++){
            for(int b=0;b<32;b++){
                //current bit b set hai
                if((nums[i]&(1<<b))!=0){
                    left[i]=max(left[i],unset[b]);
                }
                else{
                    unset[b]=i;
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int b=0;b<32;b++){
                //current bit b set hai
                if((nums[i]&(1<<b))!=0){
                    right[i]=min(right[i],unset1[b]);
                }
                else{
                    unset1[b]=i;
                }
            }
        }


        vector<int>nse(n,n),pse(n,-1);
        stack<int>st;

        //PSE
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }

        while(!st.empty())st.pop();

        //NSE
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }


        long long ans=0;

        for(int i=0;i<n;i++){
            int l=max(left[i]+1,pse[i]+1);
            int r=min(right[i]-1,nse[i]-1);

            ans+=1LL*(i-l+1)*(r-i+1);

        }
        return ans;


    }
};
