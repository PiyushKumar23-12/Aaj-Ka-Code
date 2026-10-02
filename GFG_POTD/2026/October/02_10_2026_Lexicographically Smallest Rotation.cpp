class Solution {
  public:
    string lexiString(string &s) {
        // code here
        int n=s.length();
        int i=0,j=1,k=0;
        string t=s+s;
        
        
        //O(n)
        
        //Booth algo 
        while(i<n && j<n && k<n){
            if(t[i+k]==t[j+k]){
                k++;
                continue;
            }
            
            if(t[i+k]>t[j+k]){
                i=i+k+1;
            }
            else {
                j=j+k+1;
            }
            
            if(i==j){
                j++;
            }
            k=0;
        }
        //i index jisse min string aayega
        return t.substr(i,n);
        
    }
};
