class Solution {
  public:
    int minimumSum(string &s) {
        // code here
        int i=0,j=s.length()-1;
        
        
        string temp;
        while(i<j){
            //both index have diff char
            if(s[i]!='?' && s[j]!='?' && s[i]!=s[j])return -1;
            
            if(s[i]!='?'){
                temp+=s[i];
            }
            else if(s[j]!='?'){
                temp+=s[j];
            }
            i++;
            j--;
        }
        
        int ans=0;
        int k=1;
        while(k<temp.length()){
            ans+=abs(temp[k]-temp[k-1]);
            k++;
        }
        return 2*ans;
        
    }
};
