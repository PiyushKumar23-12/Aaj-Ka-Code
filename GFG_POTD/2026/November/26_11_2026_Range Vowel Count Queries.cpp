class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here
        
        unordered_set<char>st{'a','e','i','o','u'};
        
        int n=s.length();
        vector<int>pre(n,0);
        
        
        for(int i=0;i<n;i++){
            //vowel hai
            if(st.find(s[i])!=st.end()){
                pre[i]=1;
            }
            
            if(i>0){
                pre[i]+=pre[i-1];
            }
        }
        
        
        vector<int>ans;
        
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0],r=queries[i][1];
            
            int ct=pre[r];
            if(l>0){
                ct-=pre[l-1];
            }
            ans.push_back(ct);
        }
        return ans;
        
    }
};
