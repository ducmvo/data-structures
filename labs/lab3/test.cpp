#include <iostream>
using namespace std;
bool isPalindrome(string str) {
    int strLen = str.length();
    int lastIdx = strLen - 1;
    char firstChar = str[0];
    char lastChar = str[lastIdx];
    string substr;

    if (strLen == 0) return true;
    if (firstChar != lastChar) return false;
    substr = str.substr(1, lastIdx - 1);
    return isPalindrome(substr);
}

int main() {
    string text;
    bool result;
    text = "tacocat";
    result = isPalindrome(text);
    cout << text << (result?" is":" is NOT")
         << " a palindrome." << endl;
    return 0;
}

