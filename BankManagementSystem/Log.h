#pragma once
#include <vector>
#include <string>
#include <map>

class Log
{
public:
	Log();
	~Log();
	int numberOfLogs;
	void createNewLog(std::string message);
	void printAllLogs();
	std::string findLogById(int id);
private:
	std::vector<std::map<int, std::string>> logs;
};

