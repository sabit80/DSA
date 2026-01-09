#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end()); // initializing a set from an array 

        int maxSequence=0;
        for(int num : set){
            if(num == INT_MIN ||set.find(num-1)==set.end()){//  int min is alwasys starting of a sequence
                int start=num;
                int next=num+1;
                int sequence=1;
                while(set.find(next)!=set.end()){
                    sequence++;
                    next++;
                }
                if(sequence>maxSequence){maxSequence=sequence;}
            }
        }
        return maxSequence;
    }
};