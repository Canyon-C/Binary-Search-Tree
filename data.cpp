using namespace std;
#include <iostream>

class Data {
private:
    int value;
public:

    Data(int value) {
        this->value = value;
    }

    void print() {
        cout << value;
    }
    void set_value(int value) {
        this->value = value;
    }

    int get_value() {
        return value;
    }

};