class Solution {
  public:
    int solve(int n, string s) {
        // code here
        
        // used to check whether hum computer assign kiye hai
        vector<bool>avail(26,0);
        
        // used to check whether hum computer assign nhi kiye hai
        vector<bool>denied(26,0);
        
        
        int ans=0;
        
        int occupied=0;
        
        
        
        // O(slength)
        for(char ch:s){
            
            int id=ch-'A';
            
            
            
            if(denied[id])continue;
            
            
            // we are visit for the 1st time
            if(!avail[id]){
                
                //we can assign computer
                if(occupied<n){
                    avail[id]=1;
                    occupied++;
                }
                // we cannot assign
                else{
                    denied[id]=1;
                    ans++;
                }
            }
            
            
            //avail[id]=1
            
            
            else{
                occupied--;
                avail[id]=0;
            }
            
            
        }
        
        return ans;
        
        
        
        
        
    }
};
