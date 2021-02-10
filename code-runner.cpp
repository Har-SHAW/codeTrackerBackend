
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;cout<<"<7>";
	int n2 = r - m;cout<<"<8>";
	int L[n1], R[n2];cout<<"<9>";
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];cout<<"<11>";
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];cout<<"<13>";
	int i = 0;cout<<"<14>";
	int j = 0;cout<<"<15>";
	int k = l;cout<<"<16>";

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];cout<<"<20>";
			i++;cout<<"<21>";
		}
		else {
			arr[k] = R[j];cout<<"<24>";
			j++;cout<<"<25>";
		}
		k++;cout<<"<27>";
	}
	while (i < n1) {
		arr[k] = L[i];cout<<"<30>";
		i++;cout<<"<31>";
		k++;cout<<"<32>";
	}
	while (j < n2) {
		arr[k] = R[j];cout<<"<35>";
		j++;cout<<"<36>";
		k++;cout<<"<37>";
	}
}
void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;cout<<"<42>";
	}
	int m =l+ (r-l)/2;cout<<"<44>";
	mergeSort(arr,l,m);cout<<"<45>";
	mergeSort(arr,m+1,r);cout<<"<46>";
	merge(arr,l,m,r);cout<<"<47>";
}
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";cout<<"<52>";
}
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };cout<<"<56>";
	int arr_size = sizeof(arr) / sizeof(arr[0]);cout<<"<57>";

	cout << "Given array is ";cout<<"<59>";
	printArray(arr, arr_size);cout<<"<60>";

	mergeSort(arr, 0, arr_size - 1);cout<<"<62>";

	cout << "Sorted array is ";cout<<"<64>";
	printArray(arr, arr_size);cout<<"<65>";
	return 0;cout<<"<66>";
}
