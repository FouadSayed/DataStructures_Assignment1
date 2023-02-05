#include <iostream>

    using namespace std;

    int binarySearch(int arr[], int item, int start, int last) {
        if (last <= start)
            return (item > arr[start])? (start + 1): start;
        int middle = (start + last)/2;
        if(item == arr[middle])
            return middle+1;
        if(item > arr[middle])
            return binarySearch(arr, item, middle+1, last);
        return binarySearch(arr, item, start, middle-1);
    }
    void BinaryInsertionSort(int arr[], int size) {
        int i, place, j,  item;
        for (i = 1; i < size; ++i) {
            j = i - 1;
            item = arr[i];
            place = binarySearch(arr, item, 0, j);
            while (j >= place) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = item;
        }
    }
    int main() {
        int arr[] = {80, 56, 12, 57, 43, 38, 41, 996, 10, 3};
        int n = sizeof(arr)/sizeof(arr[0]);
        BinaryInsertionSort(arr, n);
        cout<<"Sorted array is : \n";
        for (int i = 0; i < n; i++)
            cout<<arr[i]<<"\t";
    return 0;
}
