#include <algorithm>
#include "TaskManager.h"

using namespace task;

TaskManager::TaskManager() 
{
	this->m_size = 0;
	this->m_capacity = 8;
	this->m_tasks = new Task[m_capacity];
}

TaskManager::TaskManager(const Task& task)
{
	this->m_size = 1;
	this->m_capacity = 4;
	this->m_tasks = new Task[m_capacity];
	
	this->m_tasks[0] = task;
}

TaskManager::TaskManager(const Task* tasks, const size_t size)
{
	if (tasks == nullptr && size > 0)
		throw std::invalid_argument("Tasks cannot be null when size > 0");

	this->m_size = size;
	this->m_capacity = size + 16;
	this->m_tasks = new Task[m_capacity];

	if (tasks != nullptr)
		std::copy(tasks, tasks + size, this->m_tasks);
}

// Rule of 5
TaskManager::TaskManager(const TaskManager& other)
{
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;

	if (this->m_capacity < 8) this->m_capacity = 8;
	
	this->m_tasks = new Task[m_capacity];

	if (other.m_tasks != nullptr && this->m_size > 0)
	{
		for (size_t i = 0; i < m_size; ++i)
			m_tasks[i] = other.m_tasks[i];
	}
}

TaskManager& TaskManager::operator=(const TaskManager& other)
{
	// copy and swap idiom to prevent edge cases
	if (this != &other)
	{
		TaskManager temp(other);

		std::swap(this->m_size, temp.m_size);
		std::swap(this->m_capacity, temp.m_capacity);
		std::swap(this->m_tasks, temp.m_tasks);
	}

	return *this;
}

TaskManager::TaskManager(TaskManager&& other) noexcept
{
	// Move all attributes
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
	this->m_tasks = other.m_tasks;

	// Remove all info from other
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_tasks = nullptr;
}

TaskManager& TaskManager::operator=(TaskManager&& other) noexcept 
{
	// Check if same instance
	if (this == &other)
		return *this;

	// Check if m_tasks has any allocated memory
	delete[] this->m_tasks;

	// Move all attributes
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
	this->m_tasks = other.m_tasks;

	// Remove all info from other
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_tasks = nullptr;

	return *this;
}

TaskManager::~TaskManager()
{
	delete[] this->m_tasks;
	m_tasks = nullptr;
}

// Methods
void TaskManager::addTask(const Task& task)
{
	if (this->m_size == this->m_capacity) // if the size of the array is the same as the allocated memory
	{
		this->m_capacity = (m_capacity == 0) ? 8 : m_capacity;

		Task* newTasks = new Task[m_capacity];
		for (size_t i = 0; i < this->m_size; ++i) // Deep copy to new allocated block
			newTasks[i] = m_tasks[i];
		delete[] this->m_tasks;
		this->m_tasks = newTasks;
	}

	this->m_tasks[this->m_size] = task;
	++this->m_size;
}

void TaskManager::addTask(const std::string& taskText)
{
	if (this->m_size == this->m_capacity)
	{
		this->m_capacity = (m_capacity == 0) ? 8 : m_capacity * 2;

		Task* newTasks = new Task[m_capacity];
		for (size_t i = 0; i < this->m_size; ++i)
			newTasks[i] = m_tasks[i];
		delete[] this->m_tasks;
		this->m_tasks = newTasks;
	}

	const Task task(taskText);
	this->m_tasks[this->m_size] = task;
	++this->m_size;
}

void TaskManager::markComplete(size_t index)
{
	if (index >= this->m_size)
		throw std::out_of_range("Invalid task index");

	this->m_tasks[index].setCompleted(true);
}

void TaskManager::removeTask(size_t index)
{
	if (index >= this->m_size)
		throw std::out_of_range("Invalid task index");

	for (size_t i = index; i < this->m_size - 1; ++i)
		this->m_tasks[i] = this->m_tasks[i + 1];

	--this->m_size;
}