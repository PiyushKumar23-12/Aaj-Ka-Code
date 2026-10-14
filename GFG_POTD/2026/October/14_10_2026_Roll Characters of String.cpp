class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n=s.length();
        vector<int>diff(n+1,0);
        
        for(int i:roll){
            diff[0]++;
            diff[i]--;
        }
        
        for(int i=1;i<=n;i++){
            diff[i]+=diff[i-1];
        }
        
        string ans;
        for(int i=0;i<n;i++){
            char ch=(((s[i]-'a')+diff[i])%26)+'a';
            ans+=ch;
        }
        return ans;
        
    }
};
