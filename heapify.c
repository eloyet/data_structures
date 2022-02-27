#include <stdio.h>

void heapify(int arr[],int n,int i){
	int temp;

	int l=i;
	int left=2*i+1;
	int right=left+1;
    if (left < n && arr[left] < arr[l]){
	
          l= left;
}
	if (right < n && arr[right] < arr[l]){
	
		l = right;
}
	if (l != i){
		temp = arr[i];
		arr[i] = arr[l];
		arr[l] = temp;

		heapify(arr, n, l);
}

}

void heap(int arr[], int n){
     int temp;
	 int i,k=n-1;
	   for ( i = n / 2 - 1; i >= 0; i--){
		heapify(arr, n, i);
}
    for (i = k; i >= 0; i--){
	
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		heapify(arr, i, 0);
}
}
void deleteRoot(int arr[], int n) 
{ 
    int last = arr[n - 1]; 
  
    arr[0] = last; 
  
    n--; 
  
    heap(arr, n); 
} 
void print(int arr[], int n){
    int i;
	for(i = 0; i < n; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){

	int arr[] = {100,32,10,16,31,9,8,29,20,17,16,5,1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
   	printf("The array: \n");
    print(arr, n); 
	printf("\n");
	heap(arr, n);
	printf("The heap: \n");
    print(arr, n);
    deleteRoot(arr,n);
    n--;
    printf("\n Deleted root \n");
	print(arr,n);
    return 0;
}
