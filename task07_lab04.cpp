#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        next =  prev = NULL;
        data = x;
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head = tail = NULL;
    }
    void addNodeatLast(int x){
        Node* newNode = new Node(x);
        if(head==NULL){
            head= tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
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

void removeDuplicates(Node*& head){
    if(head==NULL || head->next == NULL){
        return;
    }

    Node* temp = head;
    while(temp!=NULL){
        Node* mov = temp->next;
        while(mov!=NULL){
            if(temp->data == mov->data){
                //delete move
                Node* duplicate = mov;
                mov =mov->next;
                if(duplicate->next == NULL){
                    duplicate->prev->next = NULL;
                    delete duplicate;
                }
                else{
                duplicate->next->prev = duplicate->prev;
                duplicate->prev->next = duplicate->next;
                duplicate->prev = duplicate->next =NULL;
                delete duplicate;
                }
            }
            else{
                mov =mov->next;
            }
        }
        temp = temp->next;
    }

}

int main(){
    DoublyLinkedList d;
    d.addNodeatLast(1);
    d.addNodeatLast(2);
    d.addNodeatLast(3);
    d.addNodeatLast(2);
    d.addNodeatLast(2);
    d.addNodeatLast(1);
    d.addNodeatLast(1);
    d.addNodeatLast(4);
    d.addNodeatLast(4);
    d.display();
    
    removeDuplicates(d.head);
    d.display();

    return 0;
}



