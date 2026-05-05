#include <iostream>
#include "TaskManager.h"
#include "Utils.h"

using namespace std;

// Function definitions.
void printMenu();
void printTitle();

int main(int argc, char* argv[])
{
	task::TaskManager manager;
	bool running = true;

	printTitle();

	do {
		printMenu();

		int choice;
		utils::input(choice, 1, 5);
		std::cin.ignore(); // Clear the stream buffer.

		switch (choice)
		{
		case 1: 
		{
			std::string text;
			std::cout << "Enter task: ";
			utils::input(text);
			manager.addTask(text);
			break;
		}
		case 2: 
		{
			std::cout << manager;
			break;
		}
		case 3:
		{
			
			int index;
			std::cout << "Enter task index: ";
			utils::input(index);

			try 
			{
				manager.markComplete(index);
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
			
			break;
		}
		case 4:
		{
			int index;
			std::cout << "Enter index to remove: ";
			utils::input(index);

			try
			{
				manager.removeTask(index);
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
			
			break;
		}
		case 5: { running = false; break; }

		default: { std::cout << "Invalid option."; std::cout << std::endl; break; } 
			   // Don't know how you would've gotten here, but just incase.
		}

	} while (running);

	std::cout << "\nExiting...\n"; // Exiting program.
	return 0;
}

void printMenu()
{
	std::cout << "+--------------------------------+\n";
	std::cout << "|        TASK MANAGER            |\n";
	std::cout << "+--------------------------------+\n";
	std::cout << "| 1 | Add Task                   |\n";
	std::cout << "| 2 | View Tasks                 |\n";
	std::cout << "| 3 | Mark Task Complete         |\n";
	std::cout << "| 4 | Remove Task                |\n";
	std::cout << "| 5 | Exit                       |\n";
	std::cout << "+--------------------------------+\n";
	std::cout << "Select an option: ";
}

void printTitle()
{
	std::cout << "======================================\n";
	std::cout << "           TASK MANAGER               \n";
	std::cout << "======================================\n\n";
}