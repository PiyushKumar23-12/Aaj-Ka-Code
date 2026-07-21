class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n=s.length();
        vector<int>best(26,-1);
        
        
        int ans=-1;
        
        for(int i=n-1;i>=0;i--){
            
            //char --> a
            // ind -->0 
            // ch-'a'
            int c=s[i]-'a';
            
            int reach;
            
            
            //cuur char-->z
            if(c==25){
                reach=i;
            }
            
            
            //d -->e
            else if(best[c+1]!=-1){
                reach=best[c+1];
            }
            
            else{
                reach=i;
            }
            
            best[c]=max(best[c],reach);
            
            
            //char a
            if(c==0){
                ans=max(ans,reach-i);
            }
        }
        return ans;
    }
};
