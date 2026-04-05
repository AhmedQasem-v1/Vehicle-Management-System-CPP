#include "Vehicle.h" // (1) أهم سطر: ربط المطبخ بالمنيو

// ==========================================
// تنفيذ دوال الكلاس الأب (car)
// ==========================================

// الكونستركتور
Car::Car(string b, int p) : brand(b), price(p) {}

// الديستركتور
Car::~Car() {}

// دالة الاسم (protected)
void Car::carName() {
    cout << "--- Generic Car Info ---" << endl;
}

// Getters
string Car::getBrand() { return brand; }
int Car::getPrice() { return price; }

// ==========================================
// تنفيذ دوال التاكسي (Taxi)
// ==========================================

Taxi::Taxi(string b, int p) : Car(b, p) {}

string Taxi::getType() {
    return "Taxi";
}

void Taxi::show() {
    carName();
    cout << "[Taxi] Brand: " << brand << " | Price: " << price << "$" << endl;
    cout << endl;
}


// ==========================================
// تنفيذ دوال الباص (Bus)
// ==========================================

Bus::Bus(string b, int p) : Car(b, p) {}

string Bus::getType() {
    return "Bus";
}

void Bus::show() {
    carName();
    cout << "[Bus]  Brand: " << brand << " | Price: " << price << "$" << endl;
    cout << endl;
}


// ==========================================
// تنفيذ الدوال العامة (Functions Implementation)
// ==========================================

void showMenu() {
    cout << "\n============================\n";
    cout << "   CAR MANAGEMENT SYSTEM\n";
    cout << "============================\n";
    cout << "1. Add New Vehicle\n";
    cout << "2. Search for Vehicle\n";
    cout << "3. Delete Vehicle\n";
    cout << "----------------------------\n";
    cout << "4. Save Data (Keep Working) 💾\n";
    cout << "0. Exit Program 🚪\n";
    cout << "============================\n";
    cout << "Enter your choice: ";
}

void showAll(const vector<unique_ptr<Car>>& list) {
    cout << "---- Vehicle Report ----" << endl;
    if (list.empty()) {
        cout << "(List is empty)" << endl;
    }
    for (const auto& vehicle : list) {
        vehicle->show();
    }
}

void addVehicle(vector<unique_ptr<Car>>& list) {
    int choice;
    cout << "Select vehicle type to add:\n1. Taxi\n2. Bus\nChoice: ";
    cin >> choice;
    cin.ignore();

    string tempBrand;
    int tempPrice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw invalid_argument("Invalid input. Please enter a number.");
    }
    if (choice != 1 && choice != 2) {
        throw invalid_argument("Invalid choice. Please select 1 or 2.");
    }

    cout << "Enter vehicle brand: ";
    getline(cin, tempBrand);

    cout << "Enter vehicle price: ";
    cin >> tempPrice;
    cin.ignore();

    try {
        if (choice == 1) {
            list.push_back(make_unique<Taxi>(tempBrand, tempPrice));
            showAll(list);
        }
        else if (choice == 2) {
            list.push_back(make_unique<Bus>(tempBrand, tempPrice));
            showAll(list);
        }
    }
    catch (const exception& ex) {
        cerr << "error : " << ex.what() << endl;
    }
}

void save(vector<unique_ptr<Car>>& list) {
    ofstream carFile("cars.txt");
    if (carFile.is_open()) {
        for (const auto& v : list) {
            carFile << v->getType() << endl;
            carFile << v->getBrand() << endl;
            carFile << v->getPrice() << endl;
        }
        carFile.close();
        cout << "All data saved successfully to file!\n";
    }
    else {
        cerr << "Unable to open file for writing." << endl;
    }
}

void load(vector<unique_ptr<Car>>& list) {
    ifstream carFile("cars.txt");
    string type;
    string brand;
    int price;

    while (carFile >> type >> brand >> price) {
        if (type == "Taxi") {
            list.push_back(make_unique<Taxi>(brand, price));
        }
        else if (type == "Bus") {
            list.push_back(make_unique<Bus>(brand, price));
        }
    }
}

void searchVehicle(const vector<unique_ptr<Car>>& list) {
    if (list.empty()) {
        cout << "No vehicles available to search." << endl;
        return;
    }
    string target;
    cout << "Enter brand to search: ";
    getline(cin, target);

    bool found = false;
    for (const auto& i : list) {
        if (i->getBrand() == target) {
            cout << "vehicle found : " << endl;
            i->show();
            found = true;
        }
    }
    if (!found) {
        cout << "vehicle not found." << endl;
    }
}

void deleteVehicle(vector<unique_ptr<Car>>& list) {
    if (list.empty()) {
        cout << "No vehicles available to delete." << endl;
        return;
    }

    int choice;
    cout << "Select type to delete:\n1.Taxi\n2.Bus\nChoice: ";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Invalid input!" << endl;
        return;
    }
    cin.ignore(1001, '\n');

    string targetChoice;
    if (choice == 1) targetChoice = "Taxi";
    else if (choice == 2) targetChoice = "Bus";
    else {
        cout << "Invalid choice." << endl;
        return;
    }

    string targetName;
    cout << "Enter brand to delete: ";
    getline(cin, targetName);

    bool found = false;

    for (auto it = list.begin(); it != list.end(); it++) {
        if ((*it)->getBrand() == targetName && (*it)->getType() == targetChoice) {
            list.erase(it);
            cout << "vehicle deleted successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No " << targetChoice << " with brand " << targetName << " found." << endl;
    }
}