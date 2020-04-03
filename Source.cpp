#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>


const int size = 16;

//Reverses a byte, bitwise.
unsigned int reverseBits(unsigned int num){
	unsigned int NO_OF_BITS =  8;
	unsigned int reverse_num = 0;
	int i;
	for (i = 0; i < NO_OF_BITS; i++)
	{
		if ((num & (1 << i)))
			reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
	}
	return reverse_num;
}


//Print out matrix
void printMat(int** mat, int length) {
	int count;
	for (int i = 0; i < length; i++) {
		count = 0;
		for (int j = 0; j < size; j++) {
			if (mat[i][j] < 16) {
				std::cout << "0";
			}
			std::cout << std::hex << (mat[i][j]);
			count++;
			if (count == 4) {
				count = 0;
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}


//Flips the matrix wordwise 
//(eg. 33333333 22222222 11111111 00000000 --> 00000000 11111111 22222222 33333333)
int ** reverseMatrixWordwise(int ** mat, int length) {
	//Define new matrix
	int ** flippedMat = new int*[length];
	for (int i = 0; i < length; i++) {
		flippedMat[i] = new int[size];
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < size;) {
			switch (j / 4)
			{
			case 0:
				flippedMat[i][j] = mat[length - 1 - i][j++ + 12];
				flippedMat[i][j] = mat[length - 1 - i][j++ + 12];
				flippedMat[i][j] = mat[length - 1 - i][j++ + 12];
				flippedMat[i][j] = mat[length - 1 - i][j++ + 12];
				break;					   
			case 1:						   
				flippedMat[i][j] = mat[length - 1 - i][j++ + 4];
				flippedMat[i][j] = mat[length - 1 - i][j++ + 4];
				flippedMat[i][j] = mat[length - 1 - i][j++ + 4];
				flippedMat[i][j] = mat[length - 1 - i][j++ + 4];
				break;					   
			case 2:						   
				flippedMat[i][j] = mat[length - 1 - i][j++ - 4];
				flippedMat[i][j] = mat[length - 1 - i][j++ - 4];
				flippedMat[i][j] = mat[length - 1 - i][j++ - 4];
				flippedMat[i][j] = mat[length - 1 - i][j++ - 4];
				break;					   
			case 3:						   
				flippedMat[i][j] = mat[length - 1 - i][j++ - 12];
				flippedMat[i][j] = mat[length - 1 - i][j++ - 12];
				flippedMat[i][j] = mat[length - 1 - i][j++ - 12];
				flippedMat[i][j] = mat[length - 1 - i][j++ - 12];
				break;

			default:
				std::cerr << "Error in input stream\n";
				return NULL;
			}
			
		}
	}
	//get rid of old matrix
	delete(mat);
	return flippedMat;
}



int main() {
	
	int length = size;
	int defaultMat[size][size] = {
		{ 0x9B, 0xBD, 0x0F, 0x8A, 0xE6, 0x04, 0x95, 0x8A, 0xF4, 0xE0, 0x27, 0x6D, 0x58, 0xC8, 0x64, 0x90 },
		{ 0x0e, 0x5e, 0x8c, 0x9d, 0x0E, 0x5E, 0x8C, 0x9D, 0x06, 0x06, 0xFD, 0x24, 0x19, 0x7C, 0xC9, 0x5D },
		{ 0x30, 0xF0, 0xC3, 0x8E, 0xE2, 0xC6, 0x10, 0x8C, 0x49, 0x1C, 0xF1, 0x4A, 0x9A, 0x70, 0x19, 0xC4 },
		{ 0xB2, 0x5D, 0x54, 0xB3, 0x42, 0x56, 0x17, 0x4A, 0x17, 0x26, 0xB4, 0xEF, 0xC6, 0x82, 0xB0, 0xF9 },
		{ 0x08, 0x2F, 0x21, 0x50, 0x55, 0x4D, 0xB1, 0xD1, 0xF5, 0x1A, 0x4E, 0x52, 0x08, 0xB3, 0x27, 0xA1 },
		{ 0xED, 0x27, 0xD3, 0x8B, 0xFD, 0x5C, 0x90, 0x11, 0x2A, 0xE5, 0xE9, 0x43, 0x78, 0x09, 0x28, 0x50 },
		{ 0x9F, 0x9D, 0x62, 0x10, 0xD2, 0x01, 0x73, 0x9C, 0x25, 0x58, 0x9F, 0x2C, 0x61, 0x3F, 0xA1, 0xB3 },
		{ 0x07, 0x58, 0xC3, 0x91, 0xEC, 0x99, 0x51, 0x73, 0x6B, 0xA1, 0x09, 0x3A, 0x8D, 0x8F, 0x21, 0x13 },
		{ 0x8C, 0xCB, 0x18, 0xDE, 0x5C, 0xBA, 0x7D, 0x7D, 0x47, 0x0B, 0xF2, 0x49, 0x70, 0x00, 0xD9, 0x33 },
		{ 0x7F, 0xCE, 0xFE, 0x6C, 0x17, 0x74, 0xFD, 0xD8, 0x07, 0xA3, 0x04, 0xFA, 0xED, 0x7D, 0x60, 0x98 },
		{ 0x3D, 0xE0, 0xE3, 0xD5, 0x4E, 0x80, 0x20, 0x27, 0x03, 0xFE, 0x86, 0xA2, 0xD8, 0xEB, 0x04, 0x90 },
		{ 0x6A, 0xA6, 0x33, 0xA3, 0x2E, 0x62, 0x11, 0x74, 0xAF, 0x05, 0xD9, 0x41, 0xCA, 0x6E, 0x37, 0x0C },
		{ 0x0B, 0x96, 0x15, 0xD8, 0xE4, 0x3F, 0xE3, 0xC0, 0xB6, 0xAE, 0x43, 0x45, 0xA8, 0x21, 0x0A, 0x1B },
		{ 0x89, 0xD3, 0x17, 0xBA, 0x5B, 0x64, 0xAD, 0x87, 0x87, 0x7D, 0x7B, 0xA5, 0xF4, 0xE2, 0x7A, 0x8D },
		{ 0x15, 0x28, 0xFB, 0x67, 0xD7, 0x7F, 0xA6, 0x58, 0xC8, 0x3F, 0xCD, 0xB9, 0x1F, 0x01, 0x17, 0x5D },
		{ 0xA7, 0x29, 0x19, 0x28, 0xAF, 0x4C, 0x68, 0x43, 0x9D, 0xA6, 0xA3, 0xCF, 0x0A, 0x16, 0xE9, 0x87 }
	};
	
	std::vector<std::string> stringMat;
	int ** matrix, **matReverse, width = 4;

	//Take input, else use the first 16 lines of the data
	std::cout << "Take input matrix? x * 16 byte hex string please." << std::endl;
	std::string ans;
	std::getline(std::cin, ans);

	//If you want to use alternate data, take input here
	if (ans.find('y') != std::string::npos || ans.find('Y') != std::string::npos) {
		//Length input taken in and dynamic arrays created.
		std::cout << "How many lines? (each line is 16 bytes)" << std::endl;
		std::getline(std::cin, ans);
		length = std::stoi(ans);
		matrix = new int*[length];
		matReverse = new int*[length];
		for (int i = 0; i < length; i++) {
			matrix[i] = new int[size];
			matReverse[i] = new int[size];
		}
		stringMat.resize(length);

		//New matrix taken in. Whitespace removed.
		std::cout << "Input each line, followed by an endline.\n";
		for (int i = 0; i < length; i++) {
			std::getline(std::cin, stringMat.at(i));
			stringMat.at(i).erase(std::remove_if(stringMat.at(i).begin(), stringMat.at(i).end(), ::isspace), stringMat.at(i).end());
		}

		for (int i = 0; i < length; i++) {
			for (int j = 0; j < size; j++) {
				//Populating the "matrix" data structure with input from string (string is in hex).
				std::string str = "";
				str += stringMat.at(i).at(2 * j);
				str += stringMat.at(i).at(2 * j + 1);
				matrix[i][j] = std::stoi(str, nullptr, 16);
			}
		}
	}
	else {
		//If no input is taken, then populate "matrix" with default values.
		matrix = new int*[length];
		matReverse = new int*[length];
		for (int i = 0; i < length; i++) {
			matrix[i] = new int[size];
			matReverse[i] = new int[size];
		}

		for (int i = 0; i < length; i++) {
			for (int j = 0; j < size; j++) {
				matrix[i][j] = defaultMat[i][j];
			}
		}
	}

	

	//Swaps bytes around in blocks of 4 bytes
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < size; j++) {
			switch (j % width)
			{
			case 0 :
				matReverse[i][j] = matrix[i][j + 3];
				break;
			case 1:
				matReverse[i][j] = matrix[i][j + 1];
				break;
			case 2:
				matReverse[i][j] = matrix[i][j - 1];
				break;
			case 3:
				matReverse[i][j] = matrix[i][j - 3];
				break;

			default:
				std::cerr << "Error in input stream\n";
				return 1;
			}
		}
	}

	//Prints the byte-reversed matrix.
	std::cout << "\nBytes reversed (bytes[0:3] = bytes[3:0]): \n";
	printMat(matReverse, length);

	//Reverses every individual byte within "matrix" & prints resulting array.
	std::cout << "\nBits reversed (each bit: bit[0:7] = bit[7:0]): \n";
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < size; j++) {
			matReverse[i][j] = reverseBits(matReverse[i][j]);
		}
	}
	printMat(matReverse, length);

	//Completely reverses matrix (not just wordwise, bitwise or bytewise)
	std::cout << "\nCompletely reversed: \n";
	matReverse = reverseMatrixWordwise(matReverse, length);
	printMat(matReverse, length);

	//Memory cleanup.
	delete(matrix);
	delete(matReverse);
	return 0;
}					