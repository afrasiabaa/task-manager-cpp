#include "Task.h"

using namespace task;

Task::Task()
{
	this->m_task = "";
	this->m_complete = false;
}

Task::Task(const std::string& string)
{
	this->m_task = string;
	this->m_complete = false;
}

void Task::setTask(const std::string& val)
{
	this->m_task = val;
}

void Task::setCompleted(const bool val)
{
	this->m_complete = val;
}

const std::string& Task::getTask() const 
{
	return m_task;
}

bool Task::getComplete() const
{
	return m_complete;
}