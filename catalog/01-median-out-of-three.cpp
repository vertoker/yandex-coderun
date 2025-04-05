/*
    Имя - median-out-of-three
	URL       - https://coderun.yandex.ru/problem/median-out-of-three
	Сложность - Easy

	Сложность (время)  - O(1)
	Сложность (память) - O(1)

	made by vertoker
*/

#include <iostream>

int main()
{
	int a, b, c; 
    std::cin >> a >> b >> c;
	
	if (a < b)
		if (a < c)
			std::cout << std::min(b, c) << std::endl;
		else // c < a
			std::cout << std::min(a, b) << std::endl;
	else // b < a
		if (b < c)
			std::cout << std::min(a, c) << std::endl;
		else // c < b
			std::cout << std::min(a, b) << std::endl;

    return 0;
}