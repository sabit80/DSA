#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

  // CODE IS RIGHT BUT GETTING TLE FOR USING UNORDERD MAP
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>mp;

        for(int i : nums){
            mp[i]=true;
        }
        int maxSequence=0;
        for(int i =0;i<nums.size();i++){
            if(mp.find(nums[i]-1)==mp.end()){//  starting of a sequence
                int start=nums[i];
                int next=nums[i]+1;
                int sequence=1;
                while(mp.find(next)!=mp.end()){
                    sequence++;
                    next++;
                }
                if(sequence>maxSequence){maxSequence=sequence;}
            }
        }
        return maxSequence;
    }
};