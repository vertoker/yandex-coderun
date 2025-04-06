/*
	Имя - cheapest-way
	URL - https://coderun.yandex.ru/problem/cheapest-way
	Сложность - Средняя
	Тэги - dynamic_programming_2D

	Сложность (время)  = O(N * M)
	Сложность (память) = O(N * M)

	Классическая задача на динамическое программирование.
	Для оптимизации сложности по памяти, я использовал тот же массив
	и сразу после ввода значения сразу после вычислял вес клетки
	относительно предыдущих

	made by vertoker
*/

#include <iostream>
#include <cstdint>

int main() 
{
	uint16_t N, M;
	std::cin >> N >> M;

	// max = (20 + 20) * 100 = 4000
	uint16_t weights[N][M];

	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < M; ++j)
		{
			// Ввод
			std::cin >> weights[i][j];

			// Расчёт текущей клетки на основе предыдущей
			if (i != 0 && j != 0)
				weights[i][j] += std::min( weights[i-1][j], weights[i][j-1] );
			else if (i != 0)
				weights[i][j] += weights[i-1][j];
			else if (j != 0)
				weights[i][j] += weights[i][j-1];
		}
	}

	std::cout << weights[N-1][M-1];

	return 0;
}