#include <iostream>
#include <cctype>
#include <sstream>
#include <fstream>
using namespace std;

/**
* Remove space and lowercase input string
*/
string processString(string str) {
    stringstream ss;
    for (char c :  str) 
        if (!isspace(c))    
            ss << (char) tolower(c);
    return ss.str();
}

/**
* This function can check is palindrome
* directly if pre-process string status provided
*/
bool isPalindrome(string str, bool isProcessed) {
    if (!isProcessed) {
        str = processString(str);
        isProcessed = true;
    }
    if (str.length() == 0) return true;
    if (str[0] != str[str.length() - 1]) return false;
    return isPalindrome(str.substr(1, str.length() - 2), isProcessed);
}

/**
* Check if a string is palindrome
*/
bool isPalindrome(string text) {
    // input text is processed once
    string str = processString(text);
    return isPalindrome(str, true);
}

/**
 * This main funciton will check all the lines from user input file
 * if each line text is a palindrome.
 * @author Duc Vo
 * @version 1.0
 */
int main() {
    string text;
    bool result;
    ifstream inputFile;

    cout << "Welcome to the palindrome testing program!\n" << endl;
    cout << "Enter the filename: ";
    getline(cin, text);
    cout << endl;
    inputFile.open(text);
    
    if(inputFile.is_open()) {
        while(getline(inputFile, text)) {
            result = isPalindrome(text);
            cout << text << (result?" is":" is NOT") 
            << " a palindrome." << endl;
        }
    } else {
        cout << "File not found!" << endl;
    }

    inputFile.close();

    cout << "\nThanks for using the palindrome tester!" << endl;

    return 0;
}

