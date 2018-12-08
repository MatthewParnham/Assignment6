#include <iostream>

using namespace std;

//print Array
void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

//Bubble Sort
void bubbleSort(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    int temp = 0;
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
void selectionSort(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = i; j < size; j++) {
      if(arr[j] < arr[i]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

//insertion Sort
void insertionSort(int arr[], int size) {
  for(int i = 1; i < size; i++) {
    int temp = arr[i];
    int j = i;
    while(j>0 && arr[j-1] >= temp) {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = temp;
  }
}

//quick Sort
int partition(int arr[], int low, int high) {
  int piv = arr[high];
  int i = low-1;
  int temp = 0;
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
void quickSort(int arr[], int low, int high) {
  if(low < high) {
    int partitionIdx = partition(arr, low, high);
    quickSort(arr, low, partitionIdx -1);
    quickSort(arr, partitionIdx+1, high);
  }
}

int main(int argc, char **argv) {
  int arraySize = 8;
  int arr[arraySize] = {5,7,6,1,2,4,8,3};
  printArray(arr,arraySize);
  quickSort(arr,0,arraySize);
  printArray(arr,arraySize);
}
