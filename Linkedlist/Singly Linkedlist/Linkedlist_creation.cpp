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
   Node* temp=head;
   Node* t=new Node(x);
    if(k==1){
         t->next=head;
         head=t;
         return;
    }
    else if(k==2)
    {
        //  t->next=head->next;
        //  head->next=t;
        //  return;
        head->next=t;
        t->next=head->next;
        return;
    }
    // for(int i=0;i<k-2;i++){
    //     temp=temp->next;
    // }
    // t->next=temp->next;
    // temp->next=t;
    while(k>2 && temp!=NULL){
        temp=temp->next;
        k--;
    }
    Node* temp1=temp->next;
    temp->next=t;
    t->next=temp1;
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
void DeleteNodeAtKthposition(Node* &head,int k){
    if(head==NULL){
        return;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
   else if(k==2)
   {
         Node* temp=head->next;
         head->next=temp->next;
         delete temp;
         return;
    }
     Node* curr=head;
     for(int i=0;i<k-2;i++){
          curr=curr->next;
     }
     Node* temp=curr->next;
     curr->next=curr->next->next;
     delete temp;
   }
void reverse(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    printlist(head);
    cout<<endl;
    cout<<"After Insertion"<<endl;
    InsertNodeAtFirst(head,5);
    printlist(head);
    cout<<endl;
    cout<<"After Insertion"<<endl;
    InsertNodeAtEnd(head,40);
    printlist(head);
    cout<<endl;
    cout<<"After Insertion"<<endl;
    InsertNodeAtKthposition(head,25,4);
    printlist(head);
    cout<<endl;
    cout<<"After Deletion"<<endl;
    DeleteNodeAtFirst(head);
    printlist(head);
    cout<<endl;
    cout<<"After Deletion"<<endl;
    DeleteNodeAtEnd(head);
    printlist(head);
    cout<<endl;
    cout<<"After Deletion"<<endl;
    DeleteNodeAtKthposition(head,3);
    printlist(head);
    cout<<endl;
    cout<<"After Reversing"<<endl;
    reverse(head);
    printlist(head);
    return 0;
}


