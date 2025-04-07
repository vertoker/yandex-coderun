/*
	Имя - Кафе
	URL - https://coderun.yandex.ru/problem/cafe
	Сложность - Средняя
	Тэги - dynamic_programming_2D

	Сложность (время)  = ЗАМЕНИТЬ_НА_COMPLEXITY_TIME
	Сложность (память) = ЗАМЕНИТЬ_НА_COMPLEXITY_MEMORY

	ЗАМЕНИТЬ_НА_КРАТКОЕ_ОПИСАНИЕ_РЕШЕНИЯ

	made by vertoker
*/

// ЗАДАЧА НЕ РЕШЕНА
// Лучшее решение - переписать весь код с нуля

#include <iostream>
#include <cstdint>

struct Decision
{
    uint16_t sum     = 0;
    uint16_t unused  = 0;
    uint16_t used    = 0;
    bool     invalid = false;
    bool     prevUse = false;

    void Add(uint16_t price)
    {
        sum += price;
        if (price > 100)
            ++unused;
    }
    void UseCoupon()
    {
        --unused;
        ++used;
    }
};

int main()
{
    // Ввод данных

	size_t N;
	std::cin >> N;

	int16_t costs[N];
    for (uint16_t i = 0; i < N; ++i)
        std::cin >> costs[i];

    // Исключение если N == 0
    if (N == 0)
    {
        std::cout << "0" << std::endl;
        std::cout << "0 0";
        return 0;
    }

    // Создание матрицы решений

    // x -> use, y -> not use
    Decision decisions[N][N] {};
    
    decisions[0][0].Add(costs[0]);
    for (size_t i = 1; i < N; ++i)
    {
        for (size_t l = 0; l < i + 1; ++l)
        {
            size_t x = i - l;
            size_t y = l;

            if (x > 0 && y > 0) // выбор между use и not use
            {
                Decision newX = decisions[x-1][y];
                Decision newY = decisions[x][y-1];

                if (!newX.invalid)
                {
                    if (newX.unused > 0)
                    {
                        newX.UseCoupon();
                        newX.prevUse = true;
                    }
                    else newX.invalid = true;
                }
                newY.Add(costs[i]);
                newY.prevUse = false;

                decisions[x][y] = (!newX.invalid && newX.sum < newY.sum) ? newX : newY;
            }
            else if (x > 0) // только use
            {
                Decision newX = decisions[x-1][y];

                if (!newX.invalid)
                {
                    if (newX.unused > 0)
                    {
                        newX.UseCoupon();
                        newX.prevUse = true;
                    }
                    else newX.invalid = true;
                }

                decisions[x][y] = newX;
            }
            else // y > 0 // только not use
            {
                Decision newY = decisions[x][y-1];
                newY.Add(costs[i]);
                newY.prevUse = false;
                decisions[x][y] = newY;
            }
        }
    }

    // Тестовый вывод

    /*for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < N; x++)
        {
            auto decision = decisions[x][y];
            if (decision.invalid)
                std::cout << "invalid | ";
            else
            {
                std::cout << decision.sum << ' ';
                std::cout << decision.unused << ' ';
                std::cout << decision.used << ' ';
                std::cout << std::boolalpha << decision.prevUse << std::noboolalpha;
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
    }*/

    // Расчёт результата

    Decision result;
    size_t useCount = 0;
    size_t resultX = 0, resultY = 0;
    result.sum = 65535;
    
    for (size_t x = N - 1, y = 0; y < N; ++y, --x)
    {
        Decision newResult = decisions[x][y];
        if (newResult.invalid) continue;
        
        if (newResult.sum < result.sum 
            || newResult.sum == result.sum && newResult.unused > result.unused)
        {
            result = newResult;
            useCount = x;
            resultX = x;
            resultY = y;
        }
    }

    uint16_t steps[useCount];
    size_t x = resultX, y = resultY;
    size_t counterSize = 0;
    
    while (x != 0 && y != 0)
    {
        if (decisions[x][y].prevUse)
        {
            steps[counterSize++] = x + y + 1;
            --x;
        }
        else --y;
    }
    
    // Вывод результата

    std::cout << result.sum << std::endl;
    std::cout << result.unused << ' ' << result.used << std::endl;
    while (counterSize != 0)
        std::cout << steps[--counterSize] << std::endl;
    
	return 0;
}