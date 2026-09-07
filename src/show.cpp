#include <iostream>
#include <string>
using namespace std;

class Show {
private:
    int showId;
    string movieName;
    string screen;
    string startTime;

public:
    Show(int id, string movie, string scr, string time) {
        showId = id;
        movieName = movie;
        screen = scr;
        startTime = time;
    }

    void displayShow() {
        cout << showId << ". "
             << movieName << " | Screen: "
             << screen << " | Time: "
             << startTime << endl;
    }
};
