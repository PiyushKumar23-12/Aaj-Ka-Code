class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        vector<int>pre(n,0),suff(n,0);
        
        pre[0]=arr[0];
        
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],arr[i]);
        }
        
        suff[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            suff[i]=min(suff[i+1],arr[i]);
        }
        
        int c=0;
        
        
        for(int i=0;i<n;i++){
            bool l=1,r=1;
            
            if(i>0 && pre[i-1]>arr[i])l=0;
            if(i+1<n && suff[i+1]<arr[i])r=0;
            
            if(l && r)c++;
        }
        return c;
        
    }
};
