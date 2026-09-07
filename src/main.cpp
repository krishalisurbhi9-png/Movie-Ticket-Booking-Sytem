#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Movie class
class Movie {
public:
    int id;
    string name;
    string language;

    Movie(int i, string n, string l) {
        id = i;
        name = n;
        language = l;
    }

    void show() {
        cout << id << ". " << name
             << " (" << language << ")" << endl;
    }
};

// Seat class
class Seat {
public:
    string number;
    string type;
    int price;
    bool booked;

    Seat(string n, string t, int p) {
        number = n;
        type = t;
        price = p;
        booked = false;
    }
};

// Show class
class Show {
public:
    int id;
    string movie;
    string screen;
    string time;

    Show(int i, string m, string s, string t) {
        id = i;
        movie = m;
        screen = s;
        time = t;
    }

    void showDetails() {
        cout << id << ". " << movie
             << " | Screen: " << screen
             << " | Time: " << time << endl;
    }
};

// Display seats
void displaySeats(vector<Seat>& seats) {
    cout << "\n--------- SEAT LAYOUT ---------\n";

    for (auto &seat : seats) {
        cout << seat.number << " [" << seat.type << "] - ";

        if (seat.booked)
            cout << "BOOKED";
        else
            cout << "AVAILABLE";

        cout << endl;
    }
}

// Main program
int main() {

    vector<Movie> movies = {
        Movie(1, "Avengers", "English"),
        Movie(2, "3 Idiots", "Hindi"),
        Movie(3, "Interstellar", "English")
    };

    vector<Show> shows = {
        Show(1, "Avengers", "Screen 1", "06:00 PM"),
        Show(2, "Avengers", "Screen 2", "09:00 PM"),
        Show(3, "3 Idiots", "Screen 1", "07:00 PM"),
        Show(4, "Interstellar", "Screen 2", "08:30 PM")
    };

    vector<Seat> seats = {
        Seat("A1", "SILVER", 150),
        Seat("A2", "SILVER", 150),
        Seat("A3", "SILVER", 150),
        Seat("B1", "GOLD", 250),
        Seat("B2", "GOLD", 250),
        Seat("B3", "GOLD", 250),
        Seat("C1", "PLATINUM", 400),
        Seat("C2", "PLATINUM", 400),
        Seat("C3", "PLATINUM", 400)
    };

    int choice;

    do {
        cout << "\n==============================\n";
        cout << " MOVIE TICKET BOOKING\n";
        cout << "==============================\n";
        cout << "1. View Movies\n";
        cout << "2. View Shows\n";
        cout << "3. View Seats\n";
        cout << "4. Book Seat\n";
        cout << "5. Cancel Seat\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << "\n------ MOVIES ------\n";

            for (auto &movie : movies)
                movie.show();

        }

        else if (choice == 2) {

            cout << "\n------ SHOWS ------\n";

            for (auto &show : shows)
                show.showDetails();

        }

        else if (choice == 3) {

            displaySeats(seats);

        }

        else if (choice == 4) {

            string seatNo;
            cout << "\nEnter seat number: ";
            cin >> seatNo;

            bool found = false;

            for (auto &seat : seats) {

                if (seat.number == seatNo) {

                    found = true;

                    if (seat.booked) {
                        cout << "Seat already booked!\n";
                    }
                    else {

                        cout << "Price: Rs." << seat.price << endl;

                        char confirm;
                        cout << "Confirm booking? (Y/N): ";
                        cin >> confirm;

                        if (confirm == 'Y' || confirm == 'y') {
                            seat.booked = true;

                            cout << "\nBooking Successful!\n";
                            cout << "Seat: " << seat.number << endl;
                            cout << "Amount: Rs." << seat.price << endl;
                        }
                        else {
                            cout << "Booking cancelled.\n";
                        }
                    }
                }
            }

            if (!found)
                cout << "Invalid seat number!\n";
        }

        else if (choice == 5) {

            string seatNo;
            cout << "\nEnter seat number to cancel: ";
            cin >> seatNo;

            bool found = false;

            for (auto &seat : seats) {

                if (seat.number == seatNo) {

                    found = true;

                    if (!seat.booked) {
                        cout << "This seat is not booked.\n";
                    }
                    else {
                        seat.booked = false;
                        cout << "Booking cancelled successfully!\n";
                    }
                }
            }

            if (!found)
                cout << "Invalid seat number!\n";
        }

        else if (choice == 6) {
            cout << "\nThank you for using Movie Ticket Booking System!\n";
        }

        else {
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
