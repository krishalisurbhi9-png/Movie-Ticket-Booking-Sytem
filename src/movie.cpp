#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    int id;
    string title;
    string language;
    int duration;

public:
    Movie(int i, string t, string l, int d) {
        id = i;
        title = t;
        language = l;
        duration = d;
    }

    void display() {
        cout << id << ". " << title << " (" << language
             << ") - " << duration << " min" << endl;
    }
};
