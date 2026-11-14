class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        // code here
        
        map<int,int>m;

        int sum=s1[s1.size()-1];
        m[sum]++;
        
        for(int i=s1.size()-2;i>=0;i--){
            sum+=s1[i];
            m[sum]++;
        }
        
        sum=s2[s2.size()-1];
        m[sum]++;
        
        for(int i=s2.size()-2;i>=0;i--){
            sum+=s2[i];
            m[sum]++;
        }
        
        sum=s3[s3.size()-1];
        m[sum]++;
        
        for(int i=s3.size()-2;i>=0;i--){
            sum+=s3[i];
            m[sum]++;
        }
        
        int ans=0;
        for(auto i:m){
            if(i.second==3){
                ans=i.first;
            }
        }
        return ans;
        
    }
};
