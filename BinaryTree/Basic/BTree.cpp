#include <iostream>
#include <stack>
#include <queue>
#include "BTree.h"
using namespace std;

BTree::~BTree() {
    // deleteroot(root);
}
void BTree::deleteroot(BTreeNode *r) {
    if (r != 0) {
        deleteroot(r -> lchild);
        deleteroot(r -> rchild);
        delete r;
    }
}
BTreeNode* BTree::createBTree() {
    BTreeNode *current = NULL;
    int val;
    // cout << "Please input the value of the node(End with -1)." << endl;
    cin >> val;
    if (val == -1) {
        // cout << "End This Process." << endl;
        return NULL;
    }
    else {
        current = new BTreeNode;
        current->data = val;
        char Go;
        /* cout << "If you want to end this node, input 0, else input 1." << endl;
        cout << "And if you input 0, the lchild and rchild will be set to NULL at the same time." << endl;
        cout << "So this part is used to simplify the process of constructing the Tree." << endl;
        cout << "Go?" << endl; */
        cout << "If this node is a Leaf, input Y, else input N" << endl;
        cin >> Go;
        if (Go == 'Y' || Go == 'y') {
        	current -> lchild = NULL;
        	current -> rchild = NULL;
        } else if (Go == 'N' || Go == 'n') {
            cout << "Now please input the Left child of " << val << " (End with -1)" << endl;
            current->lchild = createBTree();
            if (current->lchild == NULL) {
                cout << "End Left" << endl;
            }
            cout << "Now please input the Right child of " << val << " (End with -1)" << endl;
            current->rchild = createBTree();
            if (current->rchild == NULL) {
                cout << "End Right" << endl;
            }
        }
        return current;
    }
}

bool BTree::empty() {
    if (root == NULL) {
        return true;
    } else {
        return false;
    }
}

BTreeNode* BTree::findData(int target, BTreeNode* r) {
    // if (empty()) return NULL;
    if (r == NULL) return NULL;
    if (r -> data == target) {
         return r;
    } else {
        if (findData(target, r -> lchild) != NULL)
            return findData(target, r -> lchild);
        if (findData(target, r -> rchild) != NULL)
            return findData(target, r -> rchild);
    }
    return NULL;
}

void BTree::inOrder() {
    inOrder(root);
    cout << endl;
}
void BTree::inOrder(BTreeNode* r) {
    if (r != 0) {
        inOrder(r->lchild);
        cout << r->data << " ";
        inOrder(r->rchild);
    }
}

void BTree::NotReInOrder() {
    stack<BTreeNode*> s;
    BTreeNode *r = getRoot();
    while (!s.empty() || r != 0) {
        while (r != 0) {
            s.push(r);
            r = r->lchild;
        }
        if (!s.empty()) {
            r = s.top();
            cout << r->data << " ";
            s.pop();
            r = r->rchild;
        }
    }
    cout << endl;
}

void BTree::preOrder() {
    preOrder(root);
    cout << endl;
}

void BTree::preOrder(BTreeNode* r) {
    if (r != 0) {
        cout << r->data << " ";
        preOrder(r->lchild);
        preOrder(r->rchild);
    }
}

void BTree::NotRePreOrder() {
    stack<BTreeNode*> s;
    BTreeNode *r = getRoot();
    s.push(r);
    while (!s.empty()) {
        r = s.top();
        cout << r->data << " ";
        s.pop();
        if (r->rchild != 0) {
            s.push(r->rchild);
        }
        if (r->lchild != 0) {
            s.push(r->lchild);
        }
    }
    cout << endl;
}

void BTree::postOrder() {
    postOrder(root);
    cout << endl;
}

void BTree::postOrder(BTreeNode* r) {
    if (r != 0)
    {
        postOrder(r->lchild);  
        postOrder(r->rchild);
        cout << r->data << " ";
    }
}

struct Node {
    BTreeNode *tp;
    bool flag;
};

void BTree::NotRePostOrder() {
    Node node;
    stack<Node> s;
    BTreeNode* r = getRoot();
    while (!s.empty() || r != 0) {
        while (r != 0) {
            node.tp = r;
            node.flag = 0;
            s.push(node);
            r = r->lchild;
        }
        if (!s.empty()) {
            node = s.top();
            s.pop();
            r = node.tp;
            if (node.flag == 1) {
                cout << r->data << " ";
                r = 0;
            }
            else {
                node.flag = 1;
                s.push(node);
                r = r->rchild;
            }
        }
    }
    cout << endl;
}

int BTree::BTreeSize() {
    return BTreeSize(root);
}

int BTree::BTreeSize(BTreeNode* r) {
    if (r == 0) {
        return 0;
    }
    else {
        return 1+ BTreeSize(r->lchild) + BTreeSize(r->rchild);
    }
}

int BTree::BTreeLeaves() {
    return BTreeLeaves(root);
}

int BTree::BTreeLeaves(BTreeNode* r) {
    if (r == 0) return 0;
    if (r->lchild == 0 && r->rchild == 0) return 1;
    return BTreeLeaves(r->lchild) + BTreeLeaves(r->rchild);
}

int BTree::BTreeHeight() {
    return BTreeHeight(root);
}

int BTree::BTreeHeight(BTreeNode* r) {
    if (r == 0) return 0;
    else
    {
        int lHei = BTreeHeight(r->lchild);
        int rHei = BTreeHeight(r->rchild);
        return (lHei>rHei) ? lHei + 1 : rHei + 1;
    }
}
