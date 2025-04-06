/*
	Имя - median-out-of-three
	URL - https://coderun.yandex.ru/problem/median-out-of-three
	Сложность - Лёгкая
	Тэги - sort

	Сложность (время)  = O(1)
	Сложность (память) = O(1)

	Самая первая задача, у которой решение буквально написано в описании
	То решение полностью объясняет принцип, ну а я предложу самое эффективное
	Моё решение - это просто работа алгоритма сортировки, но с 3 элементами
	Вариантов исхода такого решения - 2^3 = 8, короче большой if-else

	made by vertoker
*/

#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
 
	if (a < b)
		if (a < c)
			if (b < c)
				std::cout << b;
			else // c < b
				std::cout << c;
		else // c < a
			if (a < b)
				std::cout << a;
			else // b < a
				std::cout << b;
	else // b < a
		if (b < c)
			if (a < c)
				std::cout << a;
			else // c < a
				std::cout << c;
		else // c < b
			if (a < b)
				std::cout << a;
			else // b < a
				std::cout << b;

	return 0;
}