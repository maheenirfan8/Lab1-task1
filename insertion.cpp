#include <iostream>
using namespace std;

const int CAPACITY = 10;

// ---------- FUNCTIONS (above main) ----------
void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "   (size = " << size << ")" << endl;
}

int insertAt(int arr[], int size, int pos, int value) {
    if (size == CAPACITY) {              // 1. is the array full?
        cout << "Array is full\n";
        return size;
    }
    if (pos < 0 || pos > size) {         // 2. is the position valid?
        cout << "Invalid position\n";
        return size;
    }
    for (int i = size; i > pos; i--)     // 3. shift right, from the LAST element
        arr[i] = arr[i - 1];
    arr[pos] = value;                    // 4. place the new value
    return size + 1;                     // 5. return the new size
}

// ---------- MAIN ----------
int main() {
    int arr[CAPACITY] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Original:              ";
    display(arr, size);

    size = insertAt(arr, size, 2, 25);       // middle
    cout << "Insert 25 at index 2:  ";
    display(arr, size);

    size = insertAt(arr, size, 0, 5);        // beginning
    cout << "Insert 5 at beginning: ";
    display(arr, size);

    size = insertAt(arr, size, size, 60);    // end
    cout << "Insert 60 at end:      ";
    display(arr, size);

    size = insertAt(arr, size, 20, 99);      // invalid position test

    return 0;
}
