#ifndef BTREE_H
#define BTREE_H

struct BTreeNode {
    int data;
    BTreeNode *lchild, *rchild;
};

class BTree {
public:
    ~BTree();
    void deleteroot(BTreeNode *r);
    void setRoot(BTreeNode *r) {
        root = r;
    }
    BTreeNode* getRoot() {
        return root;
    }
    BTreeNode* createBTree();

    bool empty();
    BTreeNode* findData(int target, BTreeNode * r);
    
    //中序遍历(递归)  
    void inOrder();
    //中序遍历(非递归)
    void NotReInOrder();

    //前序遍历(递归)
    void preOrder();
    //前序遍历(非递归)  
    void NotRePreOrder();

    //后序遍历(递归)
    void postOrder();
    //后序遍历(非递归)
    void NotRePostOrder();
    //求结点个数
    int BTreeSize();
    //求叶子个数
    int BTreeLeaves();
    //求树高   
    int BTreeHeight();
    //层次法求树高
    int layerHeight();
protected:
    //中序遍历  
    void inOrder(BTreeNode*);
    //前序遍历  
    void preOrder(BTreeNode*);
    //后序遍历
    void postOrder(BTreeNode*);

    //结点个数
    int BTreeSize(BTreeNode*);
    //叶子结点
    int BTreeLeaves(BTreeNode*);

    //树高
    int BTreeHeight(BTreeNode*);
private:
    BTreeNode* root;
};

#endif
