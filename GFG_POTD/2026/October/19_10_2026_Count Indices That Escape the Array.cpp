class Solution {
  public:
  
    bool func(int i,vector<int> &arr,vector<int> &vis,vector<int> &good){
        int n=arr.size();
        
        // array se bahar aa gaye
        if(i<0 || i>=n)return true;
        
        //current path cycle
        if(vis[i]==1)return false;
        
        //already covered in some other path
        if(vis[i]==2)return good[i];
        
        vis[i]=1;
        
        int next=i+arr[i];
        
        bool ans=func(next,arr,vis,good);
        
        
        vis[i]=2;
        
        good[i]=ans;
        return ans;
        
    }
  
    int goodIndices(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        
        vector<int>vis(n,0);
        
        vector<int>good(n,0);
        
        
        for(int i=0;i<n;i++){
            //pehle koi path mei cover kar chuke hai
            if(vis[i]==2)continue;
            
            func(i,arr,vis,good);
        }
        
        int c=0;
        for(int i:good){
            if(i)c++;
        }
        return c;
    }
};
