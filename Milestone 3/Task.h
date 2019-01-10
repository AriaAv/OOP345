// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-12-02
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef M3_TASK_H
#define M3_TASK_H

#include <deque>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item { 

private:

	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

public:

	Task(const std::string&);
	Task(Task&) = delete;
	Task& operator=(Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;
	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};

#endif 



