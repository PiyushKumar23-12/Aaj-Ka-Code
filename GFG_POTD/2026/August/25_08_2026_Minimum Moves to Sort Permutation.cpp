class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        
        //precompute
        vector<int>pos(n+1);
        
        for(int i=0;i<n;i++){
            pos[arr[i]]=i;
        }
        
        
        int maxi=1;
        
        for(int i=1;i<=n;i++){
            // i--> starting point
            int len=1;
            
            //pos[2]>pos[1]
            //2 must be on right side of 1
            while(i+len<=n && pos[i+len]>pos[i+len-1]){
                len++;
            }
            
            maxi=max(maxi,len);
        }
        return n-maxi;
    }
};



class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        vector<int>dp(n+1);
           
        int maxi=1;        
        
        //we traverse our array
        for(int x:arr){
            //dp[2]=dp[1]+1;
            dp[x]=dp[x-1]+1;
            maxi=max(maxi,dp[x]);
        }
        return n-maxi;
    }
};
