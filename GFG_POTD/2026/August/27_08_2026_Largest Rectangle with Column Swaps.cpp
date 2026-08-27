class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        // code here
        
        int n=mat.size();
        
        int m=mat[0].size();
        
        
        int ans=0;
        
        vector<int>height(m,0);
        
        //n *(mlogm + m+ m);
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(mat[row][col]==1){
                    //height increases
                    height[col]++;
                }
                else{
                    //reset the height
                    height[col]=0;
                }
            }
            
            // SC is 2m
            vector<int>temp=height;
            
            sort(temp.rbegin(),temp.rend());
            
            for(int col=0;col<m;col++){
                int area=temp[col]*(col+1);
                ans=max(ans,area);
            }
            
        }
        return ans;
        
    }
};
