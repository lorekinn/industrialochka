#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
void insertionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template<>
void insertionSort(vector<string>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<int> arr1 = { 4, 2, 8, 5, 1, 3 };
    insertionSort(arr1);
    for (int i = 0; i < arr1.size(); ++i) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    vector<double> arr2 = { 2.5, 1.2, 3.8, 0.7, 4.9 };
    insertionSort(arr2);
    for (int i = 0; i < arr2.size(); ++i) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    vector<string> arr3 = { "Denis, Andrey", "Artem, Vasiliy", "Pasha, Dmitriy", "Nikita, Anton" };
    insertionSort(arr3);
    for (int i = 0; i < arr3.size(); ++i) {
        cout << arr3[i] << endl;
    }

}
