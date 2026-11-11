class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>m;
        
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i])!=m.end()){
                if(i-m[arr[i]]<=k)return true;
            }
            m[arr[i]]=i;
        }
        
        return false;
    }
};
