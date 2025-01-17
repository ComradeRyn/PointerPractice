// Created by AJ DiLeo
// For use in CS211 Spring 2023 ONLY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ******STEP 0: SKIP TO MAIN FUNCTION*********

// perform a circular shift of the bytes
void rotateBytes(unsigned long x) {
	char* lostByte = (char*)&x;
//	printf("%lu\n", (unsigned long)*lostByte);
	unsigned long rotatedValue = x >> 8;
//	printf("%p\n", &rotatedValue);
	char* byteToReplace = (char*)&rotatedValue;
	byteToReplace = byteToReplace + 7;
//	printf("%p\n", &rotatedValue);
	*byteToReplace = *lostByte;
	printf("%lu\n", rotatedValue);
}

// reverse the bytes of the long
void reverseBytes(unsigned long x) {
	unsigned long reversedValue = x;
	char* front = (char*)&reversedValue;
	char* back = front+7;
	char temp = *front;
	*front = *back;
	*back = temp;

	front++;
	back--;
	temp = *front;
	*front = *back;
	*back = temp;

	front++;
	back--;
	temp = *front;
	*front = *back;
	*back = temp;

	front++;
	back--;
	temp = *front;
	*front = *back;
	*back = temp;

	printf("%lu\n", reversedValue);
}

// perform a bitwise OR 
// you cannot use | operator
void bitOr(int a, int b) {
	int normalComp = a & b;
	int invertedA = ~a & b;
	int invertedB = a & ~b;

	int orValue = normalComp + invertedA + invertedB;
	printf("%d\n", orValue);
}

int main(int argc, char* argv[]) {
	// Step 1: Ensure at least two command line args were given
	// e.g., ./hw2 {rotateBytes|reverseBytes|bitOr}
	// fprintf(stderr, "Usage: ./hw2 {rotateBytes|reverseBytes|bitOr} <parameters...>\n");
	if(argc < 2){
		fprintf(stderr, "Usage: ./hw2 {rotateBytes|reverseBytes|bitOr} <parameters...>\n");
		return EXIT_FAILURE;
	}
	// Step 2: Now that we know what exercise to run, let's setup conditionals
	// to enforce this
	if(strcmp(argv[1], "rotateBytes") == 0){
		if(argc != 3){
			fprintf(stderr, "Usage: ./hw2 {rotateBytes|reverseBytes|bitOr} <parameters...>\n");
			return EXIT_FAILURE;
		}
		rotateBytes(atoll(argv[2]));
		return EXIT_SUCCESS;
	}

	else if(strcmp(argv[1], "reverseBytes") == 0){
		if(argc != 3){
			fprintf(stderr, "Usage: ./hw2 {rotateBytes|reverseBytes|bitOr} <parameters...>\n");
			return EXIT_FAILURE;
		}
		reverseBytes(atoll(argv[2]));
		return EXIT_SUCCESS;
	}

	else if(strcmp(argv[1], "bitOr") == 0){
		if(argc != 4){
			fprintf(stderr, "Usage: ./hw2 {rotateBytes|reverseBytes|bitOr} <parameters...>\n");
			return EXIT_FAILURE;
		}
		bitOr(atoi(argv[2]), atoi(argv[3]));
		return EXIT_SUCCESS;
	}
	// Step 3: For every exercise:
		// Step a: validate the number of command line args
			// If invalid # of args, print err to stderr
			// terminate
		// Step b: take input(s) from command line and parse it
		// to the appropriate data type
		// Step c: call respective exercise
	
	// Step 4: Handle invalid exercise name
	// fprintf(stderr, "Usage: ./hw2 {rotateBytes|reverseBytes|bitOr} <parameters...>\n");
	fprintf(stderr, "Usage: ./hw2 {rotateBytes|reverseBytes|bitOr} <parameters...>\n");
	return EXIT_FAILURE;

}
