//
// Created by Duc Vo on 10/23/21.
//

#ifndef P2_BST_H
#define P2_BST_H
#include <sstream>
using namespace std;

template <typename T>
class BST {
public:
    BST();                                    // Constructor
    ~BST();                                   // Destructor
    BST(BST &);                               // Copy Constructor
    const BST<T> &operator=(BST<T> &);        // Overload = constructor
    void insert(T val);                       // insert a Node
    bool contains(T val);                     // determines if node in tree
    bool remove(T val);                       // remove a Node
    bool empty();                             // determines if BST is empty
    int size();                               // count of nodes in BST
    int getLeafCount();                       // count of nodes without children
    int getHeight();                          // height of BST. 0 if BST empty
    int getLevel(T val);                      // level of a node in BST
    string getAncestors(T val);               // string of ancestors
    string getInOrderTraversal();             // string of in-order elements
    string getPreOrderTraversal();            // string of pre-order elements
    string getPostOrderTraversal();           // string of post-order elements
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };
    Node* root;                                // Root node of BST
    int treeSize;                              // hold size of the tree
    void destroy(Node* &);                     // delete tree
    void insert(T, Node* &);                   // insert new node to a tree
    void copy(Node* &, Node* &);               // copy a tree
    bool contains(T, Node* &);                 // check if tree contain a node
    bool remove(T val, Node* &);               // remove a Node
    int size(Node* &, int &);                  // get total node of the tree
    int getLeafCount(Node* &, int &);          // get total node of the tree
    int getHeight(Node* &);                    // get height the tree
    int getLevel(T val, Node* &);
    void getAncestors(T val, stringstream &ss, Node* &node);
    void getOrderTraversal(Node* &, stringstream &, string); //ordered traversal
};


// CONSTRUCTOR METHODS
template <typename T>
BST<T>::BST() {
    root = nullptr;
    treeSize = 0;
}

template <typename T>
BST<T>::~BST() {
    destroy(root);
}

template <typename T>
BST<T>::BST(BST &obj) {
   copy(root, obj.root);
   treeSize = obj.treeSize;
}

template <typename T>
const BST<T> & BST<T>::operator=(BST &obj) {
    if (this != &obj) {
        if (root != nullptr) destroy(root);
        copy(root, obj.root);
        treeSize = obj.treeSize;
    }
    return *this;
}

//PUBLIC METHODS
template <typename T>
void BST<T>::insert(T val) {
    insert(val, root);
}

template <typename T>
bool BST<T>::contains(T val) {
    if (empty()) return false;
    return contains(val, root);
}

template <typename T>
bool BST<T>::remove(T val) {
    return remove(val, root);
}

template <typename T>
bool BST<T>::empty() {
    return root == nullptr;
}

template <typename T>
int BST<T>::size() {
    int count = 0;
    return size(root, count);
//  return treeSize; // note: treeSize can be used instead
}

template <typename T>
int BST<T>::getLeafCount() {
    int count = 0;
    return getLeafCount(root, count);
}

template <typename T>
int BST<T>::getHeight() {
    return getHeight(root);
}

template <typename T>
int BST<T>::getLevel(T val) {
    return getLevel(val, root);
}

template <typename T>
string BST<T>::getAncestors(T val) {
    stringstream ss;
    getAncestors(val, ss, root);
    return ss.str();
}

template <typename T>
string BST<T>::getPreOrderTraversal() {
    stringstream ss;
    getOrderTraversal(root, ss, "pre");
    return ss.str();
}

template <typename T>
string BST<T>::getInOrderTraversal() {
    stringstream ss;
    getOrderTraversal(root, ss, "in");
    return ss.str();
}

template <typename T>
string BST<T>::getPostOrderTraversal() {
    stringstream ss;
    getOrderTraversal(root, ss, "post");
    return ss.str();
}

// PRIVATE METHODS
template <typename T>
void BST<T>::destroy(Node* &node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
    node = nullptr;
    treeSize--;
}

template <typename T>
void BST<T>::insert(T val, Node* &node) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->left = newNode->right= nullptr;
        node = newNode;
        treeSize++;
    } else if (val != node->data)
        insert(val, val > node->data ? node->right: node->left);
}

template <typename T>
void BST<T>::copy(Node* &targetNode, Node* &originalNode) {
    if (originalNode == nullptr) targetNode = nullptr;
    else {
        targetNode = new Node;
        targetNode->data = originalNode->data;
        copy(targetNode->left, originalNode->left);
        copy(targetNode->right, originalNode->right);
    }
}

template <typename T>
bool BST<T>::contains(T val, Node* &node) {
    if (node == nullptr) return false;
    if (node->data == val) return true;
    return contains(val, val>node->data?node->right:node->left);
}

template <typename T>
bool BST<T>::remove(T val, Node* &node) {
    if (node == nullptr) return false;

    if (val != node->data)
        return remove(val, val > node->data ? node->right : node->left);
    else {
        Node* curr = nullptr;
        // Case 1: No Child
        // Case 2: One child
        if(node->left == nullptr) {
          curr = node;
          node = node->right;
          delete curr;
        }
        else if (node->right == nullptr) {
           curr = node;
           node = node->left;
           delete curr;
        }
        // Case 3: Two children,
        // replace current node with minimum node from right subtree,
        // or maximum node from left subtree
        else {
            // Method 1: find min of right subtree
            curr = node->right; // jump to right subtree
            while (curr->left != nullptr) // traverse to left 
                curr = curr->left;        // to find min val Node
            node->data = curr->data; // assign the delete node to found min val
            return remove(curr->data, node->right); // remove the min val node
                                                    // from right subtree

            // Method 2: find max of left subtree
            /*
            curr = node->left; // jump to left subtree
            while (curr->right != nullptr) // traverse to right to find max
                curr = curr->right;
            node->data = curr->data; // replace node val with max value
            // recursively remove the node with max value from left subtree
            remove(curr->data, node->left);
            */
        }
    }
    treeSize--;
    return true;



}

template <typename T>
int BST<T>::size(Node* &node, int &count) {
    if (node != nullptr) {
        count++;
        size(node->left, count);
        size(node->right, count);
    }
    return count;
}

template <typename T>
int BST<T>::getLeafCount(Node* &node, int &count) {
    if (node != nullptr) {
        getLeafCount(node->left, count);
        getLeafCount(node->right, count);
        if (node->left == nullptr && node->right == nullptr)
            count++;
    }
    return count;
}

template <typename T>
int BST<T>::getHeight(Node* &node) {
    if (node == nullptr)
        return 0;
    else
        return max(getHeight(node->left), getHeight(node->right)) + 1;
}

template <typename T>
int BST<T>::getLevel(T val, Node* &node) {
    if (node->data == val) return 0;
    else return 1 + getLevel(val, val > node->data ? node->right : node->left);

}

template <typename T>
void BST<T>::getAncestors(T val, stringstream &ss, Node* &node) {
    if (node->data != val) {
        ss << node->data << " ";
        getAncestors(val, ss, val > node->data ? node->right : node->left);
    }
}

template <typename T>
void BST<T>::getOrderTraversal(Node* &node, stringstream &ss, string type) {
    if (node != nullptr) {
        if (type == "pre") ss << node->data << " ";
        getOrderTraversal(node->left, ss, type);
        if (type == "in") ss << node->data << " ";
        getOrderTraversal(node->right, ss, type);
        if (type == "post") ss << node->data << " ";
    }
}

#endif //P2_BST_H
