#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome(string input) {
    stack<char> s;
    int len = input.length();

    for (int i = 0; i < len; i++) {
        s.push(input[i]);
    }

    for (int i = 0; i < len; i++) {
        if (s.top() != input[i]) {
            return false;
        }
        s.pop();
    }

    return true;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << input << " adalah palindrome." << endl;
    } else {
        cout << input << " bukan palindrome." << endl;
    }

    return 0;
}