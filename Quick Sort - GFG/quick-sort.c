// { Driver Code Starts
//Initial Template for C

#include <stdio.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
//User function Template for C

//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
   if(low>=high)
   return;
   int p = partition(arr , low , high);
   quickSort(arr , low , p-1);
   quickSort(arr, p+1 , high);
   
}
    
int partition(int arr[], int low, int high)
{
   int pivot = arr[low];
   int count = 0;
   for(int i = low +1; i <= high; i++){
       if(arr[i] <= pivot)
       count++;
   }
   int pi = low + count;
    int temp = arr[pi];
           arr[pi] = arr[low];
           arr[low] = temp;
          
   int i = low;
   int j = high;
   while(i < pi && j > pi){
       while(arr[i] <= pivot)
       i++;
       while(arr[j] > pivot)
       j--;
       if(i < pi && j > pi){
        int temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;
           i++;
           j--;
       }
   }
   return pi;
}

// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends