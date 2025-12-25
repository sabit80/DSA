#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i:arr){
            mp[i]++;
        }

        int missing=0;
        int i=1;
        while(i){
            if(mp.find(i)==mp.end()){
                missing++;

                if(missing==k){return i;}
            }
            i++;
        }
    }
};