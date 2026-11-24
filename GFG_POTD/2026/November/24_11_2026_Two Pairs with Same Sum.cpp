class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        unordered_map<long long,pair<int,int>>m;
        
        vector<int>ans(4,-1);
        
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long sum=arr[i]+arr[j];
                if(m.find(sum)==m.end()){
                    m[sum]={i,j};
                }
                else{
                    auto [a,b]=m[sum];
                    if(a!=i && a!=j && b!=i && b!=j){
                        vector<int>temp={a,b,i,j};
                        if(ans[0]==-1 || temp<ans){
                            ans=temp;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
