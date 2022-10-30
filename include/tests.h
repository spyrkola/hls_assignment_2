#ifndef TESTS_H
#define TESTS_H

#include <climits>
#include <cassert>
#include <cstdlib>
#include <cmath>

#include "functions.h"

// tests the count_ones() function using n pseudo-random input numbers
void test_count_ones(int n, bool print=false, int seed=42) {
	srand(seed);
	for (int i = 0; i < n; i++) {
		// generate random number with known number of set bits
		// by appending a random bit to the left of test_number
		unsigned int test_number = 0;
		unsigned short count_set_bits = 0;
		for (int j = 0; j < sizeof(unsigned int) * CHAR_BIT; j++) {
			bool rand_bit = rand() % 2;
			if (rand_bit) {
				count_set_bits += 1;
				test_number += (unsigned int)rand_bit << j;
			}
		}
	
		unsigned short count_ones_result = count_ones(test_number);
		if (print) {
			std::cout << "Random Number " << i + 1 << " is " << test_number << ". "
    	              << "Number of set bits = " << count_set_bits 
        	          << ". count_ones() result = " << count_ones_result << '\n';
		}
		assert(count_ones_result == count_set_bits);
	}
	// if here, all tests were successful
	std::cout << "count_ones() passed all " << n << " tests successfully!\n";
}

// tests the checksum() function using n pseudo-random input numbers
void test_checksum(int n, bool print=false, int seed=42) {	
	srand(seed);
	for (int i = 0; i < n; i++) {
		// generate random decimal number with known checksum
		// UINT_MAX = 4294967295, has 10 decimal digits
		// so, the following loop has 10 iterations.
		unsigned int test_number = 0;
		unsigned int test_checksum = 0;
			for (int j = 0; j < 10; j++) {
			// append a random decimal digit to the left of test_number
			// note: this may cause test_number to wrap around
			// if that occurs, then the test_checksum will be wrong
			// to avoid wrong results, exit loop immediately
			unsigned char digit = rand() % 10;
			if ((test_number + (unsigned long long)digit * pow(10, j)) > UINT_MAX) {
				break;
			}
			
			test_number += digit * pow(10, j);
			if (j % 2 == 0) {
				test_checksum += digit;
			} else {
				digit *= 2;
				if (digit >= 10) {
					test_checksum += digit / 10 + digit % 10;
				} else {
					test_checksum += digit;
				}
			}
		}
		
		unsigned int checksum_result = checksum(test_number);
		if (print) {
			std::cout << "Random Number " << i + 1 << " is " << test_number << ". "
    	              << "Its checksum = " << test_checksum 
        	          << ". checksum() result = " << checksum_result << '\n';
		}
		assert(checksum_result == test_checksum);
		
	}
	// if here, all tests were successful
	std::cout << "checksum() passed all " << n << " tests successfully!\n";
}

#endif // TESTS_H
