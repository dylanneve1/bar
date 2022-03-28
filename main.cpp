// Inclusions
#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>

// Namespace
using namespace std;

// Functions
void _print_bar_graph (int steps, vector <string> x, vector <int> y);
int _get_word_spacing (vector <string> x, int steps);
int _get_max (vector <int> y, int steps);

// Main
int main () {
    // Variables
    bool stop = false;
    int steps = 0;
    int maxlength = 0;

    // Vector Arrays
    vector <string> x;
    vector <int> y;

    // Take in chart catagories
    cout << "Enter x [end data set with -999]:";
    while (!stop) {
        string tmp;
        cin >> tmp;
        if (tmp != "-999") {
            x.push_back (tmp);
            steps++;
            if (tmp.length() > maxlength) {
                maxlength = tmp.length();
            }
        } else {
            stop = true;
        }
    }

    // Reset our bool
    stop = false;

    // Take in chart values
    cout << "Enter y [end data set with -999]:";
    while (!stop) {
        int tmp;
        cin >> tmp;
        if (tmp != -999) {
            y.push_back (tmp);
        } else {
            stop = true;
        }
    }

    // Print out data
    _print_bar_graph(steps, x, y);
    return 0;
}

// Prints out data from two arrays
void _print_bar_graph (int steps, vector <string> x, vector <int> y) {
    int place = _get_max (y, steps);
    bool stop = false;
    while (!stop) {
        if (place <= 9) {
            cout << " " << place << "  | ";
        } else {
            cout << place << "  | ";
        }
        for (int i = 0; i < steps; i++) {
            if (y[i] >= place) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
        place--;
        if (place == 0) {
            stop = true;
        }
    }
    cout << "----|";
    string border = "----+----|";
    if (steps <= 10) {
        cout << border << endl;
    } else if (steps <= 20) {
        cout << border << border << endl;
    } else if (steps <= 30) {
        cout << border << border << border << endl;
    } else if (steps <= 40) {
        cout << border << border << border << border << endl;
    } else if (steps <= 50) {
        cout << border << border << border << border << border << endl;
    } else if (steps <= 60) {
        cout << border << border << border << border << border << border << endl;
    } else if (steps <= 70) {
        cout << border << border << border << border << border << border << border << endl;
    }
}

// Get largest Y value
int _get_max (vector <int> y, int steps) {
    int max = 0;
    for (int i = 0; i < steps; i++) {
        if (y[i] > max) {
            max = y[i];
        }
    }
    return max;
}
