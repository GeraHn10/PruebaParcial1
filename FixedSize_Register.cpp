
#include "fixedsize_register.h"

#include <cstring>
#include <iostream>
using namespace std;

FixedSize_Register::FixedSize_Register()
{
	this->name = new char[30];
	this->job = new char[20];
}

void FixedSize_Register::print_Register()
{
	cout << "Id: " << this->code << endl;
	cout << "Name: " << this->name << endl;
	cout << "Job: " << this->job << endl;
	cout << "Salary: " << this->salary << endl;
}

char *FixedSize_Register::toChar()
{
	const int size = this->get_size();
	char *data = new char[size];

	memcpy(data, reinterpret_cast<char *>(&this->code), sizeof(this->code));
	data += sizeof(this->code);
	memcpy(data, this->name, 30);
	data += 30;
	memcpy(data, reinterpret_cast<char *>(&this->salary), sizeof(this->salary));
	data += sizeof(this->salary);
	memcpy(data, this->job, 20);

	return data;
}

void FixedSize_Register::fromChar(char *cast)
{
	memcpy(&this->code, cast, sizeof(this->code));
	cast += sizeof(this->code);
	memcpy(this->name, cast, 30);
	cast += 30;
	memcpy(&this->salary, cast, sizeof(this->salary));
	cast += sizeof(this->salary);
	memcpy(this->job, cast, 20);
}

void FixedSize_Register::open_file(char *n)
{
	this->file = new DataFile(n);
}

void FixedSize_Register::write_into_file()
{
	this->file->abrir();
	this->file->escribir(toChar(), get_size());
	this->file->cerrar();
}

void FixedSize_Register::read_into_file(int posicion)
{
	this->file->abrir();
	char *data = this->file->leer(posicion, this->get_size());
	this->fromChar(data);
	this->file->cerrar();
	delete data;
}

void FixedSize_Register::close_file()
{
	this->file->cerrar();
}

int FixedSize_Register::get_size()
{
	return sizeof(this->code) + 30 + 20 + sizeof(this->salary);
}
