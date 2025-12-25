#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int row=strs.size();
        int col=strs[0].size();


        for(int j=0;j<col;j++){
            char small='a'; // as all are english small 

            for(int i =0;i<row;i++){
                if(strs[i][j]>=small){ //greater or equal so lexicographically sorted
                    small=strs[i][j];
                }
                else{
                    ans++;
                    break;
                }
            }

        }
        return ans;

    }
};