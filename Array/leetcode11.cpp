#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;

        int left=0;
        int right=height.size()-1;

        while(left<right){
            int width=right-left;
            int h=min(height[left],height[right]);

            int currArea=width*h;
            ans=max(ans,currArea);

            if(height[left]<height[right]){
                left++;
            }
            else{right--;}

        }
        return ans;


    }
};