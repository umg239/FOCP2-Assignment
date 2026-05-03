#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> bookings; 
    unordered_map<int, int> available;               
    const int MAX_TICKETS = 100;

public:
    bool book(int user, int movie) {
        if (available.find(movie) == available.end()) {
            available[movie] = MAX_TICKETS;
        }

        if (bookings[movie].count(user) || available[movie] == 0) {
            return false;
        }

        bookings[movie].insert(user);
        available[movie]--;
        return true;
    }

    bool cancel(int user, int movie) {
        if (bookings[movie].count(user) == 0) {
            return false;
        }

        bookings[movie].erase(user);
        available[movie]++;
        return true;
    }

    bool isBooked(int user, int movie) {
        return bookings[movie].count(user) > 0;
    }

    int availableTickets(int movie) {
        if (available.find(movie) == available.end()) {
            return MAX_TICKETS;
        }
        return available[movie];
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    MovieTicket system;

    while (Q--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "BOOK") {
            int X, Y;
            ss >> X >> Y;
            cout << (system.book(X, Y) ? "true" : "false") << endl;
        }
        else if (command == "CANCEL") {
            int X, Y;
            ss >> X >> Y;
            cout << (system.cancel(X, Y) ? "true" : "false") << endl;
        }
        else if (command == "IS_BOOKED") {
            int X, Y;
            ss >> X >> Y;
            cout << (system.isBooked(X, Y) ? "true" : "false") << endl;
        }
        else if (command == "AVAILABLE_TICKETS") {
            int Y;
            ss >> Y;
            cout << system.availableTickets(Y) << endl;
        }
    }

    return 0;
}
