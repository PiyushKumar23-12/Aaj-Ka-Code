class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        // code here
        int size=4*n;
        
        vector<vector<int>>temp(size,vector<int>(size));
        
        int c=1;
        for(int i=0;i<4*n;i++){
            for(int j=0;j<4*n;j++){
                temp[i][j]=c++;
            }
        }
        
        vector<int>coil1,coil2;
        
        int ct=0;
        int req=8*n*n;
        
        // row 1 col=2
        //val=row*n+col
        
        //initial elements
        for(int row=0;row<4*n;row++){
            coil1.push_back(temp[row][0]);
            coil2.push_back(temp[size-1-row][size-1]);
            ct++;
        }
        
        int row=4*n-1;
        int col=1;
        int leave=1;
        int dir=1;
        
        while(ct<req){
            //right & up
            if(dir==1){
                while(col<=size-1-leave && ct<req){
                    coil1.push_back(temp[row][col]);
                    coil2.push_back(temp[size-1-row][size-1-col]);
                    col++;
                    ct++;
                }
                row--;
                col--;
                
                while(row>=leave && ct<req){
                    coil1.push_back(temp[row][col]);
                    coil2.push_back(temp[size-1-row][size-1-col]);
                    row--;
                    ct++;
                }
                row++;
                col--;
            }
            //left & down
            else{
                while(col>=leave && ct<req){
                    coil1.push_back(temp[row][col]);
                    coil2.push_back(temp[size-1-row][size-1-col]);
                    col--;
                    ct++;
                }
                col++;
                row++;
                
                while(row<=size-1-leave && ct<req){
                    coil1.push_back(temp[row][col]);
                    coil2.push_back(temp[size-1-row][size-1-col]);
                    row++;
                    ct++;
                }
                row--;
                col++;
            }
            dir=!dir;
            leave++;
        }
        
        return {coil1,coil2};
        
    }
};
