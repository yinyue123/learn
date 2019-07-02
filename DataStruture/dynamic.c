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

int opt (int x, int recode[], int money[], int prev[]) {
	if (recode[x] != 0)
		return recode[x];
	else {
		if (x == 1)
			return money[1];
		if (x == 0)
			return 0;
		else
			return recode[x] = max (
					opt (x - 1, recode, money, prev), 
					money[x] + opt (prev[x], recode, money, prev));
	}
}

int main(){
	if (0) {//bad neighbors
		int arr[] = {1, 2, 4, 1, 7, 8, 3};
		int result;
		result = rec_opt (arr, 6);
		printf ("%d\n", result);
		result = dp_opt (arr, 7);
		printf ("%d\n", result);
	}
	if (0) {//compact numbers
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
	if (1) {
		/*
		n : 9
		start end money [1] : 1 4 5
		start end money [2] : 3 5 1
		start end money [3] : 0 6 8
		start end money [4] : 4 7 4
		start end money [5] : 3 8 6
		start end money [6] : 5 9 3
		start end money [7] : 6 10 2
		start end money [8] : 8 11 4
		max :  12
		*/
		int n;
		int start[100], end[100], prev[100], money[100], recode[100] = {0};
		
		int i, j;
		printf ("n:");
		scanf ("%d", &n);
		for (i = 1;i < n;i++) {
			printf ("start end money [%d]:", i);
			scanf ("%d%d%d", &start[i], &end[i], &money[i]);
		}
		for (i = n;i > 0;i--) {
			for (j = i - 1;j > 0;j--) {
				if (i - 1 == 0) {
					prev[i] = 0;
					break;
				}
				if (start[i] > end[j]) {
					prev[i] = j;
					break;
				}
			}
		}
		printf ("max: %d\n", max(
					opt (n - 1, recode, money, prev), 
					money[n] + opt (prev[n], recode, money, prev)));
	}
	return 0;
}
