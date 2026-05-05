#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <iomanip>

namespace task {
	class Task
	{
	private:
		std::string m_task;
		bool m_complete;

	public:
		Task();
		Task(const std::string&);

		// Default the copy constructor and assignment
		Task(const Task&) = default;
		Task& operator=(const Task&) = default;
		
		void setTask(const std::string&);
		void setCompleted(const bool);

		const std::string& getTask() const;
		bool getComplete() const;


		// Friend functions
		friend std::ostream& operator<<(std::ostream& os, const Task& task)
		{
			os << "Task: " << std::left << std::setw(20) << task.m_task 
				<< std::right << std::setw(20) << " Current Status: " << (task.m_complete ? "Complete" : "In-Progress") << std::endl;
			return os;
		}
	};
}

#endif // !TASK_H