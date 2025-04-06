/*
	Имя - print-the-route-of-the-maximum-cost
	URL - https://coderun.yandex.ru/problem/print-the-route-of-the-maximum-cost
	Сложность - Средняя
	Тэги - dynamic_programming_2D

	Сложность (время)  = O(N * M)
	Сложность (память) = O(N * M)

	Модификация предыдущего алгоритма, только здесь нужно
    также вывести маршрут оптимального пути. На основе весов,
    я прошёлся с конца до начала, чтобы записать значения направлений
    после чего уже просто их вывел в обратном порядке

	made by vertoker
*/

#include <iostream>
#include <cstdint>
#include <vector>

int main()
{
	uint16_t N, M;
	std::cin >> N >> M;

	// max = (100 + 100) * 100 = 20000
	uint16_t weights[M][N];

    // Ввести карту и сразу же посчитать веса

    for (size_t y = 0; y < N; ++y)
	{
        for (size_t x = 0; x < M; ++x)
		{
			// Ввод
			std::cin >> weights[x][y];

			// Расчёт текущей клетки на основе предыдущей
			if (x != 0 && y != 0)
				weights[x][y] += std::max( weights[x-1][y], weights[x][y-1] );
			else if (x != 0)
				weights[x][y] += weights[x-1][y];
			else if (y != 0)
				weights[x][y] += weights[x][y-1];
		}
	}

    // Сгенерировать маршрут
	
	uint16_t x = M - 1, y = N - 1; // точка старта - конец
	std::vector<bool> directions; // для оптимизации bool пространства
    directions.resize(x + y);
	size_t counter = 0;
	
	std::cout << weights[x][y] << std::endl; // расположение для оптимизации

    bool bx = x != 0, by = y != 0;
	while (bx || by)
	{
		if (bx && by)
        {
            if (weights[x-1][y] > weights[x][y-1])
            {
                directions[counter] = true;
                --x;
            }
            else --y;
        }
		else if (bx)
        {
			directions[counter] = true;
            --x;
        }
		else --y;

		++counter;
        bx = x != 0;
        by = y != 0;
	}

    // Вывести маршрут
    
    if (counter != 0)
	    std::cout << ( directions[--counter] ? 'R' : 'D' );
	while (counter != 0)
		std::cout << ( directions[--counter] ? " R" : " D" );

	return 0;
}