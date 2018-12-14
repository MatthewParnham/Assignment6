#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//print Array
void printArray(double arr[], int size) {
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

//Bubble Sort
void bubbleSort(double arr[], int size) {
  for(int i = 0; i < size; i++) {
    double temp = 0;
    for(int j = 0; j < size - 1; j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

//Selection Sort
void selectionSort(double arr[], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = i; j < size; j++) {
      if(arr[j] < arr[i]) {
        double temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

//insertion Sort
void insertionSort(double arr[], int size) {
  for(int i = 1; i < size; i++) {
    double temp = arr[i];
    int j = i;
    while(j>0 && arr[j-1] >= temp) {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = temp;
  }
}

//quick Sort
int partition(double arr[], int low, int high) {
  double piv = arr[high];
  int i = low-1;
  double temp = 0;
  for(int j = low; j <= high-1; j++) {

    if(arr[j] <= piv) {
      i++;
      temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
    }
  }
  temp = arr[high];
  arr[high] = arr[i+1];
  arr[i+1] = temp;
  return i+1;
}
void quickSort(double arr[], int low, int high) {
  if(low < high) {
    int partitionIdx = partition(arr, low, high);
    quickSort(arr, low, partitionIdx -1);
    quickSort(arr, partitionIdx+1, high);
  }
}

int main(int argc, char **argv) {

  string filePath;
  if (argc != 2) { //Checks for valid command line arguments and saves argument to filePath variable
    cerr << "Incorrect number of arguments. Execution terminated." << endl;
    return 0;
  }
  else {
    filePath = argv[1];
  }

  ifstream in;
  in.open(filePath);
  if(!in) {
    cerr << "File not found. Execution terminated." << endl;
    return 0;
  }

  string line;
  double *arr1;
  double *arr2;
  double *arr3;
  double *arr4;
  int i = 0;
  int size;

  if(getline(in,line)) {
    size = stoi(line);
    arr1 = new double[size];
    arr2 = new double[size];
    arr3 = new double[size];
    arr4 = new double[size];
  }
  while(getline(in, line)) {
    arr1[i] = stod(line);
    arr2[i] = stod(line);
    arr3[i] = stod(line);
    arr4[i] = stod(line);
    i++;
  }

//Bubble Sort
  auto start = high_resolution_clock::now();
  bubbleSort(arr1, size);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Bubble Sort took: " << duration.count() << " microseconds to complete." << endl;

//Selection Sort
  start = high_resolution_clock::now();
  selectionSort(arr2, size);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Selection Sort took: " << duration.count() << " microseconds to complete." << endl;

//Insertion Sort
  start = high_resolution_clock::now();
  insertionSort(arr3, size);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Insertion Sort took: " << duration.count() << " microseconds to complete." << endl;

//Quick Sort
  start = high_resolution_clock::now();
  quickSort(arr4, 0, size);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Quick Sort took: " << duration.count() << " microseconds to complete." << endl;

  return 0;
}
