#include <iostream>
using namespace std;

class BST {
private:
    
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value) {
            data = value;
            left = right = NULL;
        }
    };

    Node* root;

    Node* GetNewNode(int data) {
        Node* newNode = new Node(data);
        return newNode;
    }

    Node* Insert(Node* root, int data) {
        if (root == NULL)
            root = GetNewNode(data);
        else if (data <= root->data)
            root->left = Insert(root->left, data);
        else
            root->right = Insert(root->right, data);
        return root;
    }

    bool Search(Node* root, int data) {
        if (root == NULL)
            return false;
        else if (root->data == data)
            return true;
        else if (data < root->data)
            return Search(root->left, data);
        else
            return Search(root->right, data);
    }

    Node* FindMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    Node* Delete(Node* root, int data) {
        if (root == NULL)
            return root;
        else if (data < root->data)
            root->left = Delete(root->left, data);
        else if (data > root->data)
            root->right = Delete(root->right, data);
        else {
            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                root = nullptr;
            }
            // Case 2: One child
            else if (root->left == NULL) {
                Node* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == NULL) {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            // Case 3: Two children
            else {
                Node* temp = FindMin(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }

    void PreOrder(Node* root) {
        if (root == NULL) 
		return;
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void InOrder(Node* root) {
        if (root == NULL) 
		return;
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }

    void PostOrder(Node* root) {
        if (root == NULL) 
		return;
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }

public:
    BST() { 
	root = NULL; 
	}

    void Insert(int data) { 
	root = Insert(root, data); }

    void Delete(int data) { 
	root = Delete(root, data); }

    bool Search(int data) { 
	return Search(root, data); }

    void PreOrder() { 
        if (root == NULL) cout << "Tree is empty!";
        else PreOrder(root);
        cout << endl;
    }

    void InOrder() { 
        if (root == NULL) cout << "Tree is empty!";
        else InOrder(root);
        cout << endl;
    }

    void PostOrder() { 
        if (root == NULL) cout << "Tree is empty!";
        else PostOrder(root);
        cout << endl;
    }
};

//=======================================================================================

int main() {
    BST tree;
    int value, option;
    Menu:
        cout << "--------------------------------" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Pre-order" << endl;
        cout << "5. In-order" << endl;
        cout << "6. Post-order" << endl;
        cout << "7. Clear screen" << endl;
        cout<< "8.Menu" << endl;
        cout << "9. Exit" << endl;
        cout << "--------------------------------" << endl;
      YourOption:
      	
        cout << "Your option: ";
        cin >> option;
        cout<<endl;
  switch(option)
  {
  
  case 1:
            cout << "Enter value to Insert: ";
            cin >> value;
            if (tree.Search(value))
                cout << "The node " << value << " already exists!" << endl;
            else{
			
                tree.Insert(value);
           }
        goto YourOption;
        case 2:
        	 cout << "Enter value to Delete: ";
            cin >> value;
            if (!tree.Search(value))
                cout << "The node " << value << " not found!" << endl;
            else{
			
                tree.Delete(value);
        }
        goto YourOption;
        case 3:
            cout << "Enter value to Search: ";
            cin >> value;
            cout << (tree.Search(value) ? "Found!" : "Not found!") << endl;
            goto YourOption;
        case 4: 
            tree.PreOrder();
            goto YourOption;
        case 5:
            tree.InOrder();
        goto YourOption;
        case 6:
       
            tree.PostOrder();
        goto YourOption;
        case 7:
            system("cls");
            system("clear");
         case 8:
            goto Menu;
        case 9:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option!" << endl;
        break;
}
    return 0;
}
