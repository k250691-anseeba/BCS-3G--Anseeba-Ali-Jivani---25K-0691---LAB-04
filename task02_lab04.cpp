#include<iostream>
using namespace std;

class Student{
    public:
    int rollno;
    Student* next;

    Student(int r){
        next =NULL;
        rollno = r;
    }
};
class List{
    public:
    Student* head;
    Student* tail;
    List(){
        head=tail=NULL;
    }
    void addStudent(int x){
        Student* newStudent = new Student(x);
        if(head==NULL){
            head= tail =newStudent;
            return;
        }
        tail->next = newStudent;
        tail = newStudent;
    }
    void display(){
    Student* temp = head;
    while(temp!=NULL){
        cout<<temp->rollno<<" -> ";
        temp=temp->next;
    }
        cout<<"NULL"<<endl;
    }
};

Student* middle(Student* head){
    Student* fast = head;
    Student* slow = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow= slow->next;
    }
    return slow;
}


int main(){
    List l1;
    l1.addStudent(1);
    l1.addStudent(2);
    l1.addStudent(3);
    l1.addStudent(4);
    l1.addStudent(5);
    int l1middle = middle(l1.head)->rollno;

    List l2;
    l2.addStudent(1);
    l2.addStudent(2);
    l2.addStudent(3);
    l2.addStudent(4);
    l2.addStudent(5);
    l2.addStudent(6);
    int l2middle = middle(l2.head)->rollno;

    l1.display();
    cout<<"MIDDLE: "<<l1middle<<endl;
    l2.display();
    cout<<"MIDDLE: "<<l2middle<<endl;

    return 0;
}