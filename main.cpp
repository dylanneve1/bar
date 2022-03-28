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
    int steps = 0;

    // Vector Arrays
    vector <string> x;
    vector <int> y;

    // Take in chart data
    for (int i = 1; i <= 70; i++) {
        int tmp;
        cin >> tmp;
        y.push_back(tmp);
        x.push_back(to_string(i));
        steps++;
    }

    // Print out data
    _print_bar_graph(steps, x, y);
    return 0;
}

// Prints out data from two arrays
void _print_bar_graph (int steps, vector <string> x, vector <int> y) {
    // Get our max height
    int place = _get_max (y, steps);

    // Kill switch
    bool stop = false;

    // While stop not flipped print data out line by line
    while (!stop) {
        if (place <= 9) {
            cout << " " << place << "  |";
        } else {
            cout << place << "  |";
        }
        for (int i = 0; i < steps; i++) {
            if (y[i] >= place) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
        // Move down a place
        place--;
        // We stop at 0 as no data is stored bellow that
        if (place == 0) {
            // Flip kill switch
            stop = true;
        }
    }
    // Print out meaningless border to make chart look nicer
    cout << "----|";
    string b = "----+----|";
    if (steps <= 10) {
        cout << b << endl;
    } else if (steps <= 20) {
        cout << b << b << endl;
    } else if (steps <= 30) {
        cout << b << b << b << endl;
    } else if (steps <= 40) {
        cout << b << b << b << b << endl;
    } else if (steps <= 50) {
        cout << b << b << b << b << b << endl;
    } else if (steps <= 60) {
        cout << b << b << b << b << b << b << endl;
    } else if (steps <= 70) {
        cout << b << b << b << b << b << b << b << endl;
    }
}

// Get largest Y value
int _get_max (vector <int> y, int steps) {
    int max = 0;
    // Check through array one by one and find maximum
    for (int i = 0; i < steps; i++) {
        if (y[i] > max) {
            max = y[i];
        }
    }
    return max;
}
