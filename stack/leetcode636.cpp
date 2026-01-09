#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int>stk;

        int prevtime=0;
        vector<int>result(n,0);

        for(string log: logs){
            

            int p1 = log.find(':');
            int p2 = log.find(':', p1 + 1);

            int id = stoi(log.substr(0, p1));              // "12" → 12
            string type = log.substr(p1 + 1, p2 - p1 - 1); // "end"
            int time = stoi(log.substr(p2 + 1));           // "45" → 45


            if(type =="start"){
                if (!stk.empty()) {
                    result[stk.top()] += time - prevtime;
                }
                stk.push(id);
                prevtime = time;
            }
            else{
                result[stk.top()]+=time-prevtime+1;
                stk.pop();

                prevtime=time+1;
            }
            
        }
        return result;
    }
};