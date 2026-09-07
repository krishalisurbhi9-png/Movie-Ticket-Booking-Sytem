#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Seat {
    string number;
    string type;
    int price;
    bool booked;
};

struct Movie {
    int id;
    string name;
    string language;
};

struct Show {
    int id;
    int movieId;
    string screen;
    string time;
};

vector<Movie> movies = {
    {1, "Avengers: Endgame", "English"},
    {2, "3 Idiots", "Hindi"},
    {3, "Interstellar", "English"}
};

vector<Show> shows = {
    {1, 1, "Screen 1", "06:00 PM"},
    {2, 1, "Screen 2", "09:00 PM"},
    {3, 2, "Screen 1", "07:00 PM"},
    {4, 3, "Screen 2", "08:30 PM"}
};

vector<Seat> seats = {
    {"A1", "SILVER", 150, false},
    {"A2", "SILVER", 150, false},
    {"A3", "SILVER", 150, false},
    {"B1", "GOLD", 250, false},
    {"B2", "GOLD", 250, false},
    {"B3", "GOLD", 250, false},
    {"C1", "PLATINUM", 400, false},
    {"C2", "PLATINUM", 400, false},
    {"C3", "PLATINUM", 400, false}
};

void showMovies() {
    cout << "\n--- MOVIES ---\n";

    for (const auto &m : movies) {
        cout << m.id << ". "
             << m.name << " (" << m.language << ")\n";
    }
}

void showShows(int movieId) {
    cout << "\n--- SHOWS ---\n";

    bool found = false;

    for (const auto &s : shows) {
        if (s.movieId == movieId) {
            cout << s.id << ". "
                 << s.screen << " | "
                 << s.time << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No shows available.\n";
    }
}

void showSeats() {
    cout << "\n--- SEAT LAYOUT ---\n";

    for (const auto &s : seats) {
        cout << s.number
             << " [" << s.type << "] Rs."
             << s.price << " - ";

        if (s.booked)
            cout << "BOOKED";
        else
            cout << "AVAILABLE";

        cout << endl;
    }
}

int findSeat(string seatNumber) {

    for (int i = 0; i < seats.size(); i++) {
        if (seats[i].number == seatNumber) {
            return i;
        }
    }

    return -1;
}

int findShow(int showId) {

    for (int i = 0; i < shows.size(); i++) {
        if (shows[i].id == showId) {
            return i;
        }
    }

    return -1;
}

int main() {

    int choice;
    int bookingId = 1001;

    do {

        cout << "\n================================\n";
        cout << " MOVIE TICKET BOOKING\n";
        cout << "================================\n";
        cout << "1. List Movies\n";
        cout << "2. View Shows\n";
        cout << "3. View Seats\n";
        cout << "4. Book Ticket\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {

            showMovies();

        }

        else if (choice == 2) {

            int movieId;

            showMovies();

            cout << "\nEnter Movie ID: ";
            cin >> movieId;

            showShows(movieId);
        }

        else if (choice == 3) {

            showSeats();

        }

        else if (choice == 4) {

            int movieId;
            int showId;
            int numberOfSeats;

            showMovies();

            cout << "\nEnter Movie ID: ";
            cin >> movieId;

            showShows(movieId);

            cout << "\nEnter Show ID: ";
            cin >> showId;

            if (findShow(showId) == -1) {
                cout << "Invalid show ID.\n";
                continue;
            }

            showSeats();

            cout << "\nHow many seats do you want to book? ";
            cin >> numberOfSeats;

            vector<int> selectedSeats;
            int totalAmount = 0;

            bool valid = true;

            for (int i = 0; i < numberOfSeats; i++) {

                string seatNumber;

                cout << "Enter seat " << i + 1 << ": ";
                cin >> seatNumber;

                int index = findSeat(seatNumber);

                if (index == -1) {
                    cout << "Invalid seat number!\n";
                    valid = false;
                    break;
                }

                if (seats[index].booked) {
                    cout << "Seat " << seatNumber
                         << " is already booked!\n";
                    valid = false;
                    break;
                }

                selectedSeats.push_back(index);
                totalAmount += seats[index].price;
            }

            if (!valid) {
                cout << "Booking cancelled.\n";
                continue;
            }

            cout << "\nTotal Amount = Rs."
                 << totalAmount << endl;

            cout << "\nSelect Payment Method\n";
            cout << "1. UPI\n";
            cout << "2. CASH\n";
            cout << "3. CARD\n";
            cout << "Enter choice: ";

            int paymentChoice;
            cin >> paymentChoice;

            if (paymentChoice < 1 || paymentChoice > 3) {
                cout << "Invalid payment method.\n";
                continue;
            }

            char paymentConfirm;

            cout << "Confirm payment? (Y/N): ";
            cin >> paymentConfirm;

            if (paymentConfirm != 'Y' &&
                paymentConfirm != 'y') {

                cout << "Payment Failed.\n";
                cout << "Booking NOT confirmed.\n";
                continue;
            }

            for (int index : selectedSeats) {
                seats[index].booked = true;
            }

            cout << "\nPayment Successful!\n";
            cout << "Booking Confirmed!\n";

            cout << "\n========== TICKET ==========\n";
            cout << "Booking ID : " << bookingId++ << endl;

            cout << "Movie : ";

            for (const auto &m : movies) {
                if (m.id == movieId) {
                    cout << m.name << endl;
                }
            }

            int showIndex = findShow(showId);

            cout << "Screen : "
                 << shows[showIndex].screen << endl;

            cout << "Time : "
                 << shows[showIndex].time << endl;

            cout << "Seats : ";

            for (int index : selectedSeats) {
                cout << seats[index].number << " ";
            }

            cout << "\nTotal : Rs."
                 << totalAmount << endl;

            cout << "============================\n";
        }

        else if (choice == 5) {

            string seatNumber;

            showSeats();

            cout << "\nEnter seat number to cancel: ";
            cin >> seatNumber;

            int index = findSeat(seatNumber);

            if (index == -1) {
                cout << "Invalid seat number.\n";
            }

            else if (!seats[index].booked) {
                cout << "This seat is not booked.\n";
            }

            else {
                seats[index].booked = false;
                cout << "Booking cancelled successfully!\n";
                cout << "Seat " << seatNumber
                     << " is available again.\n";
            }
        }

        else if (choice == 6) {

            cout << "\nThank you for using the system!\n";

        }

        else {

            cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
