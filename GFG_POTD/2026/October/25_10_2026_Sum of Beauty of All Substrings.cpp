class Solution {
  public:
    int beautySum(string &s) {
        // code here
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int freq[26]={0};
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mini=n;
                int maxi=0;
                
                for(int k:freq){
                    if(k>0){
                        mini=min(mini,k);
                        maxi=max(maxi,k);
                    }
                }
                
                if(maxi-mini>0){
                    ans+=maxi-mini;
                }
            }
        }
        return ans;
    }
};
