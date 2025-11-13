#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    unordered_map<char, int> count;
    queue<char> q;
    
    for (char ch : str) {
        count[ch]++;
        q.push(ch);
        
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }
        
        if (q.empty()) cout << "-1 ";
        else cout << q.front() << " ";
    }
}

int main() {
    string str = "a a b c";
    cout << "Input: " << str << endl;
    cout << "Output: ";
    firstNonRepeating(str);
    return 0;
}