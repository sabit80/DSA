#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>dq;
    dq.push_front(1);
    dq.push_back(3);
    dq[1]=dq[0];

    dq.pop_back();
    dq.pop_front();

    cout<< dq.front() << dq.back();
}