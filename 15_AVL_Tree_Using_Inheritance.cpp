#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int key, height;
    Node* left, *right, *parent;
    Node(int data = 0){
        key = data, height = 0, left = right = parent = nullptr;
    }
};
class BST{
protected:
    //private memebers
public:
    BST(){
        //constructor
    }
protected:
    void replace(Node* &root, Node* curr, Node* newNode){
        if(curr->parent == NULL)
            root = newNode;
        else
            curr->parent->left == curr ? curr->parent->left = newNode: curr->parent->right = newNode;
        if(newNode)
            newNode->parent = curr->parent;
    }
    Node* findMin(Node* node){
        while(node->left != NULL)
            node = node->left;
        return node;
    }
    Node* find(Node* &root, int data){
        Node* curr = root;
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
    void insertInBST(Node* &root, Node* &newNode){
        int data = newNode->key;
        Node* curr = root;
        Node* prev = NULL;
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
    void deleteFromBST(Node* &root, int data){
        //base case
        if(root == NULL){
            cout<<"Error: tree is empty"<<endl;
        }

        //find the node to be deleted
        Node* curr = find(root, data);
        if(curr == NULL){
            cout<<"Error: data does not exists"<<endl;
            return;
        } 

        //no left child
        if(curr->left == NULL){
            replace(root, curr, curr->right);
        }
        //no right child
        else if(curr->right == NULL){
            replace(root, curr, curr->left);
        }
        //both children
        else{
            Node* successor = findMin(curr->right);
            if(curr->right != successor){
                replace(root, successor, successor->right);
                successor->right = curr->right;
                curr->right->parent = successor;
            }
            replace(root, curr, successor);
            successor->left = curr->left;
            curr->left->parent = successor;
        }
    }
    void printpreorder(Node* root){
        if(root == NULL) return;
        cout<<root->key<<" ";
        printpreorder(root->left);
        printpreorder(root->right);
    }
    void printinorder(Node* root){
        if(root == NULL) return;
        printinorder(root->left);
        cout<<root->key<<" ";
        printinorder(root->right);
    }
    void printpostorder(Node* root){
        if(root == NULL) return;
        printpostorder(root->left);
        printpostorder(root->right);
        cout<<root->key<<" ";
    }
};

class AVL : public BST{
private:
    Node* root;
public:
    AVL(){
        root = NULL;
    }
    int getHeight(Node* node){
        if(node == NULL) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
    int getBalanceFactor(Node* node){
        return getHeight(node->left) - getHeight(node->right);
    }
    Node* rightRotation(Node* node){
        //define
        Node* x = node;
        Node* y = x->left;

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
    Node* leftRotation(Node* node){
        //define
        Node* x = node;
        Node* y = node->right;

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
    void BalanceTheTree(Node* node){
        Node* z = node;
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

                //if BF(z) == 0 ancestors are not balanced
                // int L = z->left ? z->left->height : 0;
                // int R = z->right ? z->right->height: 0;
                int L = getHeight(z->left);
                int R = getHeight(z->right);
                if(L - R != 0) break;
                else z = z->parent;
            }
        }
    }
    void insertToAVL(int data){
        Node* newNode = new Node(data);
        insertInBST(root, newNode);
        Node* z = NULL;
        if(newNode->parent) 
            z = newNode->parent->parent;
        BalanceTheTree(z);
    }
    void deleteNode(int data){
       //base case
        if(root == NULL){
            cout<<"Error: tree is empty"<<endl;
        }

        //find the node to be deleted
        Node* curr = find(root, data);
        if(curr == NULL){
            cout<<"Error: data does not exists"<<endl;
            return;
        } 

        //no left child
        if(curr->left == NULL){
            replace(root, curr, curr->right);
            BalanceTheTree(curr->parent);
            delete curr;
        }   
        //no right child             
        else if(curr->right == NULL){
            replace(root, curr, curr->left);
            BalanceTheTree(curr->parent);
            delete curr;
        }
        //both children
        else{
            Node* successor = findMin(curr->right);
            if(curr->right != successor){
                replace(root, successor, successor->right);
                BalanceTheTree(successor->parent);
                successor->parent = NULL;
                successor->right = curr->right;
                curr->right->parent = successor;
            }
            replace(root, curr, successor);
            successor->left = curr->left;
            curr->left->parent = successor;
        }
    }
    void inorder(){
        printinorder(root);
        cout<<endl;
    }
    void postorder(){
        printpostorder(root);
        cout<<endl;
    }
    void preorder(){
        printpreorder(root);
        cout<<endl;
    }
    void levelOrderTraversal() {
        if (root == nullptr)
            return;

        queue<Node*>q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->key << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
        cout<<endl;
    }

};

int main(){
    AVL tree;

    tree.insertToAVL(100);
    tree.insertToAVL(50);
    tree.insertToAVL(200);
    tree.insertToAVL(25);
    tree.levelOrderTraversal();
    tree.inorder();
    tree.preorder();
    tree.postorder();
    
}
