#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    long long n,k;
	    cin>>n>>k;
	    
	    vector<long long>a(n);
	    for(long long i=0;i<n;i++){
	       cin>>a[i];
	    }
	    
	    if(k==n){
	        cout<<max(a[0],a[n-1])<<endl;
	        continue;
	    }
	    
	    long long l=k-1;
	    long long r=n-k;
	    
	    long long ans=0;
	    vector<long long>temp;
	    if(l<=r){
	        for(int i=l;i<=r;i++){
	            ans+=a[i];
	        }
	        
	        //0 to l-1 
	        for(int i=0;i<l;i++){
	            temp.push_back(a[i]);
	        }
	        
	        //r+1 .. n-1
	        
	        for(int i=r+1;i<n;i++){
	            temp.push_back(a[i]);
	        }
	    }
	    else{
	        temp=a;
	    }
	    
	    
	    l=k-1;
	    r=temp.size()-k;
	    
	    while(temp.size()>=k && l<temp.size() && r>=0){
	        ans+=max(temp[r],temp[l]);
	        l++;
	        r--;
	    }
	    cout<<ans<<endl;
	    
	}

}
