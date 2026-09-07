#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    int customerId;
    string name;
    string phone;

public:
    Customer(int id, string n, string p) {
        customerId = id;
        name = n;
        phone = p;
    }

    void displayCustomer() {
        cout << "Customer ID : " << customerId << endl;
        cout << "Name : " << name << endl;
        cout << "Phone : " << phone << endl;
    }

    string getName() {
        return name;
    }
};
