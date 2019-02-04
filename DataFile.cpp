#include "DataFile.h"

using namespace std;

DataFile::DataFile() { archivo = new fstream(); }

DataFile::DataFile(char *dir)
{
	this->direccion = dir;
	archivo = new fstream();
}



DataFile::~DataFile()
{
	delete archivo;
	delete this->direccion;
}

void DataFile::abrir()
{
	archivo->open(this->direccion, ios::in | ios::out | ios::binary);
}

void DataFile::abrir(ios_base::openmode tipo)
{
	archivo->open(this->direccion, tipo);
}

void DataFile::cerrar() { archivo->close(); }

void DataFile::escribir(char *inf, int posicion,  int t)
{
	archivo->seekp(0, ios::beg);
	archivo->seekp(posicion);

	archivo->write(inf, t);
}

void DataFile::escribir(char *inf, int t)
{
	archivo->write(inf, t);
}

char *DataFile::leer(int posicion, int t)
{
	char *leido = new char[t];

	archivo->seekg(posicion);
	archivo->read(leido, t);

	return leido;
}

long DataFile::pp() { return archivo->tellp(); }

long DataFile::pg()
{
	return archivo->tellg();
}

bool DataFile::isEmpty()
{
	return archivo->peek() == ifstream::traits_type::eof();
}