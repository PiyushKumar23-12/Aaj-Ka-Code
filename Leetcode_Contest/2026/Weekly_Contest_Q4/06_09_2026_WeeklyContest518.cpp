// Q1.
class Solution {
public:
    int countRotations(string s, int k) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int c=0;
            for(int j=0;j<s.length()-1;j++){
                if(s[j]==s[j+1])c++;
            }

            if(c==k)ans++;

            char ch=s.back();
            s.pop_back();
            s=ch+s;
        }
        return ans;
    }
};


//Q2.
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();

        long long tot=0;
        for(int i:nums){
            tot+=i;
        }

        long long l=0,r=0;
        long long m=n/2;

        long long lsum=0;
        while(r<m){
            lsum+=nums[r];
            r++;
        }
        long long ans=0;
        if(lsum>tot-lsum)ans++;

        while(l<n-1){
            lsum-=nums[l];
            l++;
            lsum+=nums[r%n];
            r++;
            if(lsum>tot-lsum)ans++;
        }
        return ans;
    }
};


//Q3.
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();

        int ans=1;
        int gspeed=speed[n-1];


        for(int i=n-2;i>=0;i--){
            //they are already close
            if(position[i+1]-position[i]<=distance)continue;

            //we need to take the speed of rightmost robot
            if(speed[i]>gspeed){
                continue;
            }

            // dono ke beech ka dis>distance
            //speed[i]<=gspeed

            ans++;
            gspeed=speed[i];           
            
        }
        return ans;
    }
};

//Q4.
class Solution {
public:

    int dp[76][76][76][5];
    
    int func(int i,int j,int m,int n,vector<vector<int>>& grid, int k,int dir){

        // base case
        //invalid states
        if(i<0 || j<0 || i>=m || j>=n || k<0)return 1e8;

        //valid case
        if(i==m-1 && j==n-1)return grid[i][j];

        //we have already visited
        if(dp[i][j][k][dir+1]!=-1)return dp[i][j][k][dir+1];

        int ans=1e8;

        //2 cases
        //0,0
        if(dir==-1){
            //down
            int a=grid[i][j]+func(i+1,j,m,n,grid,k,0);
            //up
            int b=grid[i][j]+func(i-1,j,m,n,grid,k,1);
            //right
            int c=grid[i][j]+func(i,j+1,m,n,grid,k,2);

            //left
            int d=grid[i][j]+func(i,j-1,m,n,grid,k,3);

            ans=min({a,b,c,d});
        }

        else{
            //down
            int a=grid[i][j]+func(i+1,j,m,n,grid,k-(dir!=0),0);
            //up
            int b=grid[i][j]+func(i-1,j,m,n,grid,k-(dir!=1),1);
            //right
            int c=grid[i][j]+func(i,j+1,m,n,grid,k-(dir!=2),2);
            //left
            int d=grid[i][j]+func(i,j-1,m,n,grid,k-(dir!=3),3);

            ans=min({a,b,c,d});
        }

        return dp[i][j][k][dir+1]=ans;
        
        
    }
    
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=func(0,0,m,n,grid,k,-1);

        if(ans>=1e8)return -1;
        return ans;
    }
};
