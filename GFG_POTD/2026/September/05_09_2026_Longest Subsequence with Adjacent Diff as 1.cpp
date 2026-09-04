class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        
        int ans=0;
        // store previous values
        unordered_map<int,int>m;
        // kon kitna length ka subsequence bana pa rha 
        
        
        //  [10, 9, 4, 5, 4, 8, 6]
        for(int i:arr){
            //for 10 11 9
            int mx=max(m[i+1],m[i-1]);
            
            // m[11]-->0
            // m[9]-->0
            m[i]=mx+1;
            ans=max(ans,m[i]);
        }
        return ans;
    }
};
