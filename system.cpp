#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// =========================== BASE CLASS ===============================
class TrainClass {
protected:
    string className;
    int totalSeats;
    int bookedSeats;

public:
    TrainClass(string name, int seats)
        : className(name), totalSeats(seats), bookedSeats(0) {}

    virtual ~TrainClass() {}

    virtual bool bookTicket() {
        if (bookedSeats < totalSeats) {
            bookedSeats++;
            return true;
        }
        return false;
    }

    virtual bool cancelTicket() {
        if (bookedSeats > 0) {
            bookedSeats--;
            return true;
        }
        return false;
    }

    virtual void showAvailability() const {
        cout << className << ": "
             << (totalSeats - bookedSeats)
             << " seats available out of " << totalSeats << endl;
    }

    string getName() const { return className; }
};

// =========================== DERIVED CLASSES ==========================
class Sleeper : public TrainClass {
public:
    Sleeper() : TrainClass("Sleeper", 60) {}
};

class AC3 : public TrainClass {
public:
    AC3() : TrainClass("AC 3-Tier", 40) {}
};

class AC2 : public TrainClass {
public:
    AC2() : TrainClass("AC 2-Tier", 30) {}
};

class General : public TrainClass {
public:
    General() : TrainClass("General", 100) {}
};

// ================================ TRAIN ===============================
class Train {
private:
    string trainName;
    vector<string> route;
    vector<unique_ptr<TrainClass>> classes;

public:
    Train(string name, vector<string> r) : trainName(name), route(r) {}

    void addClass(TrainClass* cls) {
        classes.emplace_back(cls);
    }

    void showRoute() const {
        cout << "\nRoute for " << trainName << ":\n";
        for (int i = 0; i < route.size(); i++) {
            cout << i + 1 << ". " << route[i];
            if (i != route.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    void showClasses() const {
        cout << "\nAvailable Classes:\n";
        for (int i = 0; i < classes.size(); i++) {
            cout << i + 1 << ". " << classes[i]->getName() << endl;
        }
    }

    bool book(int clsIndex) {
        return classes[clsIndex]->bookTicket();
    }

    bool cancel(int clsIndex) {
        return classes[clsIndex]->cancelTicket();
    }

    void showAvailability() const {
        cout << "\nTrain: " << trainName << endl;
        for (auto &cls : classes) cls->showAvailability();
    }

    string getName() const {
        return trainName;
    }
};

// =========================== BOOKING RECORD ==========================
struct Booking {
    int bookingID;
    string passenger;
    string train;
    string from;
    string to;
    string trainClass;
};

// ============================== MAIN SYSTEM ==========================
int main() {
    // Create trains
    Train rajdhani("Rajdhani Express", {"Delhi", "Jaipur", "Ahmedabad", "Mumbai"});
    rajdhani.addClass(new AC2());
    rajdhani.addClass(new AC3());
    rajdhani.addClass(new Sleeper());

    Train shatabdi("Shatabdi Express", {"Chennai", "Vellore", "Bangalore"});
    shatabdi.addClass(new AC3());
    shatabdi.addClass(new General());

    vector<Train*> trains = { &rajdhani, &shatabdi };

    vector<Booking> bookingHistory;
    int bookingCounter = 1;

    int choice;
    do {
        cout << "\n========== RAILWAY BOOKING SYSTEM ==========\n";
        cout << "1. View Trains\n2. Book Ticket\n3. Cancel Ticket\n4. Check Availability\n5. View Booking History\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "\nAvailable Trains:\n";
            for (int i = 0; i < trains.size(); i++)
                cout << i + 1 << ". " << trains[i]->getName() << endl;
            break;
        }

        case 2: {
            string name;
            int tIndex;

            cout << "\nPassenger Name: ";
            cin >> name;

            cout << "\nSelect Train:\n";
            for (int i = 0; i < trains.size(); i++)
                cout << i + 1 << ". " << trains[i]->getName() << endl;

            cin >> tIndex;
            if (tIndex < 1 || tIndex > trains.size()) {
                cout << "Invalid train.\n";
                break;
            }

            Train* selected = trains[tIndex - 1];
            selected->showRoute();

            int f, to;
            cout << "From station number: ";
            cin >> f;
            cout << "To station number: ";
            cin >> to;

            selected->showClasses();
            int c;
            cin >> c;

            if (selected->book(c - 1)) {
                Booking b;
                b.bookingID = bookingCounter++;
                b.passenger = name;
                b.train = selected->getName();
                b.from = selected->getName();
                b.to = "";
                b.trainClass = "";
                bookingHistory.push_back(b);

                cout << "\nTicket Booked Successfully! Booking ID: " << b.bookingID << endl;
            } else {
                cout << "Booking failed. No seats.\n";
            }
            break;
        }

        case 3: {
            int t;
            cout << "\nSelect train to cancel ticket:\n";
            for (int i = 0; i < trains.size(); i++)
                cout << i + 1 << ". " << trains[i]->getName() << endl;
            cin >> t;

            Train* selected = trains[t - 1];
            selected->showClasses();

            int c;
            cout << "Class: ";
            cin >> c;

            if (selected->cancel(c - 1)) {
                cout << "Ticket cancelled.\n";
            } else {
                cout << "No booking found.\n";
            }
            break;
        }

        case 4: {
            int t;
            cout << "\nSelect train to check availability:\n";
            for (int i = 0; i < trains.size(); i++)
                cout << i + 1 << ". " << trains[i]->getName() << endl;
            cin >> t;

            trains[t - 1]->showAvailability();
            break;
        }

        case 5: {
            cout << "\n===== Booking History =====\n";
            for (auto &b : bookingHistory) {
                cout << "Booking ID: " << b.bookingID
                     << " | Passenger: " << b.passenger
                     << " | Train: " << b.train << endl;
            }
            break;
        }

        }

    } while (choice != 6);

    cout << "\nThank you for using the system.\n";
    return 0;
}