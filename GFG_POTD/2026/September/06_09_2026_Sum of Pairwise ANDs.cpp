class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        vector<long long>v(31,0);
        
        
        //n*31
        
        // kon kon sa bit ko kitna numbers contribute kar raha
        for(int i:arr){
            long long c=0;
            long long j=i;
            while(j>0){
                int d=j%2;
                if(d){
                    v[c]++;
                }
                c++;
                j/=2;
            }
        }
        
        long long ans=0;
        
        for(int i=0;i<31;i++){
            long long n=v[i];
            long long pairs=(n*(n-1))/2;
            
            // 1<<i
            ans+=(1<<i)*pairs;
        }
        return ans;
    }
};
