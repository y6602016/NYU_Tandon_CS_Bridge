#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

void openFile(ifstream & in) {
    string name;
    cout << "Please enter the file name:" << endl;
    cin >> name;
    in.open(name);
    while(!in) {
        cout << "The file name is not found, please enter again." << endl;
        cout << " Please enter the file name:" << endl;
        cin >> name;
        in.clear();
        in.open(name);
    }
}

template<class T>
class Stack {
public:
    void push(T item) {data.push_back(item);};
    void pop() {data.pop_back();};
    bool isEmpty() {return data.empty();};
    int size() {return data.size();};
    T top() {return data.back();};
    void clear() {data.clear();};
private:
    list<T> data;
};

bool balanceChecker(ifstream & in) {
    Stack<char> stack;
    char symbol;
    string words;
    in >> words;
    if (words != "begin") {
        return false;
    }
    while (in >> symbol) {
        if (symbol == 'e') break;
        if (symbol == '[') {
            stack.push(']');
        }
        else if (symbol == '(') {
            stack.push(')');
        }
        else if (symbol == '{') {
            stack.push('}');
        }
        else {
            if (stack.isEmpty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if (top != symbol) {
                return false;
            }
        }
    }
    if (stack.size() != 0) {
        return false;
    }
    in >> words;
    if (words != "nd") {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    ifstream file;
    openFile(file);
    if (balanceChecker(file)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}
