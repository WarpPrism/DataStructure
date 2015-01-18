// Problem#: 11281
// Submission#: 3469661
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University

// 链表操作的最最基本实现～～～～～～～～～～～～～～～～～～～～～～～～～～

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    LinkedList() {
        head = NULL;
        size = 0;
    }
    /*

    插入一个元素content到链表的第position个位置，注意position从0开始

    如原始链表是 1 2 3，insert(0, 5)之后变成 5 1 2 3

    如果插入的位置在链表末尾或者之后，则直接将元素插入到链表末尾

    如原始链表是 1 2 3，insert(50, 6)之后变成 1 2 3 6

    第50个位置在当前链表大小之后，所以直接插入到链表末尾，也就是第3个位置

    */
    void insert(int position, int content) {
        Node *new_node = new Node;
        Node *temp = head;
        new_node->data = content;
        if (position > size) position = size;
        if (position == 0) {
            new_node->next = head;
            head = new_node;
            size++;
            return;
        }
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        size++;
        return;
    }

    /*

    删除链表的第position个元素

    如果链表没有第position个元素，则不删除任何元素

    */
    void deleteByPosition(int position) {
        if (position >= size || position < 0) return;
        Node *temp = head;
        Node *target = NULL;
        if (position == 0) {
            target = head;
            head = head->next;
            delete target;
            size--;
            return;
        }
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        size--;
        return;
    }

    /*

    将链表内容打印到屏幕，每个元素后面都跟着一个制表符，

    并且最后一个元素的制表符后面需要换行

    */

    void print() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

private:
    Node *head;                               // 链表头指针
    int size;                                        // 链表内元素个数
};    
                             
