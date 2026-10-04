#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = prev = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = tail = NULL;
    }
};

int countTriplets(Node* head, int X){
    int count = 0;

    Node* first = head;

    while(first != NULL){
        Node* second = first->next;

        while(second != NULL){
            Node* third = second->next;

            while(third != NULL){
                if(first->data + second->data + third->data == X)
                    count++;

                third = third->next;
            }

            second = second->next;
        }

        first = first->next;
    }

    return count;
}

int main(){
    DoublyLinkedList list;

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    list.head = a;
    list.tail = e;

    a->next = b;
    b->prev = a;

    b->next = c;
    c->prev = b;

    c->next = d;
    d->prev = c;

    d->next = e;
    e->prev = d;

    int X = 6;

    cout << "Matching: " << countTriplets(list.head, X);

    return 0;
}