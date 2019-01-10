// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-12-02
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include "LineManager.h"
#include "Utilities.h"
#include <iostream>


size_t m_startTask = 0u;
size_t m_endTask = 0u;
LineManager::LineManager(const std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& customerOrders) {

	size_t m_pos = 0;
	bool m_more = true;
	Utilities utilities;
	std::string record;
	bool isStartingPoint = true;
	std::ifstream file(fileName);


	while (!file.eof()) {
		std::getline(file, record);
		std::string task = "";
		task = utilities.extractToken(record, m_pos, m_more);
		std::string next = "";
		if (m_more)
			next = utilities.extractToken(record, m_pos, m_more);

		for (size_t i = 0u; i < tasks.size(); ++i) {
			if (tasks[i]->getName() == task) {
				if (isStartingPoint) {
					m_startTask = i;
					isStartingPoint = !isStartingPoint;
				}

				if (!next.empty()) {
					for (size_t j = 0; j < tasks.size(); ++j) {
						if (tasks[j]->getName() == next) {
							tasks[i]->setNextTask(*tasks[j]);
							break;
						}
					}
				}
				else {
					m_endTask = i;
				}

				break;
			}
		}

		m_pos = 0;
		m_more = true;
		task.clear();
		next.clear();
	}

	for (size_t i = 0u; i < customerOrders.size(); ++i)
		ToBeFilled.push_back(std::move(customerOrders[i]));
	customerOrders.erase(customerOrders.begin(), customerOrders.end());

	AssemblyLine = tasks;
}

bool LineManager::run(std::ostream& os) {
	CustomerOrder temp;
	bool filled = true;

	if (!ToBeFilled.empty()) {
		*AssemblyLine[m_startTask] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (size_t i = 0u; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->runProcess(os);
	}

	if (AssemblyLine[m_endTask]->getCompleted(temp))
		Completed.push_back(std::move(temp));

	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		if (AssemblyLine[i]->moveTask()) {
			filled = false;

		}
	}

	return filled;
}

void LineManager::displayCompleted(std::ostream& os) const {
	if (!Completed.empty())
		for (size_t i = 0u; i < Completed.size(); ++i)
			Completed[i].display(os);
}

void LineManager::validateTasks() const {
	if (!AssemblyLine.empty())
		for (size_t i = 0u; i < AssemblyLine.size(); ++i)
			AssemblyLine[i]->validate(std::cout);
}