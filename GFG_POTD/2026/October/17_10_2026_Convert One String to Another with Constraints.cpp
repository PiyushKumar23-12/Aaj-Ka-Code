class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        // code here
        
        int m=s1.length(),n=s2.length();
        
        int i=0,j=0;
        
        while(i<m || j<n){
            
            //skip #
            while(i<m && s1[i]=='#')i++;
            while(j<n && s2[j]=='#')j++;
            
            //any string over
            if(i==m || j==n){
                return i==m && j==n;
            }
            
            //corresponding characters does not match
            if(s1[i]!=s2[j])return false;
            
            //characters match
            
            if(s1[i]=='A' && i<j)return false;
            
            if(s1[i]=='B' && i>j)return false;
            i++;
            j++;
        }
        return true;
    }
};
