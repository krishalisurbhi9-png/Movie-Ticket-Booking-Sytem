#include <iostream>
#include <string>
using namespace std;

class Booking {
private:
    int bookingId;
    string customerName;
    string movieName;
    string seatNumber;
    double totalAmount;

public:
    Booking(int id, string customer, string movie,
            string seat, double amount) {
        bookingId = id;
        customerName = customer;
        movieName = movie;
        seatNumber = seat;
        totalAmount = amount;
    }

    void printTicket() {
        cout << "\n========== MOVIE TICKET ==========\n";
        cout << "Booking ID : " << bookingId << endl;
        cout << "Customer : " << customerName << endl;
        cout << "Movie : " << movieName << endl;
        cout << "Seat : " << seatNumber << endl;
        cout << "Total : Rs." << totalAmount << endl;
        cout << "==================================\n";
    }
};
