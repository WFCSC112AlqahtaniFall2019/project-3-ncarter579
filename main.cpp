//Nathan Carter

#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

// MergeSort function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (int *a, int *b);  //declares the swap function
void bubbleSort(int *a, int n); //declares the swap function

int main(int argc, char *argv[]) {
    //for(int z = 0; z <= 10000 ; z+= 100) {   //this is the for loop used to run the program many times
        // get input: first is random seed, second is vector length
        int seed, length;  //initalizing variables length and seed

        seed = atoi(argv[1]);   //setting up length and seed to be called from the terminal
        length = atoi(argv[2]);

        if (argc != 3) {   //checking to make sure values were entered into the terminal correctly
            cout << "Enter seed and length into BubbleSort" << endl;
            return 1;
        }

        int x = 8;                              //variables used in unit test of swap
        int y = 4;
        cout << "Testing swap" << endl;         //telling user whats happening and what the initial and expected output should be
        cout << "Initial values: "<< x << " " << y << endl;
        cout << "expected output: "<< y << " " << x << endl;
        swap(x,y);                          //calling swap
        cout << "Swapped Values: "<< x << " " << y << endl;  //outputting swapped values to make sure they are correct

        //  cin >> seed >> length;
        srand(seed);

        vector<int> v(length); // vector to be sorted
        vector<int> t(length); // temporary workspace

        // define an integer pointer dynamically allocate an array of integers
        /* your code here */
        int *array = new int[length];   //array of size length

        // initialize and print input

        cout << "Unsorted values:" << endl;
        for (int i = 0; i < v.size(); i++) {  //iterates over the vector v, places random values inside and prints the values to the screen
            v.at(i) = rand() % 100; //random generator placing in numbers
            cout << v.at(i) << '\t'; //printing values
        }
        cout << endl;


        // copy the random list of integers from vector to array
        /* your code here */
        for (int i = 0; i < length; i++) {  //for the length of the array
            *(array + i) = v.at(i);   //copy the value from the corresponding location in the vector
        }


        clock_t start_mergeSort = clock();
        // sort vector using mergeSort
        mergeSort(v, t, 0, v.size() - 1);
        clock_t end_mergeSort = clock();

        // check output, make sure vector is sorted after mergeSort
        for (int i = 1; i < v.size(); i++) {
            assert(v.at(i - 1) <= v.at(i));
        }

        clock_t start_bubbleSort = clock();
        // sort array using bubbleSort
        /* your code here */
        bubbleSort(array, length);  //calling bubbleSort and timing it
        clock_t end_bubbleSort = clock();

        // check output, make sure array is sorted after bubbleSort
        /* your code here */
        for (int i = 1; i < length; i++) {
            assert(array[i - 1] <= array[i]);  //checking if bubbleSort did it's job and sorted correctly
        }

        // print sorted vector after mergeSort
        cout << "Sorted mergeSort" << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v.at(i) << '\t';
        }
        cout << endl;


        // print sorted array after bubbleSort
        /* your code here */
        cout << "Sorted BubbleSort" << endl;
        for (int i = 0; i < length; i++) {
            cout << array[i] << " ";  //printing the output of BubbleSort
        }
        cout << endl;


        delete array;  //deleting array from the heap because it is no longer used

        // print elapsed time for mergeSort and bubbleSort
        double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
        double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

        cout << elapsed_mergeSort << " " << elapsed_bubbleSort << endl;

    //}
    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(int *a, int *b) {
    /* your code here */
    int temp;  //swaps the two values passed to it using the variable temp
    temp = *a;
    *b = temp;
    *a = *b;
}

// BubbleSort function
void bubbleSort(int *a, int n) {
    /* your code here */
    while(n > 0){   //while the length is greater then zero
        for(int i = 0; i < n -1; i++){   //keep iterating until i reaches n - 1
            if(a[i] > a[i+1]){  //checking if values need to be swapped
                swap(a[i], a[i+1]);  //calling swap with the two values if they need swapped
            }
        }
        n--;  //reducing n so that it only looks at values that still might need to be swapped
    }
}