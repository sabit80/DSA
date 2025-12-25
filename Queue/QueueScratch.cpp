#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=NULL;
    }
};
class Queue{
    Node *head;
    Node *tail;
    public:
    Queue(){
        head=tail=NULL;
    }
    void push(int data){
        Node* newNode=new Node(data);
        if(empty()){
            head=tail=newNode;

        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        
        
    }
    void pop(){
        if(empty()){
            cout << "Queue is empty";
            return;
        }
        else{
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    int front(){
        if(empty()){
            cout<< "EMpty ";
            return -1;
        }
        return head->val;
    }
    bool empty(){
        if(head==NULL && tail== NULL){
            return true;
        }
        return false;
    }

};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<< q.front();
        q.pop();

    }

}