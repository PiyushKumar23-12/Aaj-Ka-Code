class Solution {
  public:
    char posInfinite(string &s, int pos) {
        // code here
        int len=s.length();
        int i=1;
        while(len<pos){
            len=2*len+i;
            i++;
        }
        
        i--;
        
        while(pos>s.length()){
            int old=(len-i)/2;
            
            //original string
            if(pos<=old){
                len=old;
            }
            
            //$ section
            else if(pos<=old+i){
                return '$';
            }
            
            //reverse string
            else{
                int reversepos=pos-old-i;
                pos=old-reversepos+1;
                len=old;
            }
            i--;
        }
        
        return s[pos-1];
    }
};
