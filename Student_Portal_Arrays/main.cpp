#include<iostream>
#include<cmath>
using namespace std;
struct Student {
    string name;
    int age;
    string grade;
    int id;
};

struct Student s[100];
int count = 0;

int main(){
    while(1){
        cout << "Choose the option: 1. Add a student 2. Display students 3. Exit 4. Update student details" << endl;

        int option;
        cin >> option;

        if(option == 1){

            cout << "Adding a student..." << endl;
            // Code to add a student
            cout << "Enter student name: ";
            cin >> s[count].name;
            cout << "Enter student age: ";
            cin >> s[count].age;
            cout << "Enter student grade: ";
            cin >> s[count].grade;
            cout << "Enter student ID: ";
            cin >> s[count].id;
            count++;


        }
        else if(option == 2){
            cout << "Displaying students..." << endl;
            // Code to display students
            for(int i = 0; i<count; i++){
                cout << "Name: " << s[i].name << ", Age: " << s[i].age << ", Grade: " << s[i].grade << ", ID: " << s[i].id << endl;
            }
        }
        else if(option == 3){
            cout << "Exiting..." << endl;
            break;
        }
        else if(option == 4){
            cout << "Updating student details..." << endl;
            // Code to update student details
            int id;
            cout << "Enter student ID to update: ";
            cin >> id;
            bool found = false;
            for(int i = 0; i<count; i++){
                if(s[i].id == id){
                    found = true;
                    cout << "Enter new name: ";
                    cin >> s[i].name;
                    cout << "Enter new age: ";
                    cin >> s[i].age;
                    cout << "Enter new grade: ";
                    cin >> s[i].grade;
                    break;
                }
            }
        }
        else{
            cout << "Invalid option. Please try again." << endl;
        }
    }
}