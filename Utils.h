#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <stdexcept>

namespace utils
{
	int input(int& input)
	{
		bool running = true;
		while (running)
		{
			if (std::cin >> input)
			{
				if (std::cin.peek() == '\n') { running = false; }
			}
			else
			{
				std::cout << "Invalid input: Please enter a number.\n";
				std::cin.clear();
				std::cin.ignore(1024, '\n');
			}
		}

		return input;
	}

	int& input(int& input, const int& min, const int& max)
	{
		if (min > max) // Check proper range
		{
			throw std::invalid_argument("min cannot be greater than max");
		}

		bool running = true;
		while (running)
		{
			if (std::cin >> input && (min <= input && input <= max))
			{
				if (std::cin.peek() == '\n') { running = false; }
			}
			else
			{
				std::cout << "Invalid input: Please enter a number that is between " << min << '-' << max << ".\n";
				std::cin.clear();
				std::cin.ignore(1024, '\n');
			}
		}

		return input;
	}

	std::string& input(std::string& input)
	{
		do {
			std::getline(std::cin, input);
			if (input.empty())
				std::cout << "Invalid input. Please enter a valid string.\n";
		} while (input.empty());

		return input;
	}
}

#endif // !UTILS_H
