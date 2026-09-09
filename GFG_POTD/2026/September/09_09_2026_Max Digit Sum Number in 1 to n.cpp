class Solution {
  public:
    int findMax(int n) {
        // code Here
        
        // n=48
        // s="48"
        string s=to_string(n);
        
        int ans=n;
        int sum=0;
        
        //y
        for(char ch:s){
            sum+=ch-'0';
        }
        
        //ans=48
        //sum=12
        
        //48
        //y
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')continue;
            
            
            //48
            string t=s;
            
            //38
            t[i]--;
            
            
            //"39"
            
            //y
            for(int j=i+1;j<t.length();j++){
                t[j]='9';
            }
            
            int csum=0;
            //y
            for(char ch:t){
                csum+=ch-'0';
            }
            
            // sum=12
            
            int x=stoi(t);
            // x=39
            
            if(csum>sum || (csum==sum && x>ans)){
                ans=x;
                sum=csum;
            }
            
        }
        //y^2 approach
        // y max value =9
        return ans;
    }
};
