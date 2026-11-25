class Solution {
public:
    int minTime(int a, int b, int d, int l, int r) {
        const long long MOD = 1e9 + 7;
        long long total = 0;
        
        long long p = a - b;
        long long k = (d - a+p-1) / p;
        long long normalTime = a + 1LL * k * (a + b);

        long long left=d-r;
        long long rt=d-l;
        
        long long mini=min(rt,(long long)a);
        
        if(left<=mini){
            long long n=mini-left+1;
            total+=(n*(n+1))/2+n*left;
            left=mini+1;
        }
        
        
        //O(a-b)
        
        for(int rem=0;rem<p;rem++){
            long long first=left+rem;
            
            if(first>rt)return total;
            //how many elemenst are there
            long long n=(rt-first)/p +1;
            
            //kitna net movements chahiye
            long long c = (first - a+p-1) / p;
            
            //kitna time laga to reach first
            long long base=a + 1LL * c * (a + b)-(a+c*p-first)+1;
            
            long long delta=a+b;
            
            
            long long take=0;
            
            if(base<normalTime){
                take=min(n,(normalTime-base-1)/delta+1);
            }
            
            total=(total+(take*(2*base+(take-1)*delta))/2)%MOD;
            

            total=(total+(n-take)*normalTime)%MOD;
        }
        return total%MOD;
    }
};
