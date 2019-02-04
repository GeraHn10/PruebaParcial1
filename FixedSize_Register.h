#pragma once
#ifndef FIXEDSIZE_REGISTER_H
#define FIXEDSIZE_REGISTER_H

#include "datafile.h"

class FixedSize_Register
{
private:
	DataFile *file;
	int code;
	char *name;
	double salary;
	char *job;

public:
	FixedSize_Register();
	
	void print_Register();
	char *toChar();
	void fromChar(char *);
	void open_file(char *);
	void write_into_file();
	void read_into_file(int);
	void close_file();
	int get_size();
};

#endif