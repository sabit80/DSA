#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int>prefixN(customers.size()+1,0);
        vector<int>suffixY(customers.size()+1,0);

        if(customers[0]=='N'){
            prefixN[0]=1;
        }

        for(int i =1;i<customers.size();i++){
            prefixN[i]=prefixN[i-1];

            if(customers[i]=='N'){
                prefixN[i]++;
            }
        }

        vector<int>prefixNwithoutCurr(customers.size()+1,0);
        prefixNwithoutCurr[0]=0;
        for(int i =1;i<prefixNwithoutCurr.size();i++){
            prefixNwithoutCurr[i]=prefixN[i-1];
        }



        if(customers[customers.size()-1]=='Y'){
            suffixY[customers.size()-1]=1;
        }

        for(int i =customers.size()-2;i>=0;i--){
            suffixY[i]=suffixY[i+1];

            if(customers[i]=='Y'){
                suffixY[i]++;
            }
        }


        int minIndx=0;
        int minPen=prefixNwithoutCurr[0]+suffixY[0];
        for(int i =0;i<=customers.size();i++){
            int currentpen=prefixNwithoutCurr[i]+suffixY[i];

            if(minPen>currentpen){
                minPen=currentpen;
                minIndx=i;
            }
        }
        return minIndx;


        
    }
};