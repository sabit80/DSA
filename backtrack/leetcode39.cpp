#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;

    void dfs(int i ,vector<int>& candidates,int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0 || i>=candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        dfs(i,candidates,target-candidates[i]);
        curr.pop_back();
        dfs(i+1,candidates,target);
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0,candidates,target);
        return ans;

    }
};