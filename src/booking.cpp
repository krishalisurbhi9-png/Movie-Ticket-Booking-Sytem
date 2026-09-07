#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Booking {
private:
    int bookingId;
    string customerName;
    string movieName;
    string screen;
    string showTime;
    vector<string> seats;
    int totalAmount;
    bool confirmed;

public:
    Booking(int id, string customer, string movie,
            string scr, string time,
            vector<string> selectedSeats, int amount) {

        bookingId = id;
        customerName = customer;
        movieName = movie;
        screen = scr;
        showTime = time;
        seats = selectedSeats;
        totalAmount = amount;
        confirmed = false;
    }

    void confirmBooking() {
        confirmed = true;
    }

    bool isConfirmed() {
        return confirmed;
    }

    void printTicket() {
        cout << "\n========== MOVIE TICKET ==========\n";
        cout << "Booking ID : " << bookingId << endl;
        cout << "Customer : " << customerName << endl;
        cout << "Movie : " << movieName << endl;
        cout << "Screen : " << screen << endl;
        cout << "Show Time : " << showTime << endl;

        cout << "Seats : ";
        for (string seat : seats) {
            cout << seat << " ";
        }

        cout << "\nTotal : Rs." << totalAmount << endl;
        cout << "Status : CONFIRMED" << endl;
        cout << "==================================\n";
    }

    int getBookingId() {
        return bookingId;
    }
};
