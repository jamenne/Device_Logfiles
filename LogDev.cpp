/*

LogDev.cpp


Created by Janine Müller on 18.10.2016

*/

#include <gpib/ib.h>
#include <gpib/gpib_user.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "time.h"
#include <iomanip>

#include "LogDev.h"


using namespace std;

//---------------------LogDev class---------------------//

// Constructor
LogDev::LogDev() : 
	_path(),
	_file()

{

};

//Destructor
LogDev::~LogDev(){

};

string LogDev::Date()
{
   time_t seconds = time(NULL);

   struct tm * timeinfo = localtime(&seconds);

   ostringstream oss;
   oss << (timeinfo->tm_year + 1900) << "-" << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1) << "-" << std::setw(2) << std::setfill('0') << timeinfo->tm_mday; 
   string data = oss.str();

   return data;
}

string LogDev::DateTime()
{
   time_t seconds = time(NULL);

   struct tm * timeinfo = localtime(&seconds);

   ostringstream oss;
   oss << (timeinfo->tm_year + 1900) << "-" << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1) << "-" << std::setw(2) << std::setfill('0') << timeinfo->tm_mday  << "-" << std::setw(2) << std::setfill('0') << timeinfo->tm_hour << "_" << std::setw(2) << std::setfill('0') << timeinfo->tm_min << "_" << std::setw(2) << std::setfill('0') << timeinfo->tm_sec; 
   string data = oss.str();

   return data;
}

string LogDev::Time()
{
   time_t seconds = time(NULL);

   struct tm * timeinfo = localtime(&seconds);

   ostringstream oss;
   oss << std::setw(2) << std::setfill('0') << timeinfo->tm_hour << "_" << std::setw(2) << std::setfill('0') << timeinfo->tm_min << "_" << std::setw(2) << std::setfill('0') << timeinfo->tm_sec; 
   string data = oss.str();

   //cout << data << endl;

   return data;
}

void LogDev::Initialize(const string& file_name_base){

	stringstream ss;

	ss << "/home/e5-hardware/data/" << this->Date(); 

	string help = "mkdir " + ss.str();

	int returnval = system(help.c_str());

	this->_path.str("");

	this->_path << ss.str() << "/" << this->DateTime() << "_" << file_name_base <<".txt";

	//cout << this->_path.str() << endl;
	this->_file.open(this->_path.str().c_str());
	this->_file.close();
}

void LogDev::Close(){

	this->_file.close();
	//this->~LogDev();
}

void LogDev::WriteString(const string& string_to_write){

	this->_file.open(this->_path.str().c_str(), fstream::in | fstream::out | fstream::app);

	this->_file << string_to_write << endl;

	this->_file.close();

}

void LogDev::Write(const string& string_to_write){

	this->_file.open(this->_path.str().c_str(), fstream::in | fstream::out | fstream::app);

	this->_file << this->Time() << "\t" << string_to_write << endl;

	this->_file.close();

}

void LogDev::WriteMeasurement(vector<double> vector_to_write){

	this->_file.open(this->_path.str().c_str(), fstream::in | fstream::out | fstream::app);

	this->_file << this->Time() << "\t" << vector_to_write[0] << "\t" << vector_to_write[1] << endl;

	this->_file.close();

}

void LogDev::WriteSingleMeasurement(double double_to_write){

	this->_file.open(this->_path.str().c_str(), fstream::in | fstream::out | fstream::app);

	this->_file << this->Time() << "\t" << double_to_write << endl;

	this->_file.close();

}

void LogDev::WriteDoubleAndVector(double double_to_write, vector<double> vector_to_write){

	this->_file.open(this->_path.str().c_str(), fstream::in | fstream::out | fstream::app);

	this->_file << this->Time() << "\t" << double_to_write << "\t" << vector_to_write[0] << "\t" << vector_to_write[1] << endl;

	this->_file.close();

}










