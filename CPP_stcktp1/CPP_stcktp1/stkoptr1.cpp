#include<iostream>
#include<cstdlib>
#include<ctime>
#include"stcktp1.h"
const int Num = 10;
int main()
{
	std::srand(std::time(0));
	std::cout << "스택의 크기를 입력하십시오: ";
	int stacksize;
	std::cin >> stacksize;
	Stack<const char*> st(stacksize);
	const char* in[Num] = {
		"1: 노미호", " 2: 주리혜",
		"3: 이몽룡","4: 성춘향",
		"5: 이수일","6: 심순애",
		"7: 박문수","8: 홍길동",
		"9: 김두한","10: 하야시"
	};
	const char* out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
		std::cout << out[i] << std::endl;
	std::cout << "프로그램을 종료합니다.\n";
	return 0;
}