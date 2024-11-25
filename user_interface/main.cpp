#include "tests.hpp"
#include "ui_functions.hpp"
#include <iostream>
using namespace std;

int main() {
    if (run_all_tests() != 0) {
        return 1;
    }
    
    cout << "Everything is ok!\n";
    return 0;
}