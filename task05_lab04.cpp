#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        next =  NULL;
        data = x;
    }
    Node(){}
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void addNodeatFront(int x){
        Node* newNode = new Node(x);
        if(head==NULL){
            head= newNode;
            return;
        }
        newNode->next = head;
        head =newNode;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

Node* intersection(Node* h1, Node* h2){
    Node* temph1 = h1;
    Node* temph2 = h2;
    while(temph1!=NULL){
        temph2 = h2;
        while(temph2!=NULL){
        if(temph1 == temph2){
            if(temph1 !=NULL)
            return temph1;
        }
        temph2=temph2->next;
    }
        temph1=temph1->next;
    }
    return NULL;
}

int main(){
    LinkedList l1;
    l1.addNodeatFront(7);
    l1.addNodeatFront(5);
    l1.addNodeatFront(3);
    l1.addNodeatFront(1);

    LinkedList l2;
    l2.addNodeatFront(8);
    l2.addNodeatFront(6);
    l2.addNodeatFront(4);
    l2.addNodeatFront(2);
    l2.head->next->next->next->next = l1.head->next->next;
    
    l1.display();
    l2.display();
    Node* result = intersection(l1.head,l2.head);
    if(result){
        cout<<"["<<result->data<<"]"<<endl;
    }
    else{
        cout<<"No intersection"<<endl;
    }

    return 0;
}