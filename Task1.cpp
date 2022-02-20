#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string stringTransform(const std::string& str)
{
	std::unordered_map<char, std::vector<size_t>> storage;
	std::string result(str.size(), '(');
	for(size_t i = 0; i < str.size(); ++i)
	{
		storage[tolower(str[i])].push_back(i);
	}
	for(const auto& [ch, positions] : storage)
	{
		if(positions.size() > 1)
		{
			for(const auto& pos : positions)
			{
				result[pos] = ')';
			}
		}
	}
	return result;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::string str;
	std::getline(std::cin, str);
	std::cout << stringTransform(str);
}