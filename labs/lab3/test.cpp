#include <iostream>
using namespace std;
bool isPalindrome(string str) {
    if (str.length() == 0) return true;
    if (str[0] != str[str.length() - 1]) return false;
    return isPalindrome(str.substr(1, str.length() - 2));
}

int main() {
    string text = "taat";
    cout << text << (isPalindrome(text)?" is":" is NOT")
         << " a palindrome." << endl;
    return 0;
}

