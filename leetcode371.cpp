#include<bits/stdc++.h>
class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua=a;
        unsigned int ub=b;
        while(ub!=0){
            unsigned int carry=(ua&ub)<<1;
            ua=ua^ub;
            ub=carry;

        }
        return (int)ua;
    }
};
