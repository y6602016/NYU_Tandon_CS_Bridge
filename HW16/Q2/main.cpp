#include <iostream>
#include <vector>
using namespace std;


template <class T>
class Queue {
public:
    void enqueue(T item) {data.push_back(item);};
    void deque() {
        if (front == data.size() - 1) {
            front = 0;
            data.clear();
        }
        else{
            front += 1;
        }
    };
    T top() {return data[front];};
    bool isEmpty() {return data.empty();};
    int size() {return data.size() - front;};
    void print() {
        for (int i = front; i < data.size(); i++) {
            cout << data[i] << " ";
        }
    }
private:
    vector<T> data;
    int front = 0;
};


int main() {
    Queue<int> queue;
    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(10);
    queue.print();
    cout << endl;
    queue.deque();
    queue.deque();
    queue.enqueue(100);
    queue.print();
    cout << endl;
    queue.deque();
    queue.deque();
    queue.print();
    return 0;
}
