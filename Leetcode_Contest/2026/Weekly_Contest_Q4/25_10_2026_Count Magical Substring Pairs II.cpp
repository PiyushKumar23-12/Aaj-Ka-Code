class Solution {
public:
    long long countMagicalPairs(string s) {
        int n=s.length();
        vector<vector<int>>next(n+1,vector<int>(26,n));

        for(int i=n-1;i>=0;i--){
            next[i]=next[i+1];
            next[i][s[i]-'a']=i;
        }

        vector<int>last(26,-1);

        long long ans=0;

        //split points
        for(int j=0;j<n-1;j++){
            last[s[j]-'a']=j;

            vector<int>left,rt;
            for(int c=0;c<26;c++){
                if(last[c]!=-1)left.push_back(last[c]);
                if(next[j+1][c]!=n)rt.push_back(next[j+1][c]);
            }

            int a=left.size(),b=rt.size();

            sort(left.begin(),left.end());
            sort(rt.begin(),rt.end());

            //lsub[i]-->subarray ka length kitna hai with i distincts
            vector<long long>lsub(a,0),rsub(b,0);

            for(int d=1;d<=a;d++){
                if(d==a){
                    lsub[d-1]=left[0]+1;
                }
                else{
                    lsub[d-1]=left[a-d]-left[a-d-1];
                }
            }

            for(int d=1;d<=b;d++){
                if(d==b){
                    rsub[d-1]=n-rt[b-1];
                }
                else{
                    rsub[d-1]=rt[d]-rt[d-1];
                }
            }

            for(int d=1;d<=min(a,b);d++){
                ans+=lsub[d-1]*rsub[d-1];
            }
        }
        return ans;
    }
};
