class Solution {
  public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        
        int n=arr.size()+1;
        
        
        //n
        for(int i=2;i<=n;i++){
            int j=i,c=1;
            vector<vector<int>>temp;
            
            //n 
            while(j!=1){
                int fri=arr[j-2];
                temp.push_back({i,fri,c});
                c++;
                j=fri;
            }
            
            for(int i=temp.size()-1;i>=0;i--){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};
