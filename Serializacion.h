#pragma once
#ifndef Serializacion_H
#define Serializacion_H


#include <fstream>

class Item{

	public:
	int id;
	char name[30];
	char *serializeFixedSize(int id, char name[30], double salary, char job[20]);
	char *serializeKnownVarSize(int id, char *name, double salary, char *job, int sizeName, int sizeJob);
	private:
};

char * Item::serializeFixedSize(int id, char name[30], double salary, char job[20])
{
	char *data = new char[sizeof(int) + 30 + 20 + sizeof(salary)];

	memcpy(data, reinterpret_cast<char *>(&id), sizeof(int));
	data += sizeof(int);
	memcpy(data, name, 30);
	data += 30;
	memcpy(data, reinterpret_cast<char *>(&salary), sizeof(salary));
	data += sizeof(salary);
	memcpy(data, job, 20);

	return data;
}

char *Item::serializeKnownVarSize(int id, char *name, double salary, char *job, int sizeName, int sizeJob)
{
	char *data = new char[sizeof(id) + sizeof(sizeName) + sizeName + sizeof(salary) + sizeof(sizeJob) + sizeJob];

	memcpy(data, reinterpret_cast<char *>(&id), sizeof(id));
	data += +sizeof(id);
	memcpy(data, reinterpret_cast<char *>(&sizeName), sizeof(sizeName));
	data += sizeof(sizeName);
	memcpy(data, name, sizeName);
	data += sizeName;
	memcpy(data, reinterpret_cast<char *>(&salary), sizeof(salary));
	data += sizeof(salary);
	memcpy(data, reinterpret_cast<char *>(&sizeJob), sizeof(sizeJob));
	data += sizeof(sizeJob);
	memcpy(data, job, sizeJob);

	return data;
}

#endif // !Serializacion_H