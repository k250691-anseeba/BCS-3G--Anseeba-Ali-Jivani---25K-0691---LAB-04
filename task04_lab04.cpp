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

Node* mergeTwoSortedLists(Node* h1, Node* h2){
    Node dummy;
    Node* h3 = &dummy;

    Node* temp = h3;
        while(h1 != NULL && h2 != NULL){
            if (h1->data <= h2->data) {
                temp->next = h1;
                h1 = h1->next;
                temp = temp->next;
            }
            else{
                temp->next = h2;
                h2 = h2->next;
                temp = temp->next;
            }
        }
    if(h1!=NULL){
        temp->next = h1;
    }
    else{
        temp->next = h2;
    }

    return h3->next;
}

void displayMerged(Node* h){
    while(h!=NULL){
        cout<<h->data <<" -> ";
        h = h->next;
    }
    cout<<"NULL"<<endl;
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

    l1.display();
    l2.display();
    cout<<"\n Merged List: \n";
    displayMerged(mergeTwoSortedLists(l1.head,l2.head));

    return 0;
}