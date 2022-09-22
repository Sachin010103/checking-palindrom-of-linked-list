#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;
    

    //constructor
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};


void insertathead(node* &head,int element){


       node* temp=new node(element);
       temp->next=head;
       head=temp;
      
}



 void insertatpostion(node*& head ,int element, int position ){
      node* x=new node(element); 

      if(position==1){
        insertathead(head,element);
        return;
      }
      
      if (head==NULL)
      {
         head=x;
         return;
      }
     
    node* temp=head;
    int count = 1;
    while(count<position-1 && temp->next!=NULL){
         temp=temp->next;
         count++;
    }
    
    if(temp->next==NULL){
       temp->next=x;
       return;
    }
  
    x->next=temp->next;
    temp->next=x;
 } 

void insertattail(node*& tail,int element){

   node* x=new node(element);
    node* temp=tail;
    while(temp->next!=NULL){
        temp=temp->next;
    }
   
     temp->next=x;

}

// get the middle node

node* getmiddle(node* &head){
    node* slow=head;
    node* fast=head->next;
    while (fast!=NULL)
    {
         fast=fast->next;
         if(fast!=NULL){
            fast=fast->next;
             slow=slow->next;
         }
        
    }
    return slow;
}

bool checkpalindrom(node* &head){
    //reverse
    node* curr=getmiddle(head)->next;
    node* next=curr->next;
    node* prev=NULL;

    while (curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    node* tail=prev;
    node* chead=head;

    while (tail!=NULL)
    {
        if(chead->data!=tail->data){
            return 0;
        }
        chead=chead->next;
        tail=tail->next;
    }
    
    return 1;
}

void printlinkedlist(node* head){
   
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
 
int main(){
    node* nod=new node(1);
    
    insertatpostion(nod,2,1);
    printlinkedlist(nod);
    cout<<endl;

    insertattail(nod,3);
    printlinkedlist(nod);
    cout<<endl;

     insertattail(nod,1);
     insertattail(nod,2 );

    printlinkedlist(nod);
    cout<<endl;

 
    

    checkpalindrom(nod)? cout<<"palindorm": cout<<"not palidrom";
     cout<<endl;
 printlinkedlist(nod);
}