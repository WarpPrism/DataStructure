/*************************************************************************
  这是一个二叉查找树，实现了以下操作：插入结点、构造二叉树、删除结点、查找、
  查找最大值、查找最小值、查找指定结点的前驱和后继。上述所有操作时间复杂度
  均为o(h),其中h是树的高度
  注释很详细，具体内容就看代码吧
*************************************************************************/

#include<stdio.h>
#include<stdlib.h>

//二叉查找树结点描述
typedef int KeyType;
typedef struct Node
{
	KeyType key;          //关键字
    struct Node * left;   //左孩子指针
	struct Node * right;  //右孩子指针
	struct Node * parent; //指向父节点指针
}Node,*PNode;

//往二叉查找树中插入结点
//插入的话，可能要改变根结点的地址，所以传的是二级指针
void insert(PNode * root,KeyType key)
{
	//初始化插入结点
	PNode p=(PNode)malloc(sizeof(Node));
	p->key=key;
	p->left=p->right=p->parent=NULL;
	//空树时，直接作为根结点
	if((*root)==NULL){
		*root=p;
		return;
	}
	//插入到当前结点（*root）的左孩子
	if((*root)->left == NULL && (*root)->key > key){
		p->parent=(*root);
        (*root)->left=p;
		return;
	}
	//插入到当前结点（*root）的右孩子
	if((*root)->right == NULL && (*root)->key < key){
		p->parent=(*root);
        (*root)->right=p;
		return;
	}
	if((*root)->key > key)
		insert(&(*root)->left,key);
	else if((*root)->key < key)
		insert(&(*root)->right,key);
	else
		return;
}

//查找元素,找到返回关键字的结点指针，没找到返回NULL
PNode search(PNode root,KeyType key)
{
	if(root == NULL)
		return NULL;
	if(key > root->key) //查找右子树
		return search(root->right,key);
	else if(key < root->key) //查找左子树
		return search(root->left,key);
	else
		return root;
}

//查找最小关键字,空树时返回NULL
PNode searchMin(PNode root)
{
	if(root == NULL)
		return NULL;
	if(root->left == NULL)
		return root;
	else  //一直往左孩子找，直到没有左孩子的结点
	    return searchMin(root->left);
}

//查找最大关键字,空树时返回NULL
PNode searchMax(PNode root)
{
	if(root == NULL)
		return NULL;
	if(root->right == NULL)
		return root;
	else  //一直往右孩子找，直到没有右孩子的结点
	    return searchMax(root->right);
}

//查找某个结点的前驱
PNode searchPredecessor(PNode p)
{
    //空树
	if(p==NULL)
		return p;
	//有左子树、左子树中最大的那个
	if(p->left)
    	return searchMax(p->left);
	//无左子树,查找某个结点的右子树遍历完了
	else{
		if(p->parent == NULL)
			return NULL;
		//向上寻找前驱
		while(p){
    		if(p->parent->right == p)
	    		break;
			p=p->parent;
		}
        return p->parent;
	}
}

//查找某个结点的后继
PNode searchSuccessor(PNode p)
{
    //空树
	if(p==NULL)
		return p;
	//有右子树、右子树中最小的那个
	if(p->right)
    	return searchMin(p->right);
	//无右子树,查找某个结点的左子树遍历完了
	else{
		if(p->parent == NULL)
			return NULL;
		//向上寻找后继
		while(p){
    		if(p->parent->left == p)
	    		break;
			p=p->parent;
		}
        return p->parent;
	}
}

//根据关键字删除某个结点,删除成功返回1,否则返回0
//如果把根结点删掉，那么要改变根结点的地址，所以传二级指针
int deleteNode(PNode* root,KeyType key)
{
	PNode q;
	//查找到要删除的结点
	PNode p=search(*root,key);
	KeyType temp;    //暂存后继结点的值
	//没查到此关键字
	if(!p)
		return 0;
	//1.被删结点是叶子结点，直接删除
	if(p->left == NULL && p->right == NULL){
		//只有一个元素，删完之后变成一颗空树
		if(p->parent == NULL){
			free(p);
			(*root)=NULL;
		}else{
			//删除的结点是父节点的左孩子
    		if(p->parent->left == p)
	     		p->parent->left=NULL;
	    	else  //删除的结点是父节点的右孩子
	     		p->parent->right=NULL;
			free(p);
		}
	}

	//2.被删结点只有左子树
	else if(p->left && !(p->right)){
		p->left->parent=p->parent;
		//如果删除是父结点，要改变父节点指针
		if(p->parent == NULL)
			*root=p->left;
		//删除的结点是父节点的左孩子
		else if(p->parent->left == p)
        	p->parent->left=p->left;
		else //删除的结点是父节点的右孩子
			p->parent->right=p->left;
		free(p);
	}
	//3.被删结点只有右孩子
	else if(p->right && !(p->left)){
		p->right->parent=p->parent;
		//如果删除是父结点，要改变父节点指针
		if(p->parent == NULL)
			*root=p->right;
        //删除的结点是父节点的左孩子
		else if(p->parent->left == p)
        	p->parent->left=p->right;
		else //删除的结点是父节点的右孩子
			p->parent->right=p->right;
		free(p);
	}
	//4.被删除的结点既有左孩子，又有右孩子
	//该结点的后继结点肯定无左子树(参考上面查找后继结点函数)
	//删掉后继结点,后继结点的值代替该结点
    else{
		//找到要删除结点的后继
		q=searchSuccessor(p);
        temp=q->key;
		//删除后继结点
        deleteNode(root,q->key);
		p->key=temp;
	}
	return 1;
}

//创建一棵二叉查找树
void create(PNode* root,KeyType *keyArray,int length)
{
	int i;
	//逐个结点插入二叉树中
	for(i=0;i<length;i++)
		insert(root,keyArray[i]);
}

int main(void)
{
	int i;
    PNode root=NULL;
	KeyType nodeArray[11]={15,6,18,3,7,17,20,2,4,13,9};
	create(&root,nodeArray,11);
	for(i=0;i<2;i++)
		deleteNode(&root,nodeArray[i]);
	printf("%d\n",searchPredecessor(root)->key);
	printf("%d\n",searchSuccessor(root)->key);
	printf("%d\n",searchMin(root)->key);
	printf("%d\n",searchMax(root)->key);
	printf("%d\n",search(root,13)->key);
	return 0;
}
