#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;cout<<"<6>";
    int n2 = r - m;cout<<"<7>";
    int L[n1], R[n2];cout<<"<8>";
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];cout<<"<10>";
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];cout<<"<13>";
    }
    int i = 0;cout<<"<15>";
    int j = 0;cout<<"<16>";
    int k = l;cout<<"<17>";
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];cout<<"<20>";
            i++;cout<<"<21>";
        } else {
            arr[k] = R[j];cout<<"<23>";
            j++;cout<<"<24>";
        }
        k++;cout<<"<26>";
    }
    while (i < n1) {
        arr[k] = L[i];cout<<"<29>";
        i++;cout<<"<30>";
        k++;cout<<"<31>";
    }
    while (j < n2) {
        arr[k] = R[j];cout<<"<34>";
        j++;cout<<"<35>";
        k++;cout<<"<36>";
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;cout<<"<41>";
    }
    int m = l + (r - l) / 2;cout<<"<43>";
    mergeSort(arr, l, m);cout<<"<44>";
    mergeSort(arr, m + 1, r);cout<<"<45>";
    merge(arr, l, m, r);cout<<"<46>";
}
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";cout<<"<50>";
    }
}
int main() {
    int arr[] = {12,11,13,5,6,7};cout<<"<54>";
    int arr_size = sizeof(arr) / sizeof(arr[0]);cout<<"<55>";
    mergeSort(arr, 0, arr_size - 1);cout<<"<56>";
    printArray(arr, arr_size);cout<<"<57>";
    return 0;cout<<"<58>";
}