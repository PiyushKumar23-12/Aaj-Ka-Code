class Solution {
  public:
    char nthCharacter(int n) {
        // code here
        
        long long len=1;
        long long start=1;
        long long ct=9;
        while(n>len*ct){
            n-=len*ct;
            ct*=10;
            len++;
            start*=10;
        }
        
        long long tar=start+(n-1)/len;
        
        string s=to_string(tar);
        long long idx=(n-1)%len;
        return s[idx];
    }
};
