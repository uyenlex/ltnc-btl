#include <iostream>
#include <ctime>

const int N = 30;

using namespace std;

int main () {
    srand(time(NULL));
    int list[N];
    for (int i = 0; i < N; i++) {
        list[i] = rand() % 101;
        cout << list[i] << " ";
    }
    cout << endl;

    //bubble sort
    for (int i = N-1; i > 0; i--) {
        bool swapped = false;
        for (int j = 1; j <= i; j++) {
            if (list[j-1] > list[j]) {
                int temp = list[j];
                list[j] = list[j-1];
                list[j-1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    for (int i = 0; i < N; i++) {
        cout << list[i] << " ";
    }

    return 0;
}