#include <iostream>
#include "knownvarsize_register.h"
#include "cstring"

using namespace std;

KnownVarSize_Register::KnownVarSize_Register()
{
}



void KnownVarSize_Register::print_register()
{
	cout << "Id: " << this->code << endl;
	cout << "Name: " << this->name << endl;
	cout << "Job: " << this->job << endl;
	cout << "Salary: " << this->salary << endl;
}

char *KnownVarSize_Register::toChar()
{
	const int size = this->get_size();
	char *data = new char[size];

	memcpy(data, reinterpret_cast<char *>(&this->code), sizeof(this->code));

	memcpy(data + sizeof(this->code), reinterpret_cast<char *>(&this->sizeName), sizeof(this->sizeName));

	memcpy(data + sizeof(this->code) + sizeof(this->sizeName), this->name, this->sizeName);

	memcpy(data + sizeof(this->code) + sizeof(this->sizeName) + this->sizeName, reinterpret_cast<char *>(&this->salary), sizeof(this->salary));

	memcpy(data + sizeof(this->code) + sizeof(this->sizeName) + this->sizeName + sizeof(this->salary), reinterpret_cast<char *>(&this->sizeJob), sizeof(this->sizeJob));

	memcpy(data + sizeof(this->code) + sizeof(this->sizeName) + this->sizeName + sizeof(this->salary) + sizeof(this->sizeJob), this->job, this->sizeJob);

	return data;
}

void KnownVarSize_Register::fromChar(char *inf)
{
	memcpy(&this->code, inf, sizeof(this->code));

	memcpy(&this->sizeName, inf + sizeof(this->code), sizeof(this->sizeName));
	this->name = new char[this->sizeName];

	memcpy(this->name, inf + sizeof(this->code) + sizeof(this->sizeName), this->sizeName);

	memcpy(&this->salary, inf + sizeof(this->code) + sizeof(this->sizeName) + this->sizeName, sizeof(this->salary));

	memcpy(&this->sizeJob, inf + sizeof(this->code) + sizeof(this->sizeName) + this->sizeName + sizeof(this->salary), sizeof(this->sizeJob));
	this->job = new char[this->sizeJob];

	memcpy(this->job, inf + sizeof(this->code) + sizeof(this->sizeName) + this->sizeName + sizeof(this->salary) + sizeof(this->sizeJob), this->sizeJob);
}

void KnownVarSize_Register::open_file(char *n)
{
	this->file = new DataFile(n);
}

void KnownVarSize_Register::write_into_file()
{
	this->file->escribir(this->toChar(), this->get_size());
}

void KnownVarSize_Register::read_into_file(int posicion)
{
	int countSize = 0;
	int posicionD=0;
	while(posicion <= posicionD)
	{
		this->code = *(reinterpret_cast<int *>(this->file->leer(countSize, sizeof(int))));
		this->sizeName = *(reinterpret_cast<int *>(this->file->leer(countSize + sizeof(int), sizeof(int))));
		this->name = this->file->leer(countSize + sizeof(this->code) + sizeof(this->sizeName), this->sizeName);
		this->salary = *(reinterpret_cast<double *>(this->file->leer(countSize + sizeof(this->code) + sizeof(this->sizeName) + this->sizeName, sizeof(double))));
		this->sizeJob = *(reinterpret_cast<int *>(this->file->leer(countSize + sizeof(this->code) + sizeof(this->sizeName) + this->sizeName + sizeof(this->salary), sizeof(int))));
		this->job = this->file->leer(countSize + sizeof(this->code) + sizeof(this->sizeName) + this->sizeName + sizeof(this->salary) + sizeof(this->sizeJob), this->sizeJob);

		countSize += this->get_size();
		posicionD++;
	}
}

void KnownVarSize_Register::close_file()
{
	this->file->cerrar();
}

int KnownVarSize_Register::get_size()
{
	return sizeof(this->code) + sizeof(this->sizeName) + this->sizeName + sizeof(this->salary) + sizeof(this->sizeJob) + this->sizeJob;
}
