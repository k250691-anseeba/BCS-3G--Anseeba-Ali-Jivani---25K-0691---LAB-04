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
Node* middle(Node* head){
    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        prev = slow;
        slow= slow->next;
    }
    return slow;
}

bool mirrorSeq(Node* head){  
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    temp=head;
    int j=count/2;
    Node*middleofll = middle(head);
    if(count%2 == 0){
        j--;
    }
    while(temp!=middleofll){
    Node* mid = middleofll;
    for(int i = j; i>0; i--){
        mid=mid->next;
    }
    if(mid->data != temp->data){
        cout<<"Invalid";
        return false;
    }
     temp =temp->next;
     j--;
    }

    return true;
}

int main(){
    LinkedList l1;
    l1.addNodeatFront(1);
    l1.addNodeatFront(2);
    l1.addNodeatFront(3);
    l1.addNodeatFront(2);
    l1.addNodeatFront(1);
    l1.display();

    bool result = mirrorSeq(l1.head);
    cout<<boolalpha;
    cout<<"Result: "<<result<<endl;

    LinkedList l2;
    l2.addNodeatFront(3);
    l2.display();
    result = mirrorSeq(l2.head);
    cout<<boolalpha;
    cout<<"Result: "<<result<<endl;

    LinkedList l3;
    l3.addNodeatFront(9);
    l3.addNodeatFront(0);
    l3.addNodeatFront(0);
    l3.addNodeatFront(9);
    l3.display();
    result = mirrorSeq(l3.head);
    cout<<boolalpha;
    cout<<"Result: "<<result<<endl;

    return 0;
}