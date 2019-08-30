#ifndef LAB7_STACK_HPP
#define LAB7_STACK_HPP

using namespace std;

namespace NEU {
    template <typename T>
    class stack{
    private:
        struct node{
            const T *data;
            node *next;
        };

        node *head;

        int n{};

    public:
        stack();

        ~stack();

        stack(const stack &r);

        bool push(const T &element);

        bool pop();

        T peek();

        int size();

        bool empty();
    };

    template<typename T>
    stack<T>::stack() {
        this->n = 0;
        this->head = NULL;
    }

    template<typename T>
    stack<T>::~stack() {
        delete head;
    }

    template<typename T>
    stack<T>::stack(const stack &r){
        n = r.n;
        head = new node;
        *head = *r.head;
    }

    template<typename T>
    bool stack<T>::push(const T &element) {
        node *oldHead = this->head;
        this->head = new node();
        this->head->data = new T(element);
        this->head->next = oldHead;
        n++;

        return true;
    }

    template<typename T>
    bool stack<T>::pop() {
        if (empty()) {
            return false;
        }

        node *newHead = this->head->next;
        delete this->head;
        this->head = newHead;
        n--;

        return true;
    }

    template<typename T>
    T stack<T>::peek(){
        if (empty()) {
            return false;
        }

        const T *retPtr = this->head->data;

        return *retPtr;
    }

    template<typename T>
    bool stack<T>::empty() {
        return n == 0;
    }

    template<typename T>
    int stack<T>::size() {
        return n;
    }

    template<typename T>
    ostream &operator<<(ostream &out, const stack<T> &source) {
        stack<T> temp = source;
        out << "Stack(top -> down) ";
        while (!temp.empty()) {
            out << temp.peek() << " ";
            temp.pop();
        }
        out << endl;

        return out;
    }
}

#endif