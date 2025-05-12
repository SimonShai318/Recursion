#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void printTriangle_(int n);
void printTriangle(int n);

void star(int  n) {
	if (n == 0)
		return;
	star(n - 1);
	printf("*");
}

// n is an integer 
// the recursive function returns n!
int factorial(int n)
{
	int temp, answer;
	if (n <= 0)			// stopping condition (includes negative numbers)
		return 1;

	temp = factorial(n - 1);	// recursive call
	answer = n * temp;          // combine result 	   // return  n * factorial(n-1);
	return answer;
}

void printTriangle(int n)
{
	if (n == 0)
		return;

	for (int i = 0; i < n; i++)
		printf("*");
	printf("\n");

	printTriangle(n - 1);
}

void printTriangle_(int n)
{
	if (n == 0)
		return;

	printTriangle_(n - 1);

	for (int i = 0; i < n; i++)
		printf("*");
	printf("\n");

	
}

int  power(int n, int k) {
	if (k == 0)
		return 1;
	return power(n, k - 1) * n;
}

int power_r(int n, int k) {
	if (k == 0)
		return 1;
	int t = power_r(n, k / 2);
	if (k % 2 == 0)
		return (t * t);
	else
		return (t * t * n);
}


int sumArr(int arr[], int n) {
	if (n == 0)
		return 0;
	return sumArr(arr, n - 1) + arr[n - 1];
}

int  maxArr(int arr[], int n) {
	if (n == 1)
		return arr[0];
	int tempMax = maxArr(arr, n - 1);
	if (arr[n - 1] > tempMax)
		return arr[n - 1];
	else
		return tempMax;
}


int isSymetricHelper(int arr[], int  leftIndex, int  rightIndex) {
	if (leftIndex >= rightIndex)
		return 1;
	if (arr[leftIndex] != arr[rightIndex])
		return 0;
	return isSymetricHelper(arr, leftIndex + 1, rightIndex - 1);
}

int isSymetric(int  arr[], int size) {
	return isSymetricHelper(arr, 0, size - 1);
}


int findSmallest(int A[], int first, int last)
{
	int mid, min1, min2;
	if (first == last)   // only one element in the array
		return A[first];
	else
	{
		mid = (first + last) / 2;        // divide array into two parts
		min1 = findSmallest(A, first, mid);            // recursively find smallest number in first half
		min2 = findSmallest(A, mid + 1, last);        // recursively find smallest number in second half
		if (min1 < min2)                 // compare the two results and the return the smaller one
			return min1;
		else
			return min2;
	}
}


void main()
{
	star(2);
	printf("\n---------------\n");
	int x = 5;
	int res = factorial(x);
	printf("%d! = %d\n", x, res);
	printf("\n---------------\n");
	printTriangle(4);
	printf("\n---------------\n");
	printTriangle_(4);
	printf("\n---------------\n");
	res = power(2, 3);
	printf("res = %d\n",res);
	printf("\n---------------\n");
	int arr[] = { 1,2,3,4,5 };
	res = sumArr(arr, sizeof(arr) / sizeof(int));
	printf("sum = %d\n", res);
	printf("\n---------------\n");
	res = maxArr(arr, sizeof(arr) / sizeof(int));
	printf("max = %d\n", res);
	printf("\n---------------\n");
	int arr2[] = { 1,2,3,2,1 };
	res = isSymetric(arr2, sizeof(arr2) / sizeof(int));
	printf(" isSymetric? = %d\n", res);
	printf("\n---------------\n");
	res = findSmallest(arr,0, sizeof(arr) / sizeof(int)-1);
	printf("min = %d\n", res);
	printf("\n---------------\n");
	res = power_r(2, 7);
	printf("res = %d\n", res);
	printf("\n---------------\n");

}




