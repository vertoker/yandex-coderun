/*
	Имя - knight-move
	URL - https://coderun.yandex.ru/problem/knight-move
	Сложность - Средняя
	Тэги - dynamic_programming_2D

	Сложность (время)  ≈ O(max(M, N) / 2)
	Сложность (память) = O(M * N)

	Я нашёл в интернете самое очевидное решение, но потом
    обнаружил, что это треугольник Паскаля и я переписал его,
    чтобы он его строил до конца доски
    
    Ресурсы:
        https://site.ada.edu.az/~medv/acm/Docs%20e-olimp/Volume%2041/4021.htm

	made by vertoker
*/

#include <iostream>
#include <cstdint>

int main()
{
	uint16_t N, M;
	std::cin >> N >> M;

	uint32_t weights[M][N] {};

    weights[0][0] = 1;

    // Самая очевидная реализация, сложность O(M * N)
    /*for (uint16_t y = 2; y < N; ++y)
	{
        for (uint16_t x = 2; x < M; ++x)
		{
			weights[x][y] = weights[x-1][y-2] + weights[x-2][y-1];
		}
	}*/

    if (2 < M && 1 < N) weights[2][1] = 1;
    if (1 < M && 2 < N) weights[1][2] = 1;

    // Более оптимизированная реализация как треугольник Паскаля, сложность примерно ≈O( max(M, N) / 2 )
    uint16_t pascalCounter = 3, x = 4, y = 2;
    while (true)
    {
        bool any = false;
        for (uint16_t i = 0; i < pascalCounter; ++i)
        {
            size_t layerX = x - i;
            if (layerX >= M) continue;
            size_t layerY = y + i;
            if (layerY >= N) continue;

            weights[layerX][layerY] = weights[layerX - 1][layerY - 2] + weights[layerX - 2][layerY - 1];
            any = true;
        }

        if (!any) break;
        ++pascalCounter; x += 2, ++y;
    }
    
    std::cout << weights[M-1][N-1];

    // Тестовый вывод
    /*std::cout << std::endl << std::endl;
    for (uint16_t y = 0; y < N; ++y)
	{
        for (uint16_t x = 0; x < M; ++x)
		{
            std::cout << weights[x][y] << ' ';
		}
        std::cout << std::endl;
	}*/
    
	return 0;
}