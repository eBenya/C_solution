bool search(int n, int array[], int lower, int upper){	
	//int len = sizeof(array)/sizeof(array[0]);
	int mid = (upper - lower)/2;
	if(mid == 0) return false;
	
	if (array[mid] == n) return true;
	else 
		if(array[mid] > n) search(n, array, mid, upper);
		else search(n, array, lower, mid);
}