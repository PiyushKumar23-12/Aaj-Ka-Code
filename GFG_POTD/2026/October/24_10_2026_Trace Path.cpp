class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        // code here
        int l=0,d=0;
        
        int minl=0,maxr=0;
        int minu=0,maxd=0;
        
        
        for(char ch:s){
            if(ch=='L'){
                l++;
            }
            else if(ch=='R')l--;
            
            else if(ch=='D')d++;
            else{
                d--;
            }
            
            minl=min(minl,l);
            maxr=max(maxr,l);
            
            minu=min(minu,d);
            maxd=max(maxd,d);
        }
        
        return (maxr-minl<m && maxd-minu<n);
    }
};
