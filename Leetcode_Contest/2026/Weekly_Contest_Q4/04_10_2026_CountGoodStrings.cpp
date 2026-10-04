class Solution {
public:

    const int mod=1e9+7;

    pair<long long ,long long>func(long long n){
        if(n==0){
            return {0,1};
        }

        auto[a,b]=func(n/2);

        // a-->fib(5)
        //b--> fib(6)

        //c-->fib(10)
        long long c=(a*((2*b%mod)-a+mod)%mod)%mod;

        //d --> fib(11)
        long long d=((b*b%mod)+(a*a%mod))%mod;

        if(n%2==0){
            return {c,d};
        }
        return {d,(c+d)%mod};
    }

    int countGoodStrings(long long n) {
        long long f=func(n).first;
        return 2*f%mod;
    }
};
