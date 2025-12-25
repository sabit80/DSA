#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }

};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;

    void  creationFromarray(int arr[],int n){
        head=new Node(arr[0]);
        Node* curr=head;

        for(int i=1;i<n;i++){
            Node* newNode=new Node(arr[i]);
            curr->next=newNode;
            newNode->prev=curr;
            curr=curr->next;
        }
        tail=curr;
        
    }
    int getLength(){
        int size=0;
        Node* curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        return size;
    }
    void insertAtfront(int val){
        Node* newNode= new Node(val);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    void insertAtEnd(int val){
        Node* newNode=new Node(val);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;

    }

    void print(){
        Node* curr=head;
        while(curr!=NULL){
            cout<< curr->val << "->";
            curr=curr->next;

        }
        cout <<endl;
    }
    Node*  getNodeAt(int index){
        if(index<0){return NULL;}
        Node* curr=head;
        while(index){
            index--;
            curr=curr->next;
        }
        return curr;
    }

    void insertAtIndex(int index,int val){
        if(index==0){insertAtfront(val);return;}
        if(index>getLength()){return;}

        Node* prevNode=getNodeAt(index-1);
        if(prevNode==NULL){insertAtfront(val);return;}
        if(prevNode->next!=NULL){
            Node* newNode=new Node(val);
            newNode->next=prevNode->next;
            newNode->prev=prevNode;
            prevNode->next=newNode;
            newNode->next->prev=newNode;
        }
        else{
            insertAtEnd(val);
        }
    }
    void RemoveAtIndex(int index){
        if(index==0){
            Node* currhead=head;
            head=head->next;
            head->prev=NULL;
            delete currhead;
            return;
        }
        Node* temp=getNodeAt(index);
        if(temp==NULL){return;}
        temp->prev->next=temp->next;

        if(temp!=tail){ // not tail not head
            temp->next->prev=temp->prev;
        }
        else{// tail removal
                tail=temp->prev;
        }
        
        delete temp;
    }



};

int main(){

    DoublyLinkedList list1;
    int arr[]={1,2,3,4,5,6,7,8,9};

    list1.creationFromarray(arr,9);
    list1.print();

}