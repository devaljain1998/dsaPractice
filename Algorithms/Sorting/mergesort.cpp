#include<bits/stdc++.h>
using namespace std;

void merge(int low, int mid, int high, int* a);
void mergeSort(int low, int high, int* a);
void printArray(int* a, int size);
void printArray(int* a, int lowerBound, int upperBound);

int main()
{
    int testCases = 5;
    int size[] = {5, 10, 15, 20, 100};
    testCases = 5;
    while(testCases--){
        int a[size[5-testCases]] = {0};

        for(int i=0;i<size[5-testCases];i++){
            a[i] = rand()%100 + 1;
        }

        cout << "Initial Array is: " << endl;
        printArray(a, size[5-testCases]);

        mergeSort(0, size[5-testCases]-1, a);

        cout << "Array after sorting " << endl;
        printArray(a, size[5-testCases]);        
    }

    return 0;
}

void printArray(int *a, int size){
    for(int i=0;i<size;i++){
        cout << a[i] << "  ";
    }
    cout << endl;
}

void printArray(int *a, int lowerBound, int upperBound){
    for(int i=lowerBound; i<=upperBound; i++){
        cout << a[i] << "  ";
    }
    cout << endl;
}

void mergeSort(int low, int high, int* a){
    if(low < high){
        int mid = (low+high)/2;
        mergeSort(low, mid, a);
        mergeSort(mid+1, high, a);
        merge(low, mid, high, a);
    }
}

void merge(int low, int mid, int high, int* a){
    int i=low, j=mid+1, k=0;
    int b[high-low+1] = {0};

    for(; i<=mid && j<=high ;k++){
        b[k] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }

    while (i<=mid)
    {
        b[k++] = a[i++];
    }

    while (j<=high)
    {
        b[k++] = a[j++];
    }

    for(i=low, k=0; i<=high; i++,k++){
        a[i] = b[k];
    }

}

