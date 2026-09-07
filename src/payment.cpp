#include <iostream>
#include <string>
using namespace std;

class Payment {
private:
    string method;
    bool successful;

public:
    Payment(string m) {
        method = m;
        successful = false;
    }

    bool makePayment(double amount) {
        cout << "Payment Method: " << method << endl;
        cout << "Amount: Rs." << amount << endl;

        char choice;
        cout << "Confirm payment? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            successful = true;
            cout << "Payment Successful!" << endl;
        } else {
            successful = false;
            cout << "Payment Failed!" << endl;
        }

        return successful;
    }

    bool isSuccessful() {
        return successful;
    }
};
