class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
        // code here
        
        unordered_set<string>reserve(arr.begin(),arr.end());
        unordered_set<string>assign;
         
         
        vector<string>ans;
        
        
        for(const string &name:arr){
            if(assign.find(name)==assign.end()){
                assign.insert(name);
                ans.push_back(name);
            }
            
            else{
                int k=1;
                while(true){
                    string newname=name+to_string(k);
                    if(assign.find(newname)==assign.end() && reserve.find(newname)==reserve.end()){
                        assign.insert(newname);
                        ans.push_back(newname);
                        break;
                    }
                    k++;
                }
            }
        }
        
        
        return ans;
         
        
    }
};
