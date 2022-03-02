/*
 * Created by Angelina Guzman on 3/2/2022.
 */
#include <iostream>
using namespace std;

const int NUMBERS_SIZE = 50000;

int genRandInt(int, int);
void fillArray(int[], int[], int[]);
void Quicksort_midpoint(int[], int, int);
void Quicksort_medianOfThree(int [], int, int);
void InsertionSort(int [], int);

int main() {
    // fill the arrays
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArray(arr1, arr2, arr3);

    // keep track of the time
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();
//call sort function here
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
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

}

/*
 * this function utilizes different pivot selection technique in quicksort algorithm. The pivot is the median of the following three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). You should modify the partition function given in section 21.5 to select the pivot using median-of-three technique.
 */
void Quicksort_medianOfThree(int numbers[], int i, int k) {

}

/*
 * this function sorts the given array using InsertionSort method. (implementation of this method is provided in section 21.3).
 */
void InsertionSort(int numbers[], int numbersSize) {

}