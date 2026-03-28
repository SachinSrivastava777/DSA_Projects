#include <bits/stdc++.h>
using namespace std;

int printerQueue(vector<int>& priorities, int target) {
    queue<pair<int,int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }

    int time = 0;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        bool hasHigher = false;

        queue<pair<int,int>> temp = q;
        while (!temp.empty()) {
            if (temp.front().first > current.first) {
                hasHigher = true;
                break;
            }
            temp.pop();
        }

        if (hasHigher) {
            q.push(current);
        } else {
            time++;

            if (current.second == target) {
                return time;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> priorities;
    cout << "Enter the priorities of the 5 print jobs: ";
    for(int i = 0; i < 5; i++) {
        int p;
        cin >> p;
        priorities.push_back(p);
    }
    int target;
    cout << "Enter the index of the target print job (0-4): ";
    cin >> target;
    cout << printerQueue(priorities, target);
    return 0;
}