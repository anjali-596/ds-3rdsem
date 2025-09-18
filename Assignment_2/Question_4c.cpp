#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = "";
    for (int i = 0; i < str.size(); i++) {
        if (!isVowel(str[i])) {
            result += str[i];
        }
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}