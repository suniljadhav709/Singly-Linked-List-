// Author : Sunil Jadhav
// Email : suniljadhav709@gmail.com
// Description : Singly linked list implementation [C++]. Just for fun.Hope this is helpful to someone someday.

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;



struct Node{
    Node* next;
    int data;

};


void print_linkedlist(Node *head){

    cout << "Lienked List : " << endl;

    Node *tempPtr = &(*head);

    while(tempPtr!=NULL){
        cout << (*tempPtr).data << " --> ";
        tempPtr = (*tempPtr).next;
    }
    cout << "|NULL| " << endl;
    cout << endl;
}




//Node* insert(int data, Node *head, vector<Node> node_collection){
//    Node *tempPtr = &(*head);
//    if(head==NULL){
//        cout << "header is null" << endl;
//        Node node;
//        node.data = data;
//        node.next = NULL;
//        node_collection.push_back(node);
//        cout << "Element added to collection : { " << node_collection.at(node_collection.size()-1).data << " }" << endl;
//        head = &node_collection.at(node_collection.size()-1);
//        cout << "Header pointer pointing to : " << (*head).data << endl;
//    }else{
//        cout << "header is not null and poining to :  " << (*head).data << endl;
//        cout << "temp pointer pointing to :  " << (*tempPtr).data << endl;

//        while(tempPtr!=NULL){
//            cout << "moving forward" << endl;
//            if((*tempPtr).next == NULL){
//                cout << "NULL pointer." << endl;
//                Node node;
//                node.data = data;
//                node.next = NULL;
//                node_collection.push_back(node);

//                (*tempPtr).next = &node_collection.at(node_collection.size()-1);

//                cout << "Element next to temp pointer is : " << (*(*tempPtr).next).data << endl;

//                //print_linkedlist(head);
//                tempPtr = NULL;
//            }
//            else {
//                tempPtr = (*tempPtr).next ;
//                cout << "M : " << (*tempPtr).data  << endl;
//            }

//            //tempPtr = (*tempPtr).next == NULL ? NULL : (*tempPtr).next;
//            //cout << "after moving forward in the linked list temp pointer pointing to :  " << (*tempPtr).data << endl;
//        }


//    }
//    //cout << "Head is pointing to : " << (*head).data << endl;
//    return head;
//}
Node *head;
vector<Node> node_collection;

void print_operations(){
    cout << "You can perform followig operations" << endl;
    cout << "1.Add to Tail" << endl;
    cout << "2.print" << endl;
    cout << "3.stop" << endl;
    cout << "4.remove Tail" << endl;
    cout << "5.Insert at" << endl;
    cout << "6.Remove at" << endl;
}

void remove(){
    Node *temp;
    temp = &(*head);
    while(temp != NULL){

        if((*(*temp).next).next == NULL){
            (*temp).next = NULL;
            temp =NULL;
        }else {
            temp = (*temp).next;
        }
    }
}
void insert(int data){
    Node *tempPtr;
    tempPtr = &(*head);
    if(head==NULL){
        //cout << "header is null" << endl;
        Node node;
        node.data = data;
        node.next = NULL;
        node_collection.push_back(node);
        head = &node_collection.at(node_collection.size()-1);
        //cout << "Header pointer pointing to : " << (*head).data << endl;
        cout << "Adding Head to : " << (*head).data << endl;
    }else{
        //cout << "header is not null and poining to :  " << (*head).data << endl;
        //cout << "temp pointer pointing to :  " << (*tempPtr).data << endl;

        while(tempPtr!=NULL){
            //cout << "moving forward" << endl;
            if((*tempPtr).next == NULL){
                cout << "INSERTION AFTER :" << (*tempPtr).data << endl;
                Node node;
                node.data = data;
                node.next = NULL;
                node_collection.push_back(node);

                (*tempPtr).next = &node_collection.at(node_collection.size()-1);

                //cout << "Element next to temp pointer is : " << (*(*tempPtr).next).data << endl;
                cout << (*tempPtr).data << " --> " << (*(*tempPtr).next).data << endl;
                //print_linkedlist(head);
                tempPtr = NULL;
            }
            else {
                cout << (*tempPtr).data  << " -->" << (*(*tempPtr).next).data << endl;
                tempPtr = (*tempPtr).next ;
                //cout << "Head pointing to : " << (*head).data  << endl;

            }

            //tempPtr = (*tempPtr).next == NULL ? NULL : (*tempPtr).next;
            //cout << "after moving forward in the linked list temp pointer pointing to :  " << (*tempPtr).data << endl;
        }


    }
    //cout << "Head is pointing to : " << (*head).data << endl;

}

void insert_at(int index, int item){
    int counter = 1;
    Node *temp ;
    temp = &(*head);
    while((*temp).next != NULL && (counter!=index-1)){
        temp = (*temp).next;
        ++counter;
    }
    if(counter == index-1){
        Node *prev_next;
        prev_next = (*temp).next == NULL ? NULL : (*temp).next;

        Node *new_next;
        Node newNode;
        newNode.data = item;
        newNode.next = prev_next == NULL ? NULL : prev_next;
        node_collection.push_back(newNode);
        new_next = &(node_collection.at(node_collection.size()-1));
        (*temp).next = new_next;
        temp = NULL;

    }else{
        cout << "please enter valid index" <<  endl;
    }
}

void replace_at(int index, int item){
    int counter = 1;
    Node *temp ;
    temp = &(*head);
    while((*temp).next != NULL && (counter!=index-1)){
        temp = (*temp).next;
        ++counter;
    }
    if(counter == index-1){
        Node *prev_next;
        prev_next = (*(*temp).next).next == NULL ? NULL : (*(*temp).next).next;

        Node *new_next;
        Node newNode;
        newNode.data = item;
        newNode.next = prev_next == NULL ? NULL : prev_next;
        node_collection.push_back(newNode);
        new_next = &(node_collection.at(node_collection.size()-1));
        (*temp).next = new_next;
        temp = NULL;

    }else{
        cout << "please enter valid index" <<  endl;
    }
}

void remove_at(int index){
    int counter = 1;
    Node *temp ;
    temp = &(*head);
    while((*temp).next != NULL && (counter!=index-1)){
        temp = (*temp).next;
        ++counter;
    }
    if(counter == index-1){
        Node *potential_next;
        potential_next = (*(*temp).next).next == NULL ? NULL : (*(*temp).next).next;
        (*temp).next = potential_next == NULL ? NULL : potential_next;
    }else{
        cout << "please enter valid index" <<  endl;
    }
}


int main()
{

    head = NULL;
    int _operation = 0;

    cout << "Welcome to Linked list tutorial" << endl;


    while(_operation != 3){
        //int msg = head == NULL ? -1: (*head).data ;
        //cout << "BEFORE printing operations head is pointing to : " << msg << endl;
        print_operations();

        cin >> _operation;

        if(_operation == 2)
            print_linkedlist(head);
        else if(_operation == 1){
            int _xdata = 0;

            //cout << "BEFORE asking for data head is pointing to : " << msg << endl;
            cout << "enter element to be stored." << endl;
            cin >> _xdata;

            //cout << "BEFORE insert head pointing to : " << msg << endl;
            insert(_xdata);
            //cout << "head is pointing to : " << (*head).data << endl;
        }else if(_operation == 4){
            // remove from tail
            remove();
        }else if(_operation == 5){
            // Add on an index
            cout << "Enter Index " << endl;
            int index, item;
            cin >> index;
            cout << "Enter number " << endl;
            cin >> item;
            insert_at(index,item);
        }else if(_operation == 6){
            // remove from an index
            cout << "Enter Index " << endl;
            int index;
            cin >> index;
            remove_at(index);
        }
    }
    //    int sdigit;
    //    float sfloat;

    //    scanf("%d %f", &sdigit, &sfloat);
    //    cout << "Digit : " << sdigit << endl;
    //    cout << "Float : " << sfloat << endl;
    //    float sum = sdigit + sfloat;
    //    printf("%d + %f = %f" , sdigit,sfloat, sum);
    return 0;
}

