#pragma once
#include "datafile.h"
#ifndef DelimeterVarSize_H
#define DelimeterVarSize_H


class DelimiterVar
{
private:
	DataFile *file;

	int code;
	char *name;
	double salary;
	char *job;

public:
	DelimiterVar();
	

	void print_register();//
	char *toChar();
	void fromChar(char *data);//
	void read_from_File(int position);//
	void write_into_file();
	int get_size();
};
#endif // !DelimeteVarSize_H