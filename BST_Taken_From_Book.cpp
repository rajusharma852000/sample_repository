#include<iostream>
#include<vector>
using namespace std;


class BST{
private:
    BST* left;
    BST* right;
    BST* parent;
    int key;
private:
    BST* replace(BST* &root, BST* currNode, BST* newNode){
        if(currNode->parent == NULL){
            root = newNode;
        }
        else if(currNode == currNode->parent->left){
            currNode->parent->left = newNode;
        }
        else{
            currNode->parent->right = newNode;
        }
        if(newNode != NULL){
            newNode->parent = currNode->parent;
        }
    }
    BST* findMinimum(BST* temp){
        while(temp->left)
            temp = temp->left;
        return temp;
    }
public:
    BST(int data): key(data), left(nullptr), right(nullptr), parent(nullptr){
        //constructor
    }
    BST(){}
    void insert(BST *&root, int data){
        BST* newNode = new BST(data);
        BST* curr = root;
        BST* prev = NULL;
        while(curr){
            prev = curr;
            if(curr->key < data){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        newNode->parent = prev;
        if(prev == NULL){
            root = newNode;
        }
        else if(prev->key < data){
            prev->right = newNode;
        }
        else{
            prev->left = newNode;
        }
    }
    
    BST* find(BST* &root, int data){
        BST* curr = root;
        while(curr && curr->key != data){
            if(curr->key < data){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        if(curr) return curr;
        else return NULL;
    }
    void deleteNode(BST* &root, int data){
        BST* temp = find(root, data);
        if(temp == NULL){
            cout<<"Delete-Result: Can't delete, data not found"<<endl;
            return;
        }
        if(temp->left == NULL){
            replace(root, temp, temp->right);
        }
        else if(temp->right == NULL){
            replace(root, temp, temp->left);
        }
        else{
            BST* successor = findMinimum(temp->right);
            if(temp->right != successor){
                replace(root, successor, successor->right);
                successor->right = temp->right;
                temp->right->parent = successor;
            }
            replace(root, temp, successor);
            successor->left = temp->left;
            temp->left->parent = successor;
        }
    }
    void inorder(BST* root){
        if(root == NULL) return;
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
};

int main(){
    BST* root = nullptr;
    root->insert(root, 10);
    root->insert(root, 12);
    root->insert(root, 14);
    root->inorder(root);
    cout<<endl;
    root->deleteNode(root, 10);
    root->inorder(root);
    cout<<endl;
}