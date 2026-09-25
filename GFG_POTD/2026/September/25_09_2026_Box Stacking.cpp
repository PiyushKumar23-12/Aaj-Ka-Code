class Solution {
  public:
    
    vector<vector<int>>dp;
  
    int func(int i,int prev,vector<vector<int>>&boxes){
        if(i==boxes.size())return 0;
        
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        
        int nt=func(i+1,prev,boxes);
        
        int take=0;
        if(prev==-1 || (boxes[prev][1]>boxes[i][1] && boxes[prev][0]>boxes[i][0])){
            take=boxes[i][2]+func(i+1,i,boxes);
        }
        return dp[i][prev+1]=max(take,nt);
    }
  
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // code here
        int n=height.size();
        
        vector<vector<int>>boxes;
        
        for(int i=0;i<n;i++){
            int a=height[i],b=width[i],c=length[i];
            
            
            // base repetition ko avoid karo
            //a,b,c
            // a,c,b 6 combinations
            boxes.push_back({max(b,c),min(b,c),a});
            boxes.push_back({max(a,c),min(a,c),b});
            boxes.push_back({max(b,a),min(b,a),c});
        }
        
        //sort in descending order
        
        //3n 
        // 3nlog3n
        
        sort(boxes.begin(),boxes.end(),[](const vector<int>&a,const vector<int>&b){
            //length diff 
            if(a[0]!=b[0])return a[0]>b[0];
            // length same bada width 
            return a[1]>b[1];
        });
        
        //3n*3n
        
        dp.assign(boxes.size()+1,vector<int>(boxes.size()+2,-1));
        
        return func(0,-1,boxes);
    }
};
