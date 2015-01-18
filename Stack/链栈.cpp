enum ErrorCode {
    success,
    underflow,
    overflow
};
template <class StackEntry>
struct Node {
    StackEntry data;
    Node* next;
};
template <class StackEntry>
class MyStack {
    public:
        MyStack() {
            pTop = NULL;
        }
        bool empty() const {
            if (pTop == NULL) return true;
            else return false;
        }
        int size() const {
            int count = 0;
            Node<StackEntry>* temp = NULL;
            temp = pTop;
            while (temp != NULL) {
                count++;
                temp = temp -> next;
            }
            return count;
        }
        ErrorCode pop() {
            if (pTop == NULL) return underflow;
            Node<StackEntry>* old = pTop;
            pTop = pTop -> next;
            delete old;
            old = NULL;
            return success;
        }
        ErrorCode top(StackEntry &item) const {
            if (pTop == NULL) return underflow;
            item = pTop -> data;
            return success;
        }
        ErrorCode push(const StackEntry &item) {
            Node<StackEntry>* newNode = new Node<StackEntry>;
            if (newNode == 0) return overflow;
            newNode -> next = pTop;
            newNode -> data = item;
            pTop = newNode;
            newNode = NULL;
            return success;
        }
        void clear() {
            Node<StackEntry>* temp = NULL;
            while (pTop != NULL) {
                temp = pTop;
                pTop = pTop -> next;
                delete temp;
            }
        }
    private:
        Node<StackEntry> *pTop;
};
