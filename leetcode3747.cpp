#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countDistinct(long long n) {
        unordered_map<long long int,long long int>mp;
        for(long long int i=1;i<=n;i++){
            long long int indx=i;
            while(indx%10==0){
                indx=indx/10;
            }
            if(mp.find(indx)==mp.end()){
                mp[indx]=1;
            }
            else{
                mp[indx]+=1;
            }
        }
        int ans=0;
        for(long long int i=1;i<=n;i++){
            if(mp.find(i)!=mp.end()){
                ans++;
            }
        }
        return ans;

    }
};