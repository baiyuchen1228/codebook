#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int n = rand() % 10;
    srand(time(NULL));
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << rand() % 10 << " " << rand() % 10 << endl;
    }
    return 0;
}