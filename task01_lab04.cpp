#include<iostream>
using namespace std;

class Song{
    int data;
    Song* next;

    public:
    Song(int val){
        next = NULL;
        data = val;
    }
    void setNext(Song* n){
        next = n;
    }
    Song* getNext(){
        return next;
    }
    int getData(){
        return data;
    }
};
class RecentlyPlayed{
    Song* head;
    public:
    RecentlyPlayed(){
        head= NULL;
    }
    Song*& getHead(){
        return head;
    }
    void addSong(int val){
        Song* newSong= new Song(val);
        if(head==NULL){
            head= newSong;
            return;
        }
        newSong->setNext(head);
        head = newSong;
    }
    void display(){
        Song* temp = head;
        while(temp!=NULL){
            cout<<temp->getData()<<" -> ";
            temp = temp->getNext();
        }
        cout<<"NULL" <<endl;
    }
};

Song* reverse(Song*& h){
    Song* prev = NULL;
    Song* nex = NULL;
    Song* curr = h;

    while(curr!= NULL){
        nex = curr->getNext();
        curr->setNext(prev);
        prev = curr;
        curr = nex;
    }
    h = prev;
    return h;
}


int main(){
    RecentlyPlayed p1;
    p1.addSong(10);
    p1.addSong(20);
    p1.addSong(30);
    p1.addSong(40);
    p1.addSong(50);
    cout<<"BEFORE:\n";
    p1.display();
    reverse(p1.getHead());
    cout<<"AFTER:\n";
    p1.display();

    return 0;
}