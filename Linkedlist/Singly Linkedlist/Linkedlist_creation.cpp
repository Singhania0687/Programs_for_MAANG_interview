# include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
void printlist(Node* head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
void InsertNodeAtFirst(Node* &head,int x){
    Node* temp=new Node(x);
    temp->next=head;
    head=temp;
}
void InsertNodeAtEnd(Node* &head,int x){
    Node* temp=new Node(x);
    if(head==NULL){
        head=temp;
        return;
    }
    Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}
void InsertNodeAtKthposition(Node* &head,int x,int k){
   
}
void DeleteNodeAtFirst(Node* &head){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}
void DeleteNodeAtEnd(Node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        return;
    }
    Node* curr=head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    delete curr->next;
    curr->next=NULL;
}
