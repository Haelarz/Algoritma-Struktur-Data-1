#include <iostream>
using namespace std;

void insertionSort(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key; 
    }
}

void merge(char arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(char arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void shellSort(char arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    char temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void bubbleSort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        char temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void display(char arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i];
    cout << endl;
}

int main() {
    string namaStr = "Helga";
    string nimStr = "2410817210025";

    char nama[100], nim[100];
    int namaLen = namaStr.length();
    int nimLen = nimStr.length();

    for (int i = 0; i < namaLen; i++) nama[i] = namaStr[i];
    for (int i = 0; i < nimLen; i++) nim[i] = nimStr[i];

    int pilihan;

    do {
        cout << "\n========= SORTING ==========\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Shell Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Bubble Sort\n";
        cout << "6. Selection Sort\n";
        cout << "7. Exit\n";
        cout << "=============================\n";
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        for (int i = 0; i < namaLen; i++) nama[i] = namaStr[i];
        for (int i = 0; i < nimLen; i++) nim[i] = nimStr[i];

        switch (pilihan) {
            case 1:
                insertionSort(nama, namaLen);
                cout << "Insertion Sort: ";
                display(nama, namaLen);
                break;
            case 2:
                mergeSort(nama, 0, namaLen - 1);
                cout << "Merge Sort: ";
                display(nama, namaLen);
                break;
            case 3:
                shellSort(nama, namaLen);
                cout << "Shell Sort: ";
                display(nama, namaLen);
                break;
            case 4:
                quickSort(nim, 0, nimLen - 1);
                cout << "Quick Sort: ";
                display(nim, nimLen);
                break;
            case 5:
                bubbleSort(nim, nimLen);
                cout << "Bubble Sort: ";
                display(nim, nimLen);
                break;
            case 6:
                selectionSort(nim, nimLen);
                cout << "Selection Sort: ";
                display(nim, nimLen);
                break;
            case 7:
                cout << "Thank You\n";
                break;
            default:
                cout << "There's no option sire!\n";
        }

    } while (pilihan != 7);

    return 0;
}