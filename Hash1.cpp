// #define SUCCESS 1
// #define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768

#include <iostream>
#include <cstdlib>
using namespace std;

enum Status { SUCCESS, UNSUCCESS };
typedef struct {
    int *elem;
    int count;
} HashTable;

int m = 0;

Status InitHashTable(HashTable *H) {
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        H->elem[i] = NULLKEY;
    }
    return SUCCESS;
}

int Hash(int key) {
    return key % m;
}

void InsertHash(HashTable *H, int key) {
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY) {
        addr = (addr + 1) % m; // 开放定址法的线性探测
    }
    H->elem[addr] = key;
}

Status SearchHash(HashTable H, int key, int *addr) {
    *addr = Hash(key);
    while (H.elem[*addr] != key) {
        *addr = (*addr + 1) % m;
        if (*addr = Hash(key)) {
            cout << "Can't find the key." << endl;
            return UNSUCCESS;
        }
    }
    return SUCCESS;
}

void PrintHash(HashTable *H) {
    cout << "Current HashTable is as following:" << endl;
    for (int i = 0; i < H->count; i++) {
        cout << H->elem[i] << " ";
    }
    cout << endl;
}

int main() {
    HashTable *H = new HashTable;
    InitHashTable(H);
    InsertHash(H, 12);
    InsertHash(H, 67);
    InsertHash(H, 56);
    InsertHash(H, 16);
    InsertHash(H, 25);
    InsertHash(H, 37);
    InsertHash(H, 22);
    InsertHash(H, 29);
    InsertHash(H, 15);
    InsertHash(H, 47);
    InsertHash(H, 48);
    InsertHash(H, 34);
    PrintHash(H);
    int *addr = new int;
    SearchHash(*H, 25, addr);
    cout << *addr << endl;
    system("pause");
    return 0;
}
