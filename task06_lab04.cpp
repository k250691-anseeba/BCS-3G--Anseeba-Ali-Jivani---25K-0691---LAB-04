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

void odd_evenID(Node*& h){
    Node dummy1;
    Node dummy2;
    Node* even = &dummy1;
    Node* odd = &dummy2;

    Node* temp = h;
    Node* eventemp = even;
    Node* oddtemp = odd;
    while(temp!=NULL){
        if(temp->data % 2 == 0){
            eventemp->next = temp;
            eventemp = temp;
        }
        else{
            oddtemp->next = temp;
            oddtemp = temp;
        }
        temp = temp->next;
    }
    oddtemp->next = NULL;
    eventemp->next = NULL;
    
    oddtemp = odd;
    h = odd->next;
    while(oddtemp->next!=NULL){
        oddtemp=oddtemp->next;
    }
    oddtemp->next = even->next;

}

int main(){
    LinkedList l1;
    l1.addNodeatFront(7);
    l1.addNodeatFront(4);
    l1.addNodeatFront(6);
    l1.addNodeatFront(5);
    l1.addNodeatFront(3);
    l1.addNodeatFront(1);
    l1.addNodeatFront(2);
    l1.display();

    odd_evenID(l1.head);
    l1.display();

    return 0;
}