#pragma once
#include "DelimeterVarSize.h"
#include <cstring>


#include <string>

using namespace std;

DelimiterVar::DelimiterVar()
{
	this->file = new DataFile((char *)"delimiter_file.dat");
}



void DelimiterVar::write_into_file()
{

	if (this->file->isEmpty())
	{
		this->file->escribir((char *)"|", sizeof(char));
	}

	this->file->escribir(this->toChar(), this->get_size());
}
char *DelimiterVar::toChar()
{
	char recordDelimiter = '|';
	char fieldDelimiter = ';';
	char *data = new char[this->get_size()];

	memcpy(data, reinterpret_cast<char *>(&this->code), sizeof(int));
	data += sizeof(int);
	memcpy(data, &fieldDelimiter, sizeof(char));
	data += sizeof(char);
	memcpy(data, reinterpret_cast<char *>(this->name), strlen(this->name));
	data += strlen(this->name);
	memcpy(data, &fieldDelimiter, sizeof(char));
	data += sizeof(char);
	memcpy(data, reinterpret_cast<char *>(&this->salary), sizeof(double));
	data += sizeof(double);
	memcpy(data, &fieldDelimiter, sizeof(char));
	data += sizeof(char);
	memcpy(data, reinterpret_cast<char *>(this->job), strlen(this->job));
	data += strlen(this->job);
	memcpy(data, &recordDelimiter, sizeof(char));

	return data;
}



int DelimiterVar::get_size()
{
	return sizeof(this->code) + strlen(this->name) + sizeof(this->salary) + strlen(this->job) + 1 + 3;
}