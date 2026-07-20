class Solution {
  public:
  
    int func(int i,int j,vector<string>& temp){
        int k=0;
        while(k<temp[i].length() && k<temp[j].length() && temp[i][k]==temp[j][k]){
            k++;
        }
        return k;
    }
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        int n=arr.size();
        
        vector<string>temp=arr;
        sort(temp.begin(),temp.end());
        
        map<string,string>res;
        
        //word->prefix
        
        
        for(int i=0;i<n;i++){
            int prev=0,next=0;
            
            if(i>0){
                prev=func(i,i-1,temp);
            }
            
            if(i<n-1){
                next=func(i,i+1,temp);
            }
            
            int maxi=max(prev,next)+1;
            
            res[temp[i]]=temp[i].substr(0,maxi);
            
        }
        
        vector<string>ans;
        
        
        for(int i=0;i<n;i++){
            //zebra --> z
            ans.push_back(res[arr[i]]);
        }
        
        return ans;
        
        
        
    }
};
