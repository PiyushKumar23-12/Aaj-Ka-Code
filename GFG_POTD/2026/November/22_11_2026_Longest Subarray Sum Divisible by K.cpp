class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
        
        unordered_map<int,int>m;
        
        m[0]=-1;
        
        int ans=0;
        int sum=0;
        
        for(int i=0;i<arr.size();i++){
            sum=((sum+arr[i])%k+k)%k;
            
            if(m.find(sum)!=m.end()){
                ans=max(ans,i-m[sum]);
            }
            else{
                m[sum]=i;
            }
        }
        
        return ans;
    }
};
