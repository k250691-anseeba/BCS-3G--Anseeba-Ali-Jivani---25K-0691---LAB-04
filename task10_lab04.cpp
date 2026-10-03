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

bool detectCycle(Node* head){
    Node* fast = head;
    Node* slow= head;
    while(fast!=NULL && fast->next!=NULL){
    fast = fast->next->next;
    slow = slow->next;
    if(fast == slow){
        return true;        
    }
}
return false;
}

void breakCycle(Node*head){
    if(head!=NULL && head->next==head){
        head->next =NULL;
        return;
    }
    if(!detectCycle(head)){
        return;
    }

    Node* fast = head;
    Node* slow= head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){
            break;
        }
    }
    slow = head;

    do{
        slow=slow->next;
        fast = fast->next;
    }while(fast!=slow);

    while(slow->next!=fast){
        slow=slow->next;
    }
    slow->next = NULL;
}


int main() {

    LinkedList list;
    list.addNodeatFront(6);
    list.addNodeatFront(5);
    list.addNodeatFront(4);
    list.addNodeatFront(3);
    list.addNodeatFront(2);
    list.addNodeatFront(1);

    Node* temp = list.head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = list.head->next->next;

    cout<<boolalpha;
    cout<<"Cycle: "<<detectCycle(list.head)<<endl;
    
    cout<<"Breaking cycle: "<<endl;
    breakCycle(list.head);
    list.display();


    return 0;
}