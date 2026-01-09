#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for(int i =digits.size()-1;i>=0;i--){
            if(digits[i]<9){ // last digit is not a 9
                digits[i]++;
                return digits;
            }

            // code for finding last digit nine;
            digits[i]=0; // nothing else cz the loop will automatically increase value before nine

        }

        // the code comes to this point that means 
        // all values where 9999... so add a 1 in front after making all zeros

        digits.insert(digits.begin(),1);
        return digits;
    }
};