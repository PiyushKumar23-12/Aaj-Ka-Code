class Solution {
  public:
  
    int findXor(int n){
        if(n%4==1)return 1;
        if(n%4==2)return n+1;
        if(n%4==3)return 0;
        return n;
    }
    int findXOR(int l, int r) {
        // code here
        return findXor(r)^findXor(l-1);
    }
};
