int binarySearch(int arr[], int start, int end, int value) 
{ 
   if (end >= start) 
   { 
		int mid = start + (end - start)/2; 

		if (arr[mid] == value)   
			return mid; 

		if (arr[mid] > value)  
			return binarySearch(arr, start, mid-1, value); 
		return binarySearch(arr, mid+1, end, value); 
   } 

   return -1; 
} 