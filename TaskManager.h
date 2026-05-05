#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <iostream>
#include <string>
#include "Task.h"

namespace task
{
	class TaskManager
	{
	private:
		Task* m_tasks; // Allocating memory for array rather than vector cause why not.
		size_t m_size;
		size_t m_capacity;
	
	public:
		// Constructors
		TaskManager();
		TaskManager(const Task&);
		TaskManager(const Task*, const size_t);
		
		// Rule of 5
		TaskManager(const TaskManager&);
		TaskManager& operator=(const TaskManager&);

		TaskManager(TaskManager&&) noexcept;
		TaskManager& operator=(TaskManager&&) noexcept;

		~TaskManager();

		// Methods
		void addTask(const Task&);
		void addTask(const std::string&);
		void markComplete(size_t index);
		void removeTask(size_t index);

		// Helper functions
		friend std::ostream& operator<<(std::ostream& os, const TaskManager& taskManager)
		{
			if (taskManager.m_size == 0)
			{
				os << "No tasks found." << std::endl;;
			}
			else
			{
				for (size_t i = 0; i < taskManager.m_size; ++i)
					os << '[' << i << "] " << taskManager.m_tasks[i];
			}
			return os;
		}
	};
}


#endif // !TASK_MANAGER_H