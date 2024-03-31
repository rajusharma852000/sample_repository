#include<iostream>
using namespace std;


class AVL{
private:
    int key;
    int height;
    AVL* left, *right, *parent;
public:
    //constructor
    AVL(int data = 0): key(data), height(0), left(nullptr), right(nullptr), parent(nullptr){}

    //to find minimum valued node
    AVL* getMin(AVL* node){
        if(node == NULL) return nullptr;
        while(node->left != nullptr)
            node = node->left;
        return node;
    }

    //to get the height of node
    int getHeight(AVL* node){
        if(node == NULL) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    //balance factor = Height(left) - Height(right)
    int getBalanceFactor(AVL* node){
        return getHeight(node->left) - getHeight(node->right);
    }

    //to find a node with given data
    AVL* find(AVL* &root, int data){
        AVL* curr = root;
        while(curr && curr->key != data){
            if(curr->key < data){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        return curr;
    }

    //to right rotate the tree along the given node
    AVL* rightRotation(AVL* node){
        //define
        AVL* x = node;
        AVL* y = x->left;

        //updates links/pointers
        if(x->parent) x->parent->left == x ? x->parent->left = y: x->parent->right = y;
        y->parent = x->parent;
        x->left = y->right;
        if(y->right) y->right->parent = x;
        x->parent = y;
        y->right = x;

        //update height
        x->height = getHeight(x);
        y->height = getHeight(y);
        
        return y;
    }

    //to left rotate the tree along the given node
    AVL* leftRotation(AVL* node){
        //define
        AVL* x = node;
        AVL* y = node->right;

        //update links/pointers
        if(x->parent) x->parent->left == x ? x->parent->left = y: x->parent->right = y;
        y->parent = x->parent;
        x->right = y->left;
        if(y->left) y->left->parent = x;
        x->parent = y;
        y->left = x;

        //update height
        x->height = getHeight(x);
        y->height = getHeight(y);

        return y;
    }

    //replace curr by newNode
    void replace(AVL* &root, AVL* curr, AVL* newNode){
        if(curr->parent == NULL)
            root = newNode;
        else
            curr->parent->left == curr ? curr->parent->left = newNode: curr->parent->right = newNode;
        if(newNode)
            newNode->parent = curr->parent;
    }

    //To balnce a tree, on the basis of Balance factor
    void BalanceTheTree(AVL* &root, AVL* node){
        AVL* z = node;
        while(z != NULL){
            int BF = getBalanceFactor(z);
            if(BF <= 1 && BF >= -1){
                z = z->parent;
            }
            else{
                if(BF > 1 && getBalanceFactor(z->left) >= 0){
                    z = rightRotation(z);
                }
                else if(BF > 1 && getBalanceFactor(z->left) < 0){
                    z->left = leftRotation(z->left);
                    z = rightRotation(z);
                }
                else if(BF < -1 && getBalanceFactor(z->right) <= 0){
                    z = leftRotation(z);
                }
                else if(BF < -1 && getBalanceFactor(z->right) > 0){
                    z->right = rightRotation(z->right);
                    z = leftRotation(z);
                }

                //if root has been rotated
                if(z->parent == NULL) {root = z; return;}

                int L = getHeight(z->left);
                int R = getHeight(z->right);
                if(L - R != 0) break;
                else z = z->parent;
            }
        }
    }

    //insert function
    void insert(AVL* &root, int data){
        //if tree is empty
        AVL* newNode = new AVL(data);
        if(root == NULL){
            root = newNode;
            return;
        }

        //if tree is non-empty
        AVL* curr = root;
        AVL* prev = nullptr;
        while(curr){
            prev = curr;
            if(curr->key > data){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
           
        //insert on left
        newNode->parent = prev;
        if(prev->key > data){
            prev->left = newNode;
        }
        //insert on right
        else if(prev->key < data){
            prev->right = newNode;
        }

        //balance the tree
        AVL* z = NULL;
        if(newNode->parent) 
            z = newNode->parent->parent;
        BalanceTheTree(root, z);
    }

    //delete function
    void deleteNode(AVL* &root, int data){
       //base case
        if(root == NULL){
            cout<<"Error: tree is empty"<<endl;
        }

        //find the node to be deleted
        AVL* curr = find(root, data);
        if(curr == NULL){
            cout<<"Error: data does not exists"<<endl;
            return;
        } 

        //no left child
        if(curr->left == NULL){
            replace(root, curr, curr->right);
            BalanceTheTree(root, curr->parent);
            delete curr;
        }   
        //no right child             
        else if(curr->right == NULL){
            replace(root, curr, curr->left);
            BalanceTheTree(root, curr->parent);
            delete curr;
        }
        //both children
        else{
            AVL* successor = getMin(curr->right);
            if(curr->right != successor){
                replace(root, successor, successor->right);
                BalanceTheTree(root, successor->parent);
                successor->parent = NULL;
                successor->right = curr->right;
                curr->right->parent = successor;
            }
            replace(root, curr, successor);
            successor->left = curr->left;
            curr->left->parent = successor;
        }
    }

    //inorder travesal
    void inorder(AVL* node){
        if(node == NULL) return;
        inorder(node->left);
        cout<<node->key<<" ";
        inorder(node->right);
    }

    //preorder travarsal
    void preorder(AVL* node){
        if(node == NULL) return;
        cout<<node->key<<" ";
        preorder(node->left);
        preorder(node->right);
    }

};

int main(){
    AVL tree;
    AVL* root = nullptr;
    tree.insert(root, 200);
    tree.insert(root, 100);
    tree.insert(root, 300);
    tree.insert(root, 250);
    tree.insert(root, 400);
    tree.insert(root, 500);
    tree.inorder(root);
    cout<<endl;
    tree.preorder(root);
}
