class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        // code here
        
        int n=arr.size();
        
        vector<int>lmax(n+1,INT_MIN),rmax(n+1,INT_MIN),lmin(n+1,INT_MAX),rmin(n+1,INT_MAX);
        
        //left side
        
        for(int i=0;i<n;i++){
            lmax[i+1]=max(lmax[i],arr[i]);
            lmin[i+1]=min(lmin[i],arr[i]);
        }
        
        
        //right side
        
        for(int i=n-1;i>=0;i--){
            rmax[i]=max(rmax[i+1],arr[i]);
            rmin[i]=min(rmin[i+1],arr[i]);
        }
        
        
        int ans=INT_MAX;
        
        for(int i=0;i<=n-k;i++){
            int lt=i,rt=i+k;
            
            //lmin--> 0 se lt 
            // rmin--> rt-->n-1
            int mini=min(lmin[lt],rmin[rt]);
            
            //lmax-->0 se lt tak ka max
            //rmax--> rt-->n-1 tak ka max
            int maxi=max(lmax[lt],rmax[rt]);
            
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};
