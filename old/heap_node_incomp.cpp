class Node {
    public:
    int value;
    Node* left;
    Node* right;
    Node(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
private:
    void insertBubble() {
        bool isLeftSmaller = left != NULL && left -> value < value;
        bool isRightSmaller = right != NULL && right -> value < value;
        if(isLeftSmaller && isRightSmaller) {
            if(left -> value < right -> value) {
                swap(value, left->value);
                left -> insertBubble();
            }
            else {
                swap(value, right->value);
                right -> insertBubble();
            }
            return;
        }
        if(isLeftSmaller) {
            swap(value, left-> value);
            left -> insertBubble();
            return;
        }

        if(isRightSmaller) {
            swap(value, right -> value);
            right -> insertBubble();
        }
    }
    public:
    void insertNumber(int n){
        
    }
}