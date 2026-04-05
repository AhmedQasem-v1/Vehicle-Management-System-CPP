#include "Models/Vehicle.h" // (1) هذا السطر يستدعي كل المكتبات والكلاسات التي جهزناها هناك

int main() {
    vector<unique_ptr<Car>> myCar;

    // تحميل البيانات
    load(myCar);

    int op = -1;
    while (op != 0) {
        showMenu();

        cin >> op;

        // حماية القائمة الرئيسية
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            op = -1;
            continue;
        }
        cin.ignore(1000, '\n'); // تنظيف الإنتر

        try {
            if (op == 1) addVehicle(myCar);
            else if (op == 2) searchVehicle(myCar);
            else if (op == 3) deleteVehicle(myCar);

            else if (op == 4) {
                cout << "Saving changes to file...\n";
                save(myCar);
                cout << "Done! You can continue working now.\n";
            }

            else if (op == 0) {
                cout << "Exiting program. Goodbye!" << endl;
            }
            else {
                cout << "Invalid option. Please try again." << endl;
            }
        }
        catch (const exception& e) {
            cerr << "Warning Error : " << e.what() << endl;
        }
    }

    return 0;
}