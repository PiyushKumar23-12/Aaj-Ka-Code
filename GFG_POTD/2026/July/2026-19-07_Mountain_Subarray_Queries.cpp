class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n=arr.size();
        vector<int>left(n,0),right(n,0);
        
        left[0]=0;
        right[n-1]=n-1;
        
        int cleft=0;
        int crt=n-1;
        
        //left array
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                cleft=i;
            }
            left[i]=cleft;
        }
        
        //right array
        
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                crt=i;
            }
            right[i]=crt;
        }
        
        
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0],r=queries[i][1];
            
            if(right[l]>=left[r]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
        
        
    }
};
