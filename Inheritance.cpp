#include<iostream>
using namespace std;

class Device {
private:
    string id;
    string isActive;
public:
    Device(string id) {
        this->id = id;
    }

    void turnOn() {
        isActive = "рабочий";
    }

    void turnOff() {
        isActive = "нерабочий";
    }

    void getInfo() {
        cout << "ID: " << id << "\nСостояние: " << isActive << endl;
    }
};


class PC: public Device {
private:
    int ram;
    string os;
public:
    PC(string id, int ram, string os): Device(id) {
        this->ram = ram;
        this->os = os;
    }

    void getInfo() {
        Device::getInfo();
        cout << "RAM: " << ram << " gb" << "\nОС: " << os << endl;
    }
};


class Laptop: public PC {
private:
    float weight;
    int diagonal;
public:
    Laptop(string id, int ram, string os, float weight, int diagonal): PC(id, ram, os) {
        this->weight = weight;
        this->diagonal = diagonal;
    }

    void getInfo() {
        PC::getInfo();
        cout << "Вес: " << weight << " kg" << "\nДиагональ: " << diagonal << " cm";
    }
};

int main() {
    Device d("28746573");
    PC p("45678510", 16, "Windows");
    Laptop l("12345678", 8, "MacOS", 2.5f, 16);
    d.turnOn();
    p.turnOff();
    l.turnOn();
    //d.getInfo();
    //p.getInfo();
    l.getInfo();
    return 0;
}