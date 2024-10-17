#include "Log.h"
#include<iostream>

Log::Log() : numberOfLogs(0) {};
Log::~Log() {};

void Log::createNewLog(std::string message)
{
	std::map<int, std::string> newLog;
	newLog[numberOfLogs] = message;
	logs.push_back(newLog);
	numberOfLogs++;
}

void Log::printAllLogs()
{
	for (const auto& log : logs)
	{
		for (const auto& pair : log)
		{
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}
}

std::string Log::findLogById(int id)
{
	for (auto& log : logs)
	{
		for (auto& pair : log)
		{
			if (pair.first == id)
			{
				return pair.second;
			}
		}
	}
	return nullptr;
}