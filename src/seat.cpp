#include <iostream>
#include <string>
using namespace std;

class Seat {
private:
    string seatNumber;
    string seatType;
    int price;
    bool booked;

public:
    Seat(string number, string type, int cost) {
        seatNumber = number;
        seatType = type;
        price = cost;
        booked = false;
    }

    string getSeatNumber() {
        return seatNumber;
    }

    int getPrice() {
        return price;
    }

    bool isAvailable() {
        return !booked;
    }

    void bookSeat() {
        booked = true;
    }

    void cancelSeat() {
        booked = false;
    }

    void displaySeat() {
        cout << seatNumber << " - "
             << seatType << " - Rs." << price
             << " - ";

        if (booked)
            cout << "BOOKED";
        else
            cout << "AVAILABLE";

        cout << endl;
    }
};
