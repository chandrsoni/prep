/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* deepStackList(ListNode* head, ListNode* lastNode) {
        if(lastNode == NULL) {
            return head;
        }
        
        ListNode* newNode = deepStackList(head, lastNode-> next);
        if(newNode == NULL) {
            return NULL;
        }
        
        ListNode* nextNode = newNode ->next;
        if (newNode == lastNode || lastNode == nextNode) {
            lastNode->next = NULL;
            return NULL;
        }
        newNode->next = lastNode;
        lastNode->next = nextNode;
        return nextNode;
    }
public: 
    void reorderList(ListNode* head) {
        deepStackList(head, head);
    }
};

int main() {
    
    Solution sol;
    ListNode* l = new ListNode(1);
    ListNode* next = l->next = new ListNode(2);
    next = next -> next = new ListNode(3);
    next = next -> next = new ListNode(4);
    next = next -> next = new ListNode(5);
    next = next -> next = new ListNode(6);
    next = next -> next = new ListNode(7);
    sol.reorderList(l);
    while(l != NULL) {
        cout<< "l val " << l-> val << endl;
        l = l->next;
    }
    std::cout << "Hello World!\n";
}