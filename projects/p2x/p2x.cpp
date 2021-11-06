#include <iostream>
#include <fstream>
#include "BSTx.h"
using namespace std;

template <typename T>
void displayTreeStats(BST<T> &);
template <typename T>
void displayOrderTraversal(BST<T> &);
template <typename T>
void displayLevelAndAncestors(BST<T> &, T);

int main() {
    ifstream inputFile;
    string fileName, str;
    int input;
    string sInput;
    int testArr[] = {20, 40, 10, 70, 99, -2, 59, 43};
    string testStringArr[] = {"gene", "mary", "bea", "uma", "yan", "amy", "ron", "opal"};


    cout << "Welcome to Binary Search Tree" << endl << endl;
    cout << "******************************" << endl;
    cout << "* INTEGER BINARY SEARCH TREE *" << endl;
    cout << "******************************" << endl ;

    cout << endl << "*********************\n"
                    "* TEST INTEGERS BST *\n"
                    "*********************\n" << endl;
    cout << "** CREATE BST **" << endl;
    BST<int> intBST;

    displayTreeStats(intBST);

    fileName = "integers.dat";
    inputFile.open(fileName);
    if(!inputFile.is_open()) {
        cout << "\nEnter integer file: ";
        getline(cin, fileName);
        inputFile.open(fileName);
        if(!inputFile.is_open()) {
            cerr << "Could not open the file - " << fileName << endl;
            return EXIT_FAILURE;
        }
    }
    cout << endl;

    cout << "** TEST INSERT **" << endl;

    cout << "Inserting in this order: ";
    while (inputFile >> input) {
        cout << input << " ";
        intBST.insert(input);
    }
    cout << endl;
    displayTreeStats(intBST);
    cout << endl;

    cout << "** TEST TRAVERSALS **" << endl;
    displayOrderTraversal(intBST);
    cout << endl;

    cout << "** TEST LEVEL & ANCESTORS **" << endl;
    str = intBST.getPreOrderTraversal();
    stringstream ss(str);

    while(ss >> input)
        displayLevelAndAncestors(intBST, input);

    cout << endl;

    cout << "** TEST CONTAINS **" << endl;
    for (int val : testArr) {
        cout << "contains(" << val <<"): "
             << (intBST.contains(val)?"true":"false") << endl;
    }
    cout << endl;

    cout << "** TEST REMOVE **" << endl;
    cout << "Removing in this order: ";
    for (int val : testArr) {
        cout << val << " ";
        intBST.remove(val);
    }
    cout << endl;
    displayTreeStats(intBST);
    displayOrderTraversal(intBST);
    cout << endl;

    cout << "** TEST INSERT (again) **" << endl;
    cout << "Inserting in this order: ";
    for (int val : testArr) {
        cout << val << " ";
        intBST.insert(val);
    }
    cout << endl;
    displayTreeStats(intBST);
    displayOrderTraversal(intBST);

    inputFile.close();
    cout << "\n==================================================" << endl;

    cout << endl << "********************\n"
                    "* test string BST  *\n"
                    "********************\n";

    cout << "** CREATE BST **" << endl;
    BST<string> stringBST;

    displayTreeStats(stringBST);

    fileName = "strings.dat";
    inputFile.open(fileName);
    if(!inputFile.is_open()) {
        cout << "\nEnter strings file: ";
        getline(cin, fileName);
        inputFile.open(fileName);
        if(!inputFile.is_open()) {
            cerr << "Could not open the file - " << fileName << endl;
            return EXIT_FAILURE;
        }
    }
    cout << endl;

    cout << "** TEST INSERT **" << endl;

    cout << "Inserting in this order: ";
    while (inputFile >> sInput) {
        cout << sInput << " ";
        stringBST.insert(sInput);
    }
    cout << endl;
    displayTreeStats(stringBST);
    cout << endl;

    cout << "** TEST TRAVERSALS **" << endl;
    displayOrderTraversal(stringBST);
    cout << endl;

    cout << "** TEST LEVEL & ANCESTORS **" << endl;
    str = stringBST.getPreOrderTraversal();
    ss.clear();
    ss.str(str);
    while(ss >> str) {
        displayLevelAndAncestors(stringBST, str);
    }
    cout << endl;

    cout << "** TEST CONTAINS **" << endl;
    for (string val : testStringArr) {
        cout << "contains(" << val <<"): "
             << (stringBST.contains(val)?"true":"false") << endl;
    }
    cout << endl;

    cout << "** TEST REMOVE **" << endl;
    cout << "Removing in this order: ";
    for (string val : testStringArr) {
        cout << val << " ";
        stringBST.remove(val);
    }
    cout << endl;

    displayTreeStats(stringBST);
    displayOrderTraversal(stringBST);
    cout << endl;

    cout << "** TEST INSERT (again) **" << endl;
    cout << "Inserting in this order: ";
    for (string val : testStringArr) {
        cout << val << " ";
        stringBST.insert(val);
    }
    cout << endl;
    displayTreeStats(stringBST);
    displayOrderTraversal(stringBST);

    cout << endl << "TEST CONSTRUCTOR COPY METHODS" << endl;
    BST<string> st(stringBST);
    cout<< "COPIED STRING TREE STATS: " << endl;
    displayTreeStats(st) ;
    BST<int> st2(intBST);
    cout<< "COPIED INTEGER TREE STATS: " << endl;
    displayTreeStats(st2) ;

    cout << "TEST OVERLOAD = OPERATOR" << endl;
    BST<int> bst;
    bst = intBST;
    cout<< "= OPERATOR INT TREE STATS: " << endl;
    displayTreeStats(bst) ;
    BST<string> bst2;
    bst2 = stringBST;
    cout<< "= OPERATOR STRING TREE STATS: " << endl;
    displayTreeStats(bst2) ;

    cout << endl << "GoodBye!" << endl;

    inputFile.close();
    return 0;
}

template <typename T>
void displayTreeStats(BST<T> &obj) {
    cout <<
        "# of nodes:  " << obj.size() << endl <<
        "# of leaves: " << obj.getLeafCount() << endl <<
        "BST height:  " << obj.getHeight() << endl <<
        "BST width:   " << obj.getWidth() << endl <<
        "BST empty?   " << (obj.empty() ? "true" : "false") << endl;
}

template <typename T>
void displayOrderTraversal(BST<T> &obj) {
    cout <<
    "pre-order:   " << obj.getPreOrderTraversal() << endl <<
    "in-order:    " << obj.getInOrderTraversal() << endl <<
    "post-order:  " << obj.getPostOrderTraversal() << endl <<
    "level-order: " << obj.getLevelOrder() << endl;
}

template <typename T>
void displayLevelAndAncestors(BST<T> &obj, T val) {
    cout <<
    "level(" << val << "): " << obj.getLevel(val) << ", "
    "ancestors(" << val << "): " << obj.getAncestors(val) << endl;
}