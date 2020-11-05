#include<iostream>
#include<stdio.h>
using namespace std;

struct bitfield { //4bit구조체
	unsigned int bit0 : 1;
	unsigned int bit1 : 1;
	unsigned int bit2 : 1;
	unsigned int bit3 : 1;
};

union uniset { //4bit bitfield와 uniset의 i를 공용체로 만듦
	struct bitfield bit;
	unsigned int num;
};

int AndGate(int n1, int n2) { //AND게이트 함수
	return n1 & n2;
}

int XorGate(int n1, int n2) { //XOR게이트 함수
	return n1 ^ n2;
}

int OrGate(int n1, int n2) { //OR게이트 함수
	return n1 | n2;
}

int main() {
	union uniset n1, n2;
	union uniset c_in, c_out, s;

	//n1과 n2에 두 수 입력받기
	cout << "연산할 두 수를 입력하시오.(0~7)" << endl;
	cout << "n1 = ";
	cin >> n1.num;
	cout << "n2 = ";
	cin >> n2.num;
	cout << endl;

	//c_in의 최하위 비트 초기화
	c_in.bit.bit0 = 0;

	//bit0을 연산
	s.bit.bit0 = XorGate(XorGate(n1.bit.bit0, n2.bit.bit0), c_in.bit.bit0);//논리연산 후 결과를 s에 저장
	c_out.bit.bit0 = OrGate(AndGate(n1.bit.bit0, n2.bit.bit0), AndGate(XorGate(n1.bit.bit0, n2.bit.bit0), c_in.bit.bit0)); 
	//연산 과정에서 발생한 올림수를 c_out에 저장
	c_in.bit.bit1 = c_out.bit.bit0; //올림수 c_out을 c_in의 다음 비트에 저장

	//bit1을 연산
	s.bit.bit1 = XorGate(XorGate(n1.bit.bit1, n2.bit.bit1), c_in.bit.bit1);
	c_out.bit.bit1 = OrGate(AndGate(n1.bit.bit1, n2.bit.bit1), AndGate(XorGate(n1.bit.bit1, n2.bit.bit1), c_in.bit.bit1));
	c_in.bit.bit2 = c_out.bit.bit1;

	//bit2을 연산
	s.bit.bit2 = XorGate(XorGate(n1.bit.bit2, n2.bit.bit2), c_in.bit.bit2);
	c_out.bit.bit2 = OrGate(AndGate(n1.bit.bit2, n2.bit.bit2), AndGate(XorGate(n1.bit.bit2, n2.bit.bit2), c_in.bit.bit2));
	c_in.bit.bit3 = c_out.bit.bit2;

	//bit3을 연산
	s.bit.bit3 = XorGate(XorGate(n1.bit.bit3, n2.bit.bit3), c_in.bit.bit3);
	c_out.bit.bit3 = OrGate(AndGate(n1.bit.bit3, n2.bit.bit3), AndGate(XorGate(n1.bit.bit3, n2.bit.bit3), c_in.bit.bit3));

	//진리표 출력
	cout << "<진리표>" << endl;
	cout << "x, y, c_in, s, c_out" << endl;
	printf("%x, %x,   %x,  %x,  %x\n", n1.bit.bit0, n2.bit.bit0, c_in.bit.bit0, s.bit.bit0, c_out.bit.bit0);
	printf("%x, %x,   %x,  %x,  %x\n", n1.bit.bit1, n2.bit.bit1, c_in.bit.bit1, s.bit.bit1, c_out.bit.bit1);
	printf("%x, %x,   %x,  %x,  %x\n", n1.bit.bit2, n2.bit.bit2, c_in.bit.bit2, s.bit.bit2, c_out.bit.bit2);
	printf("%x, %x,   %x,  %x,  %x\n\n", n1.bit.bit3, n2.bit.bit3, c_in.bit.bit3, s.bit.bit3, c_out.bit.bit3);

	//결과값 출력
	printf("%d + %d = %x%x%x%x + %x%x%x%x = %x%x%x%x\n\n",
		n1.num, n2.num,
		n1.bit.bit3, n1.bit.bit2, n1.bit.bit1, n1.bit.bit0,
		n2.bit.bit3, n2.bit.bit2, n2.bit.bit1, n2.bit.bit0,
		s.bit.bit3, s.bit.bit2, s.bit.bit1, s.bit.bit0);

	system("pause");
	return 0;
}
