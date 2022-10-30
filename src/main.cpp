#include <iostream>
#include "functions.h"
#include "tests.h"

template<int N, typename T>
void print_arr(T arr[N]) {
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}

template<int N, int M, typename T>
void print_2d_arr(T arr[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}
}

int main() {
	// count_ones() test
	std::cout << "---count_ones---\n";
	test_count_ones(5, true);

	// checksum() test
	std::cout << "\n---checksum---\n";
	test_checksum(5, true);
	
	// compute_row_sum() test
	std::cout << "\n---compute_row_sum---\n";
	short a[3][5] = {
		{ 1, 2, 3, 4, 5 }, 
		{ 0, 0, 0, 0, 0 }, 
		{ -40, -3, 3, 25, 4 } 
	};
	short row_sum[3];
	compute_row_sum<3, 5>(a, row_sum);
	std::cout << "input array: \n";
	print_2d_arr<3, 5, short>(a);
	std::cout << "output array: \n";
	print_arr<3, short>(row_sum);
	
	// wave_sort() test
	std::cout << "\n---wave_sort---\n";
	int arr_1[5] = { 5, 2, 9, 3, 2 };
	std::cout << "1. input array = "; 
	print_arr<5, int>(arr_1);
	
	wave_sort<5>(arr_1);
	std::cout << "   output array = ";
	print_arr<5, int>(arr_1);
	
	int arr_2[6] = { 3, 2, 9, 6, 4, 1 };
	std::cout << "2. input array = ";
	print_arr<6, int>(arr_2);
	
	wave_sort<6>(arr_2);
	std::cout << "   output array = ";
	print_arr<6, int>(arr_2);

	return 0;
}
