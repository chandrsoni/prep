/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* cloneGraphWithMap(Node* node, map<Node*, Node*>& addressMap) {
        if(node == NULL) {
            return NULL;
        }
        Node* newNode = new Node(node->val);
        addressMap[node] = newNode;
        for(int i = 0; i < node->neighbors.size(); i++) {
            map<Node*, Node*>::iterator it = addressMap.find(node->neighbors[i]);
            if(it != addressMap.end()) {
                newNode->neighbors.push_back(it->second);
            }
            else {
                newNode->neighbors.push_back(cloneGraphWithMap(node->neighbors[i], addressMap));
            }
        }
        
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> addressMap;
        return cloneGraphWithMap(node, addressMap);
    }
};