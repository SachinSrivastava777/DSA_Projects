#include<iostream>
using namespace std;

struct node {
    string song;
    node* next;
};

void addsong(node* &head, string song) {
    node* newnode = new node;
    newnode->song = song;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}

void deletesong(node* &head, string song) {
    if (head == NULL) {
        cout << "Playlist empty\n";
        return;
    }

    node* temp = head;
    node* prev = NULL;

    do {
        if (temp->song == song) {
            if (temp == head) {
                node* last = head;
                while (last->next != head) last = last->next;

                if (head->next == head) {
                    delete head;
                    head = NULL;
                    return;
                }

                last->next = head->next;
                node* del = head;
                head = head->next;
                delete del;
            } else {
                prev->next = temp->next;
                delete temp;
            }
            cout << "Removed: " << song << "\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    cout << "Song not found\n";
}

void displaysongs(node* head) {
    if (head == NULL) {
        cout << "Playlist empty\n";
        return;
    }

    node* temp = head;
    int i = 1;

    do {
        cout << i++ << ". " << temp->song << "\n";
        temp = temp->next;
    } while (temp != head);
}

void playnext(node* &head) {
    if (head == NULL) {
        cout << "\nPlaylist empty\n";
        return;
    }

    cout << "Now Playing: " << head->song << "\n";
    head = head->next;
}

int main() {
    node* head = NULL;

    cout << "🎧 Playlist Manager Started\n";

    while (1) {
        cout << "\n-----------------------------\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Show Playlist\n";
        cout << "4. Play Next\n";
        cout << "5. Exit\n";
        cout << "-----------------------------\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string song;
            cout << "Enter song: ";
            getline(cin >> ws, song);
            addsong(head, song);
            cout << "Added: " << song << "\n";
        }
        else if (choice == 2) {
            string song;
            cout << "Enter song to remove: ";
            getline(cin >> ws, song);
            deletesong(head, song);
        }
        else if (choice == 3) {
            cout << "\n🎵 Playlist:\n";
            displaysongs(head);
        }
        else if (choice == 4) {
            playnext(head);
        }
        else if (choice == 5) {
            cout << "Goodbye 🎶\n";
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
}