#pragma once
#ifndef DATAFILE_H
#define DATAFILE_H

#include <fstream>
using namespace std;
class DataFile
{


public:
	
	DataFile();
	DataFile(char *path);
	~DataFile();
	void abrir();
	void abrir(std::ios_base::openmode mode);
	void cerrar();
	void escribir(char *,  int , int);
	void escribir(char *,  int);
	char *leer(int , int);
	long pp();
	long pg();
	bool isEmpty();
   std::fstream *archivo;

private:
	char *direccion;
};

#endif