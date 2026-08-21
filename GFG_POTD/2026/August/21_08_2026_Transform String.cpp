class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        
        //anagram check
        
        //Case 1
        vector<int>freq(256,0);
        
        //n
        for(char ch:s1){
            freq[ch]++;
        }
        
        //n
        for(char ch:s2){
            freq[ch]--;
        }
        
        //256
        for(int i:freq){
            if(i)return -1;
        }
        
        //case 2
        
        int i=s1.length()-1,j=s2.length()-1;
        
        int ans=0;
        
        
        //n
        while(i>=0 && j>=0){
            if(s1[i]==s2[j]){
                i--;j--;
            }
            else{
                i--;
                ans++;
            }
        }
        return ans;
    }
};
