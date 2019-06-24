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

int dp_subset (int arr[], int s) {
#define arr_len 6
#define S 10
	//S = s + 1
	int subset[arr_len][S];
	int i, j;
	for (i = 0; i < arr_len; i++)
		subset[i][0] = 1;
	for (i = 0; i < s; i++)
		subset[0][i] = 0;
	subset[0][arr[0]] = 1;
	for (i = 0; i < arr_len; i++) {
		for (j = 0; j < s + 1; j++) {
			if (arr[i] > s)
				subset[i][s] = subset[i - 1][s];
			else {
				int a = subset[i - 1][s - arr[i]];
				int b = subset[i - 1][s];
				subset[i][s] = a || b;
			}
		}
	}
	return subset[arr_len - 1][S  - 1];
}

int time_prev (int arr[][3], int s) {
	int i;
	for (i = 0; i < s; i++)
}

int time_max () {
	//arr[length][1:start_time, 2:end_time, 3:value]
	int arr[8][3] =  {
		{1, 4, 5}, 
		{3, 5, 1}, 
		{0, 6, 8}, 
		{4, 7, 4},  
		{5, 9, 3}, 
		{6, 10, 2}, 
		{8, 11, 4}
	};

}

void main(){
	{
		int arr[] = {1, 2, 4, 1, 7, 8, 3};
		int result;
		result = rec_opt (arr, 6);
		printf ("%d\n", result);
		result = dp_opt (arr, 7);
		printf ("%d\n", result);
	}
	{
		int arr[] = {3, 34, 4, 12, 5, 2};
		int result;
		result= rec_subset (arr, 6 - 1, 9);
		printf ("%d\n", result);
		result= rec_subset (arr, 6 - 1, 10);
		printf ("%d\n", result);
		result= rec_subset (arr, 6 - 1, 11);
		printf ("%d\n", result);
		result= rec_subset (arr, 6 - 1, 12);
		printf ("%d\n", result);
		result= rec_subset (arr, 6 - 1, 13);
		printf ("%d\n", result);
		result= dp_subset(arr, 9);
		printf ("%d\n", result);
	}
}
