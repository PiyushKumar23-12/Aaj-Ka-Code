class Solution {
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        // code here
        int ans=0;
        int n=mat.size(),m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ans+=4;
                    if(i>=1 && mat[i-1][j]==1){
                        ans--;
                    }
                    if(j>=1 && mat[i][j-1]==1)ans--;
                    
                    if(i+1<n && mat[i+1][j]==1)ans--;
                    if(j+1<m && mat[i][j+1]==1)ans--;
                    
                }
            }
        }
        return ans;
    }
};
