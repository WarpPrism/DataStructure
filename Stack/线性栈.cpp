// 基于数组的栈
enum ErrorCode {success, overflow, underflow};

const int maxsize = 100;

template <class StackEntry>
class MyStack {
private:
    StackEntry *entry;
    int size;
public:
    MyStack() {
        entry = new int[maxsize];
        size = 0;
    }
    ~MyStack() {
        delete []entry;
        size = 0;
    }
    bool empty() {
        return size <= 0;
    }
    ErrorCode push(const StackEntry &item) {
        if (size >= maxsize) return overflow;
        else {
            entry[size] = item;
            size++;
            return success;
        }
    }
    ErrorCode top(StackEntry &item) const {
        if (size <= 0) return underflow;
        else {
            item = entry[size - 1];
            return success;
        }
    }
    ErrorCode pop() {
        if (size <= 0) return underflow;
        else {
            entry[size - 1] = 0;
            size--;
            return success;
        }
    }
};

// 测试主函数
#include <iostream>
using namespace std;

int main() {
    MyStack<int> S;
    int item;
    char command;
    cout << "Please input items that you want to push into the stack." << endl;
    cout << "End with -1" << endl; //一定要以-1结束呀
    do {
        cin >> item;
        //cout << item << endl;
        if (item == -1) {
            cout << "End Push" << endl;
            break;
        }
        if(S.push(item) == success) {
            cout << "Succeed in pushing " << item << " into the stack!" << endl;
        } else {
            cout << "The stack is full!" << endl;
            break;
        }
    } while (item != -1);
    
    cout << "Now please input the commands(t(top) or p(pop) or q(quit))" << endl;
    do {
        cin >> command;
        if (command == 'q' || command == 'Q') {
            cout << "Quit Success" << endl;
            break;
        }
        switch (command) {
            case 't':
            case 'T':
                int item;
                if(S.top(item) == success) {
                    cout << "The top element now is " << item << endl;
                } else {
                    cout << "The stack is empty now." << endl;
                }
                break;
            case 'p':
            case 'P':
                if (S.pop() == success) {
                    cout << "Pop Success!" << endl;
                } else {
                    cout << "The stack is empty now." << endl;
                }
                break;
            default:
                cout << "No such command." << endl;
                break;
        }
    } while (command != 'q' || command != 'Q');
    return 0;
}
