
void addNodeToQueue(TreeNode* currentNode, TreeNode* nextNode, vector<int>& result, queue<TreeNode*>& bfsQ, map<TreeNode*, int>& nodeLength) {
    bfsQ.push(nextNode);
    int leftLength = nodeLength[currentNode] + 1;
    if(leftLength >= result.size()) {
        result.push_back(nextNode->val);
    } else {
        result[leftLength] = nextNode->val;
    }
    nodeLength[nextNode] = leftLength;
}
vector<int> rightSideView(TreeNode* root) {
    if(root == NULL) {
        return vector<int>();
    }
    vector<int> result;
    map<TreeNode*, int> nodeLength;
    queue<TreeNode*> bfsQueue;
    bfsQueue.push(root);
    nodeLength[root] = 0;
    result.push_back(root->val);
    while(!bfsQueue.empty()){
        TreeNode* currentNode = bfsQueue.front();
        if(currentNode -> left != NULL) {
            addNodeToQueue(currentNode, currentNode->left, result, bfsQueue, nodeLength);
        }
        if(currentNode -> right != NULL) {
            addNodeToQueue(currentNode, currentNode->right, result, bfsQueue, nodeLength);
        }
        bfsQueue.pop();
    }
    
    return result;
}