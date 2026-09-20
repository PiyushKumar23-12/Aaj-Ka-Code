class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<vector<int>>group={nums};

        vector<int>ans(15);

        
        for(int bit=14;bit>=0;bit--){

            //groups for next level
            vector<vector<int>>next;

            bool flag=0;

            // iss bit ka total prefix sum
            int c=0;

            //traverse groups
            for(int i=0;i<group.size();i++){
                vector<int>ones,zero;

                // process kar rahe koi previous kiye aur flag=1 hai
                //means koi element pehle aisa tha jo is bit ko 0 set kar diya hai
                
                if(flag){
                    next.push_back(group[i]);
                    continue;
                }

                for(int j=0;j<group[i].size();j++){
                    if((group[i][j]>>bit)&1){
                        ones.push_back(group[i][j]);
                    }
                    else{
                        zero.push_back(group[i][j]);
                    }
                }

                // all the numbers in this group have set bit 1
                if(zero.empty()){
                    c+=ones.size();
                    next.push_back(ones);
                }
                else{
                    // some elements have set bit =0
                    if(!ones.empty()){
                        c+=ones.size();
                        next.push_back(ones);
                    }
                    next.push_back(zero);
                    flag=1;
                }
            }
            ans[14-bit]=c;
            group=next;
            
        }


        return ans;
    }
};
