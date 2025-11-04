#include <stdio.h>
#include <stdlib.h>
/*
NAME: ARNOLD OBAGA
REG NO: PA106/G/28787/25
DESCRIPTION: This program prompts the user to input 10 integers, stores them in an array, writes them to a file,
             reads the integers back to calculate their sum and average, writes the results to another file,
             and finally displays the contents of both files.
*/

#define SIZE 10

// Task 1: Prompt user to input 10 integers and store in array
void inputIntegers(int arr[]) {
    printf("Enter 10 integers:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Write to input.txt
    FILE *fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        perror("Error opening input.txt");
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        fprintf(fptr, "%d\n", arr[i]);
    }
    fclose(fptr);
}

// Task 2: Read from input.txt, calculate sum and average, write to output.txt
void processIntegers() {
    FILE *fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        perror("Error opening input.txt");
        return;
    }

    int num, sum = 0, count = 0;
    while (fscanf(fptr, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(fptr);

    float average = (count > 0) ? (float)sum / count : 0;

    FILE *outptr = fopen("output.txt", "w");
    if (outptr == NULL) {
        perror("Error opening output.txt");
        return;
    }
    fprintf(outptr, "Sum: %d\nAverage: %.2f\n", sum, average);
    fclose(outptr);
}

// Task 3: Display contents of input.txt and output.txt
void displayFiles() {
    char ch;
    FILE *fptr = fopen("input.txt", "r");
    if (fptr == NULL) {
        perror("Error opening input.txt");
    } else {
        printf("\nContents of input.txt:\n");
        while ((ch = fgetc(fptr)) != EOF) {
            putchar(ch);
        }
        fclose(fptr);
    }

    FILE *outptr = fopen("output.txt", "r");
    if (outptr == NULL) {
        perror("Error opening output.txt");
    } else {
        printf("\nContents of output.txt:\n");
        while ((ch = fgetc(outptr)) != EOF) {
            putchar(ch);
        }
        fclose(outptr);
    }
}

int main() {
    int numbers[SIZE];
    inputIntegers(numbers);
    processIntegers();
    displayFiles();
    return 0;
}