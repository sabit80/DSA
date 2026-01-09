#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre;
        pre.push_back(1);
        pre.push_back(nums[0]);

        vector<int>suf;
        suf.push_back(1);
        suf.push_back(nums[nums.size()-1]);

        for(int i =1;i<nums.size()-1;i++){
            int ans=nums[i]*pre[i];
            pre.push_back(ans);
            
        }

        for(int i =nums.size()-2;i>0;i--){
            int ans=nums[i]* suf[nums.size()-1-i];
            suf.push_back(ans);
        }

        reverse(suf.begin(),suf.end());

        for(int i =0;i<nums.size();i++){
            nums[i]=pre[i]*suf[i];
        }
        return nums;

    }
};