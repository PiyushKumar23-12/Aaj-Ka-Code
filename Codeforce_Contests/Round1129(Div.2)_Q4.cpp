#include <bits/stdc++.h>
using namespace std;


using ll=long long;
const ll mod=998244353;

ll func(ll n){
    if(n<=0)return 0;
    if(n==1)return 1;
    if(n==2)return 3;
    
    ll k=0;
    
    while(((1LL<<(k+1))-1)<=n){
        k++;
    }
    
    ll cur=(1LL<<k)-1;
    ll next=(1LL<<(k+1))-1;
    
    if(cur==n){
        return k;
    }
    
    ll takecur=k+1+func(n-cur+1);
    
    ll takenext=k+1+next-n;
    return min(takecur,takenext);
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        ll l,r;
        cin>>l>>r;
        
        ll ans=0;
        
        for(ll q=l;q<=r;q++){
            ans=(ans+func(q))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
