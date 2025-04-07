/*
	Имя - НОП с восстановлением ответа
	URL - https://coderun.yandex.ru/problem/nop-with-response-recovery
	Сложность - Средняя
	Тэги - dynamic_programming_2D

	Сложность (время)  = O(N * M)
	Сложность (память) = O(N + M)

	ЗАМЕНИТЬ_НА_КРАТКОЕ_ОПИСАНИЕ_РЕШЕНИЯ

	made by vertoker
*/

// ЗАДАЧА НЕ РЕШЕНА
// Решение меня устраивает - а coderun закрытые тесты нет

#include <iostream>
#include <cstdint>

uint16_t CalculateSeq(uint16_t* seq1, uint16_t* seq2, uint16_t N, uint16_t M, size_t i, size_t j)
{
    uint16_t result = 0;
    while (i < N && j < M)
    {
        if (seq1[i] != seq2[j])
            break;
        
        ++i, ++j;
        ++result;
    }
    return result;
}
void Print(uint16_t* seq, uint16_t startIndex, uint16_t length)
{
    if (length > 0)
    {
        std::cout << seq[startIndex];
        ++startIndex, --length;

        while (length > 0)
        {
            std::cout << ' ' << seq[startIndex];
            ++startIndex, --length;
        }
    }
    else std::cout << 0;
}

int main()
{
    // Ввод
    
    uint16_t N;
    std::cin >> N;

    uint16_t seq1[N];
    for (size_t i = 0; i < N; ++i)
        std::cin >> seq1[i];
    
    uint16_t M;
    std::cin >> M;

    uint16_t seq2[M];
    for (size_t i = 0; i < M; ++i)
        std::cin >> seq2[i];
    
    // Проверка всех решений

    uint16_t answerIndexSeq1 = 0;
    uint16_t answerLength = 0;

    for (size_t i = 0; i < N - answerLength; ++i)
    {
        for (size_t j = 0; j < M - answerLength; ++j)
        {
            uint16_t newAnswerLength = CalculateSeq(seq1, seq2, N, M, i, j);
            if (newAnswerLength > answerLength)
            {
                answerLength = newAnswerLength;
                answerIndexSeq1 = i;
            }
        }
    }

    Print(seq1, answerIndexSeq1, answerLength);
    
	return 0;
}