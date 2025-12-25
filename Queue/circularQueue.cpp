#include<bits/stdc++.h>
using namespace std;
class CircularQueue{
    int *arr;
    int currSize,cap;
    int f,r;

    public:
    CircularQueue(int size){ // user will initialize with a fixed size circular queue;
        cap=size;
        arr=new int[cap];
        f=0;r=-1;
    }
    void pop(){
        if(empty()){
            return;
        }

        f=(f+1)%cap;
        currSize--;
        

    }
    void push(int data){
        if(currSize==cap){
            return;
        }
        else{

            r=(r+1)%cap;
            arr[r]=data;
            currSize++;
        }

    }
    void front(){
        if(empty()){
            return;
        }
        cout<< arr[f];

    }
    bool empty(){
        if(currSize==0){return true;}
        return false;
    }

};
int main(){

}