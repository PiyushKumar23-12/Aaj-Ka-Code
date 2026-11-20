class Solution {
  public:
    int minFlips(string &s) {
        // code here
        
        int c1=0,c2=0;
        
        
        //010101...
        
        //101010...
        for(int i=0;i<s.length();i++){
            //even 
            if(i%2==0){
                if(s[i]=='0')c2++;
                else{
                    c1++;
                }
            }
            //odd
            else{
                if(s[i]=='0')c1++;
                else{
                    c2++;
                }
            }
            
        }
        
        return min(c1,c2);
        
    }
};
