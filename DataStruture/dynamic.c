#include <stdio.h>
#include <stdlib.h>

int max (int a, int b) {
	return a > b ? a : b;
}

int rec_opt(int arr[], int i){
	if ( i == 0 ) {
		return arr[0];
	} else if ( i == 1 ){
		return max (arr[0], arr[1]);
	} else  {
		int a, b;
		a = rec_opt (arr, i - 2) + arr[i];
		b = rec_opt (arr, i - 1);
		return max (a, b);
	}
}

int dp_opt (int arr[], int n) {
	int opt[7] = {0};
	int i;
	int a, b;
	opt[0] = arr[0];
	opt[1] = max (arr[0], arr[1]);
	for (i = 2; i < n; i++) {
		a = opt[i - 2] + arr[i];
		b = opt[i - 1];
		opt[i] = max (a, b);
	}
	return opt[n - 1];
}

int rec_subset (int arr[], int i, int s) {
	if (s == 0)
		return 1;
	else if (i == 0)
		return arr[0] == s;
	else if (arr[i] > s)
		return rec_subset (arr, i - 1, s);
	else {
		int a, b;
		a = rec_subset (arr, i - 1, s - arr[i]);
		b = rec_subset (arr, i - 1, s);
		return a || b;
	}
}

void main(){
	{
		int arr[] = {1, 2, 4, 1, 7, 8, 3};
		int result = rec_opt (arr, 6);
		int result2 = dp_opt (arr, 7);
		printf ("%d\n", result);
		printf ("%d\n", result2);
	}
	{
	}
}
