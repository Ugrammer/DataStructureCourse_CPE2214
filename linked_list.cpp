#include<iostream>
#include<string>
#include<list>
using namespace std;
struct node{
    int data;
    node *next; // เก็บ address ของ node ถัดไป
    
};
class myList{
    
public:
    node* head;
    node* tail;
    int dataSize;
    myList();
    void push_front(int data);
    void printList();
    void insert(int ith, int data);
    ~myList();
};
myList::myList(){
    head = new node;
    tail = head;
    head->next = nullptr;
    dataSize =0;
}
void myList::push_front(int data){
    node *newNode = new node;
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
    if (newNode->next == nullptr){
        tail = newNode;
    }
    dataSize++;
}
void myList::printList(){
    node *temp;
    temp = head;
    for(int i = 0;temp!= nullptr;i++){
        cout<<temp<<"|"<<temp->data<<"|"<<temp->next<<endl;
        temp = temp->next;
    }
}
void myList::insert(int ith,  int data){
    node *newNode;
    node *temp;
    newNode = new node;
    temp = head;
    newNode->data = data;
    for (int i= 1;i<ith;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    dataSize++;
}
myList::~myList(){
    node *temp;
    node *dtemp;
    temp = head;
    cout<<"now deleting all"<<endl;
    while(temp!=nullptr){
        dtemp = temp;
        temp = temp->next;
        cout<<"delete = "<<dtemp<<endl;
        delete dtemp;
    }
}
int main(){
    myList l1;
   // cout<<l1.head<<endl;
   // cout<<l1.head->next<<endl;
   // l1.push_front(7);
   // l1.push_front(6);
   // l1.printList();
    for(int i = 1;i<=100;i++){
        l1.push_front(i);
    }
    l1.insert(10, 120);
    l1.printList();
    cout<<"tail is "<<l1.tail<<endl;
    cout<<"data size = "<<l1.dataSize<<endl;
   // cout<<l1.head<<"|"<<l1.head->data<<"|"<<l1.head->next<<endl;
   // cout<<l1.head->next<<"|"<<l1.head->next->data<<"|"<<l1.head->next->next<<endl;
    return 0;
}

