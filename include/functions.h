// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// problem 1:
// count number of bits in a that are equal to one.
unsigned short count_ones(unsigned int a) {
	// use mask = 32'b1 to isolate least significant bit
	// if it is 1, increment counter
	// then, right shift a to get the next digit
	// until there are no more 1s to add to the total
	unsigned short count = 0;
	unsigned int mask = 1;

	while(a > 0) {
		count += a & mask;
		a >>= 1;
	}

	return count;
}

// problem 2:
// calculate the checksum of number a
unsigned int checksum(unsigned int a) {
	// Use modulo division to get the least significant (decimal) digit of number a.
	// Loop variable i indicates whether a digit of a should be doubled before being added to 
	// the total. Then, discard the current LSD using integer division with 10.
	// The algorithm repeats the above until there is nothing left to add.
	unsigned int result = 0;
	unsigned int digit;

	for (int i = 0; a > 0; i++) {
		digit = a % 10;

		if (i % 2 == 1) {
			digit *= 2;
			if (digit >= 10) {
				// if here, 10 <= digit <= 18, so only 2 digits will be added to result
				// based on the above, the most significant digit is guaranteed to be 1
				digit = 1 + (digit % 10);
			}
		}

		result += digit;
		a /= 10;
	}

	return result;
}

// problem 3:
// calculate sums of rows of a 2-d array a
template<int N, int M>
void compute_row_sum(short a[N][M], short row_sum[N]) {
	// The outer loop indicates a row of array a.
	// row_sum[i] must be set to 0 before adding anything to it.
	// Then, use a second loop to get every element of row i.
	for (int i = 0; i < N; i++) {
		row_sum[i] = 0;
		for (int j = 0; j < M; j++) {
			row_sum[i] += a[i][j];
		}
	}
}

// problem 4:
// perform wave sort on array a
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

template<int N>
void selection_sort(int a[N]) {
	for (int i = 0; i < N - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < N; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}

		if (min_idx != i) {
			swap(a[i], a[min_idx]);
		}		
	}
}

template<int N>
void wave_sort(int a[N]) {
	// Algorithm: first, sort the array using any sorting algorithm.
	// Then,  swap a's elements in pairs, starting from the first element.
	// Stopping the for loop at the second-to-last element of a covers both
	// even and odd length array cases.
	selection_sort<N>(a);
	for (int i = 0; i < N - 1; i += 2) {
		swap(a[i], a[i + 1]);
	}
}

#endif // FUNCTIONS_H
