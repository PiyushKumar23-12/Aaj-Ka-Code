//Better Approach:
int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        sort(arr.begin(),arr.end());
        
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int sum=arr[i]+arr[j];
                
                if(sum<l){
                    int left=l-sum;
                    int right=r-sum;
                    ans+=upper_bound(arr.begin()+j+1,arr.end(),right)-arr.begin()-j-1;
                    ans-=upper_bound(arr.begin()+j+1,arr.end(),left-1)-arr.begin()-j-1;
                }
                
                else if(sum>=l && sum<=r){
                    int req=r-sum;
                    ans+=upper_bound(arr.begin()+j+1,arr.end(),req)-arr.begin()-j-1;
                }
                
            }
        }
        return ans;
    }



//Optimised Approach:

class Solution {
  public:
  
  
  //Optimised approach
  int func(vector<int> &arr, int r){
      int ans=0;
      int n=arr.size();
      
      for(int i=0;i<n-2;i++){
          int j=i+1,k=n-1;
          
          while(j<k){
              int sum=arr[i]+arr[j]+arr[k];
              if(sum>r){
                  k--;
              }
              else{
                  ans+=k-j;
                  j++;
              }
          }
      }
      
      return ans;
      
  }
  
  
  int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        //nlog n
        sort(arr.begin(),arr.end());
        
        //n2
        return func(arr,r)-func(arr,l-1);
        
    }
};
