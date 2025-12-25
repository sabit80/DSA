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

class Linked_list{
    public:
    Node* head;
    Node* tail;

    Node* createFromArray(int arr[],int n){
        Node* head=new Node(arr[0]);
        Node* current=head;
        for(int i=1;i<n;i++){
            current->next=new Node(arr[i]);
            current=current->next;
        }
        return head;
    }
    void printLinkedlist(Node* head){
        Node* current=head;
        while(current!=NULL){
            cout << current->val<< "->";
            current=current->next;
        }
        cout<<endl;
    }

    int Indexof(Node* head,int val){
        int indx=0;
        Node* curr=head;

        while(curr!=NULL){
            if(curr->val==val){
                return indx;
            }

            indx++;
            curr=curr->next;
        }
        return -1;
    }

    Node* insertAtFront(Node* head,int val){
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
        return head;
    }
    Node* getNodeAt(Node* head,int index){
        if(index<0){return NULL;}
        Node* current=head;
        while(index){
            current=current->next;
            index--;
        }
        return current;
    }

    Node* insertAtIndx(Node* head,int index,int val){
        // valid for indx smallaer than the size

        Node* prev=getNodeAt(head,index-1);

        if(prev!=NULL){
        Node * newNode=new Node(val);
        Node* nextNode=getNodeAt(head,index+1);

        newNode->next=nextNode;
        prev->next=newNode;
        return head;

        }
        else{ // insert at first;

            insertAtFront(head,val);

        }
    }
    Node* insertAtEnd(Node* head,int val){
        Node* current=head;

        while(current!=NULL){
            current=current->next;
        }
        Node* newNode= new Node(val);
        current->next=newNode;
        newNode->next=NULL;
        return head;
    }

    int lenth(Node* head){
        int length=0;
        Node* current=head;
        while(current!=NULL){
            length++;
            current=current->next;
        }
        return length;
    }


};

int main(){

    Linked_list list1;
    int arr[]={1,2,3,4,5,6,7,8,9};
    Node* head=list1.createFromArray(arr,9);
    list1.printLinkedlist(head);
}