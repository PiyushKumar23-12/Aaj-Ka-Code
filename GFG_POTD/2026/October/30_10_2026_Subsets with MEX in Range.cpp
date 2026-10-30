class Solution {
  public:
  
  const int mod=1e9+7;
  
    long long power(long long a,long long b){
        long long res=1;
        while(b>0){
            if(b%2){
                res=(res*a)%mod;
            }
            b/=2;
            a=(a*a)%mod;
        }
        return res;
    }
  
    int cntSubsets(vector<int> &arr, int l, int r) {
        // code here
        
        map<long long,long long>m;
        
        for(int i:arr){
            m[i]++;
        }
        
        int n=arr.size();
        
        long long ans=0;
        
        long long pre=1;
        long long c=0;
        
        
        for(int i=0;i<=r;i++){
            // value l se r ke beech mei hai
            if(i>=l){
                long long rem=n-c-m[i];
                long long ways=(pre*power(2LL,rem))%mod;
                ans=(ans+ways)%mod;
            }
            
            if(m[i]==0)break;
            
            pre=(pre*(power(2LL,m[i])-1+mod))%mod;
            c+=m[i];
        }
        
        return ans;
        
    }
};
