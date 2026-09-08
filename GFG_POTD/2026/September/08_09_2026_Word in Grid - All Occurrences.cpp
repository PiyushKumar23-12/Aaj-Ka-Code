class Solution {
  public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        
        
        vector<vector<int>>ans;
        
        //directions
        
        //x dir
        int dx[]={1,-1,0,0,1,1,-1,-1};
        
        //y dir
        int dy[]={0,0,1,-1,1,-1,1,-1};
        
        
        //n*m*8*word.length
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                
                if(mat[row][col]!=word[0])continue;
                
                for(int d=0;d<8;d++){
                    int x=row,y=col;
                    int k=0;
                    
                    while(k<word.length()){
                        //pura word complete nhi kar paayein
                        if(x<0 || y<0 || x>=n || y>=m)break;
                        
                        if(mat[x][y]!=word[k])break;
                        
                        // humlog right jaate jaayenge
                        x+=dx[d];
                        y+=dy[d];
                        k++;
                    }
                    
                    if(k==word.length()){
                        ans.push_back({row,col});
                        break;
                    }
                }
            }
        }
        
        if(ans.size()==0)return {{-1}};
        return ans;
        
    }
};
