#include<iostream>
using namespace std;

struct node{
    string name;
    string phone_number;
    node* next;
};

typedef node* NODE;

NODE add_contact(NODE head){
    NODE newnode = new node;
    
    cout<<"Enter name: ";
    cin>>newnode->name;
    
    cout<<"Enter phone number: ";
    cin>>newnode->phone_number;
    
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        NODE temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

void display(NODE head){
    if(head == NULL){
        cout<<"No contacts found\n";
        return;
    }

    NODE temp = head;
    while(temp != NULL){
        cout<<"------------------\n";
        cout<<"Name: "<<temp->name<<endl;
        cout<<"Phone: "<<temp->phone_number<<endl;
        temp = temp->next;
    }
}

NODE delete_contact(NODE head){
    if(head == NULL){
        cout<<"No contacts found\n";
        return head;
    }

    string name;
    cout<<"Enter name to delete: ";
    cin>>name;

    NODE temp = head;
    NODE prev = NULL;

    while(temp != NULL){
        if(temp->name == name){
            if(prev == NULL){
                head = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            delete temp;
            cout<<"Deleted successfully\n";
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    cout<<"Contact not found\n";
    return head;
}
int main(){
    NODE head = NULL;
    int choice;

    do{
        cout<<"1. Add Contact\n";
        cout<<"2. Display Contacts\n";
        cout<<"3. Delete Contact\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                head = add_contact(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = delete_contact(head);
                break;
            case 4:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice, try again.\n";
        }
    } while(choice != 4);

    return 0;
}