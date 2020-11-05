#include <stdio.h> 

#define SWAP_INT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
//INT32변수를 byte swap 

void ConverterPrint(char* value, int n) { // 정렬된 숫자를 출력
	int i;
	for (i = 0; i < n; i++)
		printf(" %.2x", value[i]);
} 

struct bitfield {
	unsigned int bit0 : 1;
	unsigned int bit1 : 1;
	unsigned int bit2 : 1;
	unsigned int bit3 : 1;
	unsigned int bit4 : 1;
	unsigned int bit5 : 1;
	unsigned int bit6 : 1;
	unsigned int bit7 : 1;

	unsigned int bit8 : 1;
	unsigned int bit9 : 1;
	unsigned int bit10 : 1;
	unsigned int bit11 : 1;
	unsigned int bit12 : 1;
	unsigned int bit13 : 1;
	unsigned int bit14 : 1;
	unsigned int bit15 : 1;
};
union uniset { //Share a memory of integer with char 4 bytes and bitfield of 16 bits.
	struct bitfield bit;
	unsigned int number;
	char ch[4];
};

int main() {
	union uniset uni; // union variable
	uni.number = 0x12345678; // save in integer.

	int num;
	num = SWAP_INT32(uni.number);

	printf("\nuni.number = 0x%x\n", uni.number);

	printf("\nThe little endian value is:	");
	ConverterPrint((char*)& uni.number, sizeof(uni.number));

	printf("\nThe Big endian value is:	");
	ConverterPrint((char*)& num, sizeof(num));
	printf("\n\n");

	system("pause");
	return 0;
}
