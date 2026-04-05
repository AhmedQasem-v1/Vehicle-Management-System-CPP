// Car.h - هذا ملف "المنيو" أو الواجهة
#pragma once // (1) سطر سحري يمنع تكرار استدعاء الملف

#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

// ==========================================
// 1. إعلان الكلاسات (الهيكل فقط)
// ==========================================

class Car {
protected:
    string brand;
    int price;

    // الدالة المساعدة (سنكتب كودها في ملف cpp)
    virtual void carName();

public:
    Car(string b, int p);           // الكونستركتور
    virtual ~Car();                 // الديستركتور

    // Getters
    string getBrand();
    int getPrice();

    // Pure Virtual Functions (تبقى كما هي لأنها بدون كود أصلاً)
    virtual string getType() = 0;
    virtual void show() = 0;
};

// --- إعلان الأبناء ---

class Taxi : public Car {
public:
    Taxi(string b, int p);
    string getType() override;
    void show() override;
};

class Bus : public Car {
public:
    Bus(string b, int p);
    string getType() override;
    void show() override;
};

// ==========================================
// 2. إعلان الدوال العامة (Prototypes)
// ==========================================
// هنا نقول للمترجم: "عندنا دوال بهذه الأسماء، تفاصيلها ستجدها في المطبخ (cpp)"

void showMenu();
void showAll(const vector<unique_ptr<Car>>& list);
void addVehicle(vector<unique_ptr<Car>>& list);
void save(vector<unique_ptr<Car>>& list);
void load(vector<unique_ptr<Car>>& list);
void searchVehicle(const vector<unique_ptr<Car>>& list);
void deleteVehicle(vector<unique_ptr<Car>>& list);

