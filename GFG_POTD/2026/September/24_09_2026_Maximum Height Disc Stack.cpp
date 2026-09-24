DP based approach

class Solution {
  public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        // code here
        int n=r.size();
        
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({r[i],h[i]});
        }
        
        sort(v.begin(),v.end());
        
        vector<int>dp(n);
        
        //dp[i]--> iss index tak max stack height kya hai
        
        for(int curr=0;curr<n;curr++){
            
            //single disc in stack
            dp[curr]=v[curr][1];
            
            //previous disc
            for(int prev=0;prev<curr;prev++){
                //both dimensions are more
                if((v[curr][1]>v[prev][1]) && (v[curr][0]>v[prev][0])){
                    dp[curr]=max(dp[curr],dp[prev]+v[curr][1]);
                }
            }
        }
        
        int maxi=*max_element(dp.begin(),dp.end());
        return maxi;
    }
};




Segment Tree

class Solution {
  public:
    vector<int>stree;
    int mx;
    
    int findquery(int i,int l,int r,int st,int end){
        //outside the range
        if(r<st || l>end)return 0;
        
        //completely within that range
        if(l>=st && r<=end){
            return stree[i];
        }
        
        int mid=l+(r-l)/2;
        return max(findquery(2*i,l,mid,st,end),findquery(2*i+1,mid+1,r,st,end));
    }
    
    
    void update(int i,int l,int r,int idx,int val){
        
        //mid=1
        //leaf node
        if(l==r){
            stree[i]=max(stree[i],val);
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            //index is in left subtree
            update(2*i,l,mid,idx,val);
        }
        else{
            //idx right subtree
            update(2*i+1,mid+1,r,idx,val);
        }
        
        //node update
        stree[i]=max(stree[2*i],stree[2*i+1]);
        return;
    }
    
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        // code here
        mx=*max_element(h.begin(),h.end());
        
        int n=r.size();

        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({r[i],h[i]});
        }
        
        //nlog n

        sort(v.begin(),v.end());
        
        stree.assign(4*mx+1,0);
        
        int ans=0;
        int i=0;
        
        
        // curr
        
        //nlogmx
        while(i<n){
            
            int j=i;
            
            //process disc having same radius
            while(j<n && v[j][0]==v[i][0])j++;
            vector<vector<int>>temp;
            
            // 1...hei-1
            for(int k=i;k<j;k++){
                int hei=v[k][1];
                
                //it will give us the best extend from 1 to hei-1
                
                //best sum of disc 1...hei-1
                int best=findquery(1,1,mx,1,hei-1);
                
                int cur=hei+best;
                ans=max(ans,cur);
                temp.push_back({hei,cur});
            }
            
            for(int i=0;i<temp.size();i++){
                update(1,1,mx,temp[i][0],temp[i][1]);
            }
            i=j;
        }
        return ans;
        
    }
};
