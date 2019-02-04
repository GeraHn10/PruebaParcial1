#pragma once
#ifndef KNOWNVARSIZE_REGISTER_H
#define KNOWNVARSIZE_REGISTER_H

#include "datafile.h"

class KnownVarSize_Register
{
private:
	DataFile *file;
	int code;
	int sizeName;
	char *name;
	double salary;
	int sizeJob;
	char *job;

public:
	KnownVarSize_Register();
	

	void print_register();
	char *toChar();
	void fromChar(char *);
	void open_file(char *);
	void write_into_file();
	void read_into_file(int);
	void close_file();
	int get_size();
};
#endif