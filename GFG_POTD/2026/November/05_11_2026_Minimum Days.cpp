class Solution {
  public:
  
    bool func(string s,vector<int> &p,int mid){
        for(int i=1;i<=mid;i++){
            s[p[i]]='?';
        }
        
        int j=1;
        while(j<s.length()){
            if(s[j]==s[j-1] && s[j]!='?')return false;
            j++;
        }
        return true;
    }
  
    int getMinimumDays(string &s, vector<int> &p) {
        // code here
        p.insert(p.begin(),-1);
        int l=0,h=p.size()-1;
        
        int ans=0;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(func(s,p,mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return ans;
        
    }
};
