class Solution {
  public:
    int sameMod(vector<int> &arr) {
        // code here
        set<int>st;
        
        for(int i:arr){
            st.insert(i);
        }
        
        // when all values equal
        if(st.size()==1)return -1;
        
        
        int n=arr.size();
        
        //we converted the array
        for(int i=1;i<n;i++){
            arr[i]=abs(arr[i]-arr[0]);
        }
        
        
        // we will find gcd
        // maximum k 
        
        int gc=arr[1];
        for(int i=2;i<n;i++){
            gc=gcd(gc,arr[i]);
        }
        
        // uska factors bhi hoga
        int ans=0;
        for(int i=1;i<=gc;i++){
            if(gc%i==0)ans++;
        }
        return ans;        
       
        
    }
};
