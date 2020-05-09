class Node {
    public:
    int val;
    Node* left, *right;
    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
    
    void inorderTraversal() {
        if(this->left != NULL) {
            this->left->inorderTraversal();
        }
        cout << val << endl;
        if(this->right != NULL) {
            this->right -> inorderTraversal();
        }
    }
    
    void preOrderTraversal() {
        cout << val << endl;
        if(this-> left != NULL) {
           this->left -> preOrderTraversal(); 
        }
        
        if(this -> right != NULL) {
            this->right -> preOrderTraversal();
        }
    }
    
    void postOrderTraversal() {
        if(this->left != NULL) {
            this-> left -> postOrderTraversal();
        }
        if(this->right != NULL) {
            this->right -> postOrderTraversal();
        }
        
        cout << val <<endl;
    }
    
    Node* search(int x) {
        if(this->val == x) {
            return this;
        }
        
        if(left != NULL) {
            Node* leftSearch = left->search(x);
            if(leftSearch) {
                return leftSearch;
            }
        }
        
        if(right != NULL) {
            Node* rightSearch = right->search(x);
            if(rightSearch) {
                return rightSearch;
            }
        }
        
        return NULL;
    }
    
    void binaryInsert(int x) {
        if(x < val) {
            if(left != NULL){
                left->binaryInsert(x);
                return;
            }
            left = new Node(x);
            return;
        }
        
        if(right != NULL) {
            right->binaryInsert(x);
            return;
        }
        right = new Node(x);
        return;
    }
    
    Node* binarySearch(int x) {
        if(val == x) {
            return this;
        }
        
        if(val < x) {
            if(left != NULL) {
                return left->binarySearch(x);;
            }
            return NULL;
        }
        else {
            if(right != NULL) {
                return right->binarySearch(x);
            }
            return NULL;
        }
    }
    
    private:
    Node* deleteMe() {
        if(right != NULL) {
            Node* minRight = right->min();
            val = minRight->val;
            right->deleteNode(minRight->val);
            return this;
        }

        if(left == NULL) {
            delete this;
            return NULL;
        }

        Node* tempLeft = left;
        val = left -> val;
        right = left-> right;
        left = left-> left;
        delete tempLeft;
        return this;
    }
    public:
    void deleteNode(int x) {
        if(val == x) {
            delete this;
        }
        if(x < val) {
            if(left->val == x) {
                left = left->deleteMe();
                return;
            }
            left-> deleteNode(x);
        } else {
            if(right->val == x) {
                right = right->deleteMe();
                return;
            }
            right -> deleteNode(x);
        }
        return;
    }
    Node* min() {
        if(left != NULL) {
            return left->min();
        }
        return this;
    }
};

int main () {
    int n;
    cin >> n;
}