/*
 * Created by Angelina Guzman on 3/2/2022.
 */
#include <iostream>
using namespace std;

const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

int genRandInt(int, int);
void fillArrays(int arr1[], int arr2[], int arr3[]);
void Quicksort_midpoint(int numbers[], int, int);
void Quicksort_medianOfThree(int numbers[], int, int);
void InsertionSort(int numbers[], int);
int partition_midpoint(int numbers[], int, int);
int partition_medOfThree(int numbers[], int, int);
bool checkSort(int numbers[], int);

int main() {
    // fill the arrays
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArrays(arr1, arr2, arr3);

    // keep track of the time
    clock_t Start = clock();
    //call sort function here
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE);
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort (midpoint) time to sort an array of size " << NUMBERS_SIZE << " is: " << elapsedTime << " milliseconds." << endl;
    if (checkSort(arr1, NUMBERS_SIZE)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }

    clock_t Start2 = clock();
    //call sort function here
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE);
    clock_t End2 = clock();
    int elapsed = (End2-Start2)/CLOCKS_PER_MS;
    cout << "Quicksort (median of three) time to sort an array of size " << NUMBERS_SIZE << " is: " << elapsed << " milliseconds." << endl;
    if (checkSort(arr2, NUMBERS_SIZE)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }

    int arr[10] = {1, 39, 42, 2, 53, 583, 503, 1, 384, 23};
    clock_t Start3 = clock();
    //call sort function here
    InsertionSort(arr3, NUMBERS_SIZE);
    clock_t End3 = clock();
    int elapsed3 = (End3-Start3)/CLOCKS_PER_MS;
    cout << "Insertion sort time to sort an array of size " << NUMBERS_SIZE << " is: " << elapsed3 << " milliseconds." << endl;
    if (checkSort(arr3, NUMBERS_SIZE)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }
    return 0;
}

int genRandInt(int low, int high) {
    return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

/*
 * this function sorts the given array in the range from i to k using quicksort method. In this function, pivot is the midpoint element (numbers[(i+k)/2]). (implementation of this function is given in section 21.5)
 */
void Quicksort_midpoint(int numbers[], int i, int k) {
    // base case: if the lowIndex surpasses the highIndex, stop
    if (i >= k) {
        return;
    }

    //  recursive cases on the partitions
    int low = partition_midpoint(numbers, i, k);
    Quicksort_midpoint(numbers, i, low);
    Quicksort_midpoint(numbers, low + 1, k);
}

/*
 * this function utilizes different pivot selection technique in quicksort algorithm. The pivot is the median of the following three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). You should modify the partition function given in section 21.5 to select the pivot using median-of-three technique.
 */
void Quicksort_medianOfThree(int numbers[], int i, int k) {
    if (i >= k) {
        return;
    }

    int low = partition_medOfThree(numbers, i, k);
    Quicksort_medianOfThree(numbers, i, low);
    Quicksort_midpoint(numbers, low + 1, k);
}

/*
 * this function sorts the given array using InsertionSort method. (implementation of this method is provided in section 21.3).
 */
void InsertionSort(int numbers[], int numbersSize) {
    for (int i = 1; i < numbersSize; i++) {
        int j = i;
        while ((j > 0) && (numbers[j] < numbers[j - 1])) {
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}

// helper functions

/*
 * after this function is completed, the highest index of the low partition will be returned, where the partition is in its correct place in the array. this does not sort the partitions
 */
int partition_midpoint(int numbers[], int lowIndex, int highIndex) {
    int midpoint = (lowIndex + highIndex) / 2;
    int pivot = numbers[midpoint];

    bool done = false;

    while (!done) {
        while(numbers[lowIndex] < pivot) {
            lowIndex += 1;
        }
        while (pivot < numbers[highIndex]) {
            highIndex -=1;
        }

        if(lowIndex >= highIndex) {
            done = true;
        } else {
            int temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;

            lowIndex += 1;
            highIndex -= 1;
        }
    }
    return highIndex;
}

int partition_medOfThree(int numbers[], int lowIndex, int highIndex) {
    // find median of three
    int mid = (lowIndex + highIndex) / 2;

    if (numbers[lowIndex] > numbers[mid]) {
        int tmp = numbers[lowIndex];
        numbers[lowIndex] = numbers[mid];
        numbers[mid] = tmp;
    }

    if (numbers[lowIndex > numbers[highIndex]]) {
        int temp = numbers[lowIndex];
        numbers[lowIndex] = numbers[highIndex];
        numbers[highIndex] = temp;
    }

    if (numbers[mid] > numbers[highIndex]) {
        int tmp = numbers[mid];
        numbers[mid] = numbers[highIndex];
        numbers[highIndex] = tmp;
    }

    int pivot = numbers[mid];

    bool done = false;

    while (!done) {
        while(numbers[lowIndex] < pivot) {
            lowIndex += 1;
        }
        while (pivot < numbers[highIndex]) {
            highIndex -=1;
        }

        if(lowIndex >= highIndex) {
            done = true;
        } else {
            int temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;

            lowIndex += 1;
            highIndex -= 1;
        }
    }
    return highIndex;
}

bool checkSort(int numbers[], int size) {
    for (int i = 0; i < size - 2; i++) {
        if (numbers[i] > numbers[i + 1]) {
            return false;
        }
    }

    return true;
}
