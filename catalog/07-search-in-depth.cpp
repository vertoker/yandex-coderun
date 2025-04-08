/*
	Имя - 07-search-in-depth
	URL - https://coderun.yandex.ru/problem/search-in-depth
	Сложность - Лёгкая
	Тэги - dfs

	Сложность (время)  = ЗАМЕНИТЬ_НА_COMPLEXITY_TIME
	Сложность (память) = ЗАМЕНИТЬ_НА_COMPLEXITY_MEMORY

	ЗАМЕНИТЬ_НА_КРАТКОЕ_ОПИСАНИЕ_РЕШЕНИЯ

	made by vertoker
*/

// ЗАДАЧА НЕ РЕШЕНА
// Не проходит дальше 12 теста, закрытого теста

#include <iostream>
#include <cstdint>
#include <map>
#include <vector>
#include <bitset>

typedef std::multimap<uint16_t, uint16_t> Links_t;
typedef std::vector<bool>                 Result_t;

void Process(Links_t& links, Result_t& result, uint16_t* sum, uint16_t key)
{
	auto range = links.equal_range(key);

	for (auto i = range.first; i != range.second; ++i)
	{
		uint16_t value = i->second;
		if (!result[value])
		{
			result[value] = true;
			++*sum;
			Process(links, result, sum, value);
		}
	}
}

int main()
{
	uint16_t N, M; // N <= 1000, M <= 50000
	std::cin >> N >> M;

	std::multimap<uint16_t, uint16_t> links;
	
	for (size_t i = 0; i < M; ++i)
	{
		uint16_t first, second;
		std::cin >> first >> second;
		links.insert(std::make_pair(first, second));
		links.insert(std::make_pair(second, first));
	}
	
	uint16_t sum = 1;
	std::vector<bool> result(N + 1, false);
	result[1] = true;
	
	Process(links, result, &sum, 1);
	
	std::cout << sum << std::endl;
	for (size_t i = 1; i <= N; i++)
	{
		if (result[i])
			std::cout << i << ' ';
	}
	
	return 0;
}