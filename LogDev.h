/*

LogDev.h


Created by Janine Müller on 18.10.2016


*/

#ifndef ____LogDev__
#define ____LogDev__

#include <fstream>
#include <sstream>
#include <string>
#include <vector>


class LogDev
{

public:
	LogDev();
	~LogDev();
	void Close();

	std::string Date();
	std::string DateTime();
	std::string Time();

	void Initialize(const std::string& file_name_base);

	void WriteString(const std::string& string_to_write);
	void Write(const std::string& string_to_write);
	void WriteMeasurement(std::vector<double> vector_to_write);
	void WriteSingleMeasurement(double double_to_write);
	void WriteDoubleAndVector(double double_to_write, std::vector<double> vector_to_write);

private:

	std::stringstream _path;
	std::fstream _file;

};


#endif /* defined(____LogDev__) */