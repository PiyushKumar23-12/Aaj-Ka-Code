class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        int ans=0;
        
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    height[j]+=1;
                }
                else{
                    height[j]=0;
                }
            }
            
            vector<int>temp=height;
            
            sort(temp.rbegin(),temp.rend());
            

            for(int k=0;k<m;k++){
                int w=k+1;
                int h=temp[k];
                ans=max(ans,h*w);
            }
        }
        return ans;
    }
};
