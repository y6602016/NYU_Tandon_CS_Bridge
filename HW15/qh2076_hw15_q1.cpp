#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

using namespace std;


class EmployeeList;

class Employee {
public:
    Employee();
    Employee(int newId, double newRate, string newName);
    ~Employee();
    int getId() const {return id;};
    string getName() const {return name;};
    double getRate() const {return rate;};
private:
    int id;
    double rate;
    string name;
};
Employee::Employee(int newId, double newRate, string newName) {
    id = newId;
    rate = newRate;
    name = newName;
}
Employee::Employee() {}
Employee::~Employee() {}

class node {
    friend class EmployeeList;
public:
    node();
    node(Employee & newData);
    ~node();
    Employee getData() {return data;};
    Employee data;
    node * pre;
    node * next;
};

node::node() {}
node::node(Employee & newData) {
    data = newData;
    pre = nullptr;
    next = nullptr;
}
node::~node() {}


class EmployeeList {
public:
    EmployeeList();
    ~EmployeeList();
    void addEmployee(int id, double rate, string name);
    node * getHead() {return head;};
    void print();
private:
    node * head;
};


EmployeeList::EmployeeList() {
    head = nullptr;
}
EmployeeList::~EmployeeList() {}

void EmployeeList::addEmployee(int id, double rate, string name) {
    Employee * employee = new Employee(id, rate, name);
    node * n = new node(*employee);
    if (head == nullptr) {
        head = n;
    }
    else{
        node * p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = n;
        n->pre = p;
    }
}


void EmployeeList::print() {
    node * n = head;
    while (n != nullptr) {
        cout << n->data.getName() << " ";
        n = n->next;
    }
}

void openFile(ifstream & in) {
    string name;
    cout << "Please enter the file name: ";
    cin >> name;
    in.open(name);
    while (!in) {
        cout << "Cannot find the file, please enter again: ";
        cin >> name;
        in.clear();
        in.open(name);
    }
}


int main() {
    ifstream file1;
    openFile(file1);

    int id;
    double rate;
    string name;
    EmployeeList employees;

    while (file1 >> id) {
        file1 >> rate;
        file1.ignore(9999, ' ');
        getline(file1, name);
        employees.addEmployee(id, rate, name);
    }

    ifstream file2;
    openFile(file2);
    vector<int> Id(100);
    vector<int> Hours(100);

    int count = 0;
    while (file2 >> Id[count]) {
        file2 >> Hours[count];
        count++;
    }

    vector<pair<string, double>> idAndSalary;
    node * n = employees.getHead();
    while (n != nullptr) {
        double salary = 0;
        for (int i = 0; i < count; i++) {
            if (n->getData().getId() == Id[i]) {
                salary += n->getData().getRate() * Hours[i];
            }
        }
        pair<string, double> info = make_pair(n->getData().getName(), salary);
        idAndSalary.push_back(info);
        n = n->next;
    }

    for (int i = idAndSalary.size() - 1; i > 0; i--) {
        for (int k = 0; k < i; k++) {
            if (idAndSalary[k].second < idAndSalary[k + 1].second) {
                pair<string, double> temp = idAndSalary[k];
                idAndSalary[k] = idAndSalary[k + 1];
                idAndSalary[k + 1] = temp;
            }
        }
    }

    for (int i = 0; i < idAndSalary.size(); i++) {
        cout << idAndSalary[i].first << ", $" << idAndSalary[i].second << endl;
    }
    return 0;
}
