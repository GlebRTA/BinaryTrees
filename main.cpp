#include <iostream>

using namespace std;

int COUNTER = 0;

template <typename T>
class Node {

public:

    T value;
    int count = 0;
    Node* left;
    Node* right;

    Node(T value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }

};


Node<int>* push(Node<int>* node, int val) {

    if (node == nullptr) {
        return new Node<int>(val);
    }

    if (val < node->value) {
        node->left = push(node->left, val);
    }
    else if (val == node->value) {
        node->count++;
    }
    else {
        node->right = push(node->right, val);
    }

    return node;
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void preOrderSort(Node<char>* tree) {

    if (tree == NULL) {
        return;
    }

    cout << tree->value << " ";
    preOrderSort(tree->left);
    preOrderSort(tree->right);
}


void postOrderSort(Node<char>* tree) {
    if (tree == NULL) {
        return;
    }

    postOrderSort(tree->left);
    postOrderSort(tree->right);
    cout << tree->value << " ";
}

void inOrderSort(Node<char>* tree) {
    if (tree == NULL) {
        return;
    }

    inOrderSort(tree->left);
    cout << tree->value << " ";
    inOrderSort(tree->right);

}

void inOrderSort(Node<int>* tree, int* arr) {
    if (tree == NULL) {
        return;
    }

    inOrderSort(tree->left, arr);
    for (int i = 0; i <= tree->count; i++) {
        arr[COUNTER++] = tree->value;
        //cout << tree->value << " ";
    }

    inOrderSort(tree->right, arr);

}

void postOrderDelete(Node<int>* tree) {
    if (tree == NULL) {
        return;
    }

    postOrderDelete(tree->left);
    postOrderDelete(tree->right);
    delete tree;

}

int main() {


    //tree example from Wikipedia
    /*Node<char>* root = new Node<char>('F');

    root->left = new Node<char>('B');
    root->left->left = new Node<char>('A');
    root->left->right = new Node<char>('D');
    root->left->right->left = new Node<char>('C');
    root->left->right->right = new Node<char>('E');

    root->right = new Node<char>('G');
    root->right->right = new Node<char>('I');
    root->right->right->left = new Node<char>('H');

    cout << "Pre Order Sort" << endl;
    preOrderSort(root);

    cout << endl << endl << "In Order Sort" << endl;;
    inOrderSort(root);

    cout << endl << endl << "Post Order Sort" << endl;
    postOrderSort(root);

    cout << endl;*/

    int size;
    cout << "Input array size" << endl;
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    Node<int>* root = NULL;
    for (int i = 0; i < size; i++) {
        root = push(root, arr[i]);
    }


    cout << "In Order Sort" << endl;;
    inOrderSort(root, arr);

    printArray(arr, size);

    postOrderDelete(root);
    delete[] arr;

    return 0;
}