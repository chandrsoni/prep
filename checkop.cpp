class A {
    int internalNum;
    public:
    A() {
        internalNum = 0;
    }
    A(int num) {
        internalNum = num;
    }
    
    bool operator==(A b) {
        return internalNum == b.internalNum;
    }
};

int main() {
    A a, b(0);
    cout << ((a == b) ? "true": "false") << endl;
    std::cout << "Hello World!\n";
}