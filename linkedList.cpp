class Node{
    public:
    int value;
    Node* next;
    Node(int value) {
        this -> value = value;
        next = NULL;
    }
};

class LList {
    private:
    Node* head;
    Node* tail;
    public:
    LList(){
        head = tail = NULL;
    }

    void push_front(int val) {
        if(head == NULL) {
            head = tail = new Node(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void push_back(int val) {
        if(head == NULL) {
            head = tail = new Node(val);
            return;
        }

        Node* newNode = new Node(val);
        tail -> next = newNode;
        tail = newNode;
    }

    int pop_front(){
        if(head == NULL) {
            throw;
            return -1;
        }

        int returnVal = head->val;
        head = head-> next;
        if(head == NULL) {
            tail = NULL;
        }
    }
}