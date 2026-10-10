class Solution {
  public:
    bool balancePan(int a, int b) {
        // code here
        while(b>0){
            int rem=b%a;
            
            if(rem==1)b--;
            else if(rem==a-1)b++;
            
            else if(rem!=0)return false;
            
            b/=a;
        }
        return true;
    }
};
