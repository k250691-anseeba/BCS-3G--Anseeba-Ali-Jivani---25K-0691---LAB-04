#include<iostream>
using namespace std;

class Record{
    public:
    int patientID;
    int severityScore;
    Record* next;
    Record* prev;

    Record(int id, int score){
        next = prev = NULL;
        patientID = id;
        severityScore = score;
    }
};

class DoublyLinkedList{
    public:
    Record* head;
    Record* tail;

    DoublyLinkedList(){
        head=tail=NULL;
    }
};

Record* getNode(Record* h, int position){
    Record* temp = h;

    for(int i=0; i<position; i++){
        temp = temp->next;
    }

    return temp;
}

void swapNodes(Record*& head, Record*& tail, Record* a, Record* b){
    if(a == b)
        return;

    Record* ap = a->prev;
    Record* an = a->next;
    Record* bp = b->prev;
    Record* bn = b->next;

    if(a->next == b){
        if(ap != NULL)
            ap->next = b;
        else
            head = b;

        if(bn != NULL)
            bn->prev = a;
        else
            tail = a;

        b->prev = ap;
        b->next = a;
        a->prev = b;
        a->next = bn;
    }
    else if(b->next == a){
        swapNodes(head, tail, b, a);
    }
    else{
        if(ap != NULL)
            ap->next = b;
        else
            head = b;

        if(an != NULL)
            an->prev = b;

        if(bp != NULL)
            bp->next = a;
        else
            head = a;

        if(bn != NULL)
            bn->prev = a;

        a->prev = bp;
        a->next = bn;

        b->prev = ap;
        b->next = an;
    }
}

void ShellSort(Record*& head, Record*& tail){
    int count = 0;
    Record* temp = head;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    int gap = count / 2;

    while(gap >= 1){
        for(int i=gap; i<count; i++){
            int j=i;

            while(j>=gap){
                Record* previous = getNode(head, j-gap);
                Record* current = getNode(head, j);

                if(previous->severityScore <= current->severityScore)
                    break;

                swapNodes(head, tail, previous, current);

                j = j-gap;
            }
        }

        gap = gap/2;
    }
}

int main(){
    DoublyLinkedList list;

    Record* a = new Record(101, 50);
    Record* b = new Record(102, 20);
    Record* c = new Record(103, 80);
    Record* d = new Record(104, 10);
    Record* e = new Record(105, 60);
    Record* f = new Record(106, 30);

    list.head = a;
    list.tail = f;

    a->next = b;
    b->prev = a;

    b->next = c;
    c->prev = b;

    c->next = d;
    d->prev = c;

    d->next = e;
    e->prev = d;

    e->next = f;
    f->prev = e;

    ShellSort(list.head, list.tail);

    Record* temp = list.head;

    cout << "NULL <- ";

    while(temp != NULL){
        cout << "[ID:" << temp->patientID
             << ", Sev:" << temp->severityScore << "]";

        if(temp->next != NULL)
            cout << " <-> ";

        temp = temp->next;
    }

    cout << " -> NULL";

    return 0;
}