#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// Recursively calculates the sum of all numbers from 1 to num
int sumOfNumbers(int num) {
    if (num == 0 )
        return 0;
    return sumOfNumbers(num-1) + num ;
}

// Recursively prints each character of a string
void printSent(const char *myString) {
    if (*myString == '\0')
        return ;
    printf("%c", *myString);
    return printSent(myString + 1);
}

// Recursively counts the number of digits in a given number
int numberOfDigits(int num) {
    if (num == 0 )
        return 0;
    return 1 + numberOfDigits(num/10);
}

// Recursively checks if the array is sequential in increasing order by 1
int isSeq(int arr[], int size) {
    if (arr == 0 )
        return 0;
    if (arr[size-2] == arr[size -1 ] -1 ) {
        isSeq(arr, size-1);
        return 1 ;
    }else return 0;
}

// Recursively searches for a number in the array from both ends (first to last)
int isThereNum(int arr[], int size , int num, int first , int last) {
    if (arr == 0 )
        return 0;

    if (arr[last] == num || arr[first] == num ) {
        return 1;
    }else {
        first = first + 1;
        return isThereNum(arr , size-1 , num, first, last);
    }
}

// Recursively prints all numbers from num down to 1
void printAllNumbers(int num) {
    if (num == 0)
        return ;
    printf("%d",num);
    printAllNumbers(num-1);
}

// Recursively prints all numbers from 1 up to num
void printAllNumbersRev(int num) {
    if (num == 0)
        return ;
    printAllNumbers(num-1);
    printf("%d",num);
}

// Recursively counts total number of wheels assuming:
// even-numbered vehicle has 2 wheels, odd-numbered has 4 wheels
int countWheels(int num, int wheels) {
    if (num == 0)
        return wheels;
    if (num % 2 == 0) {
        wheels = wheels + 2 ;
    }
    if (num %2 != 0) {
        wheels = wheels + 4 ;
    }
    return countWheels(num-1,wheels);
}





int main() {
    int num;
    printf("Please enter a number of prog: ");
    scanf("%d",&num);

    switch (num) {
        case 1: {
            int num, sum;
            printf("Enter a number: ");
            scanf("%d", &num);
            sum = sumOfNumbers(num);
            printf("The sum of %d is %d", num,sum);
            break;
        }
        case 2: {
            const char *myString = "Hello World!";
            printSent(myString);
            return 0 ;
        }
        case 3: {
            int num,digits;
            printf("Please enter a number: ");
            scanf("%d",&num);
            digits = numberOfDigits(num);
            printf("There is %d digits in the number %d", digits, num);

        }
        case 4: {
            int *arr, size, result;
            printf("Enter array size: ");
            scanf("%d", &size);  // user provides size at runtime

            arr = (int *)malloc(size * sizeof(int));

            if (arr == NULL) {
                printf("failed\n");
                return 1;
            }
            printf("Please enter %d numbers for the array: \n", size);

            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }

            result=isSeq(arr,size);

            if (result == 0)
                printf("The arr is not sequential");
            else if (result == 1)
                printf("The arr is Sequential");

            free(arr);
            return 0;
        }

        case 5: {
            int *arr, size, result,num;
            int first=0 ;

            printf("Enter array size: ");
            scanf("%d", &size);  // user provides size at runtime

            int last= size-1 ;

            arr = (int *)malloc(size * sizeof(int));

            if (arr == NULL) {
                printf("failed\n");
                return 1;
            }
            printf("Please enter %d numbers for the array: \n", size);

            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }

            printf("PLease enter a number to find in the array: ");
            scanf("%d", &num);

            result= isThereNum(arr,size,num,first,last);
            if (result == 1 ) {
                printf("The numm is there");
            }else printf("Failed to find");
        }

        case 6: {
            int num;
            printf("Please enter a number: ");
            scanf("%d", &num);
            printAllNumbers(num);
        }

        case 7: {
            int num;
            printf("Please enter a number: ");
            scanf("%d", &num);
            printAllNumbersRev(num);
        }

        case 8: {
            int num, amount;
            int wheels = 0;
            printf("Please enter a number: ");
            scanf("%d",&num);
            amount = countWheels(num, wheels);
            printf("There is %d wheels in the parking lot.",amount);
        }
    }

}