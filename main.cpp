#include <cstring>
#include <iostream>
#include "datafile.h"
#include "fixedsize_register.h"
#include "Serializacion.h"
#include "KnownVarSize_Register.h"


using namespace std;







int main()
{
	Item s;
	int option;
	bool continueI=true;

	while (continueI == true)
	{
		cout << "---Menu Principal---" << endl;
		cout<< "1. Escribir fixed size file " << endl;
		cout << "2. Leer fixed size file     " << endl;
		cout << "3. Escribir known size file " << endl;
		cout << "4.Leer known size file     " << endl;
		cout << "5.Salir" << endl;
		

		cout << "Ingrese una opción:" << endl;

		cin >> option;

		FixedSize_Register *fixedRegister = new FixedSize_Register();
		KnownVarSize_Register *knownSizeRegister = new KnownVarSize_Register();

		switch (option)
		{
		case 1:

		{
			char Name[30], Job[20];
			int code;
			double Salary;

			fixedRegister->open_file((char *)"primero.dat");

			cout <<"Codigo" << endl;
			cin >> code;

			cout << "Ingrese nombre: " << endl;
			cin >> Name;

			cout << "Ingrese trabajo: " << endl;
			cin >> Job;

			cout << "Ingrese salario: " << endl;
			cin >> Salary;

			char *data = s.serializeFixedSize(code, Name, Salary, Job);

			fixedRegister->fromChar(data);
			fixedRegister->write_into_file();
			fixedRegister->close_file();
		}

		break;

		case 2:

		{
			int fixedPosition;
			cout << "Ingrese la pos: " << endl;
			cin >> fixedPosition;

			fixedRegister->open_file((char *)"segundo.dat");

			fixedRegister->read_into_file(fixedPosition);
			fixedRegister->print_Register();
			fixedRegister->close_file();
		}

		break;

		case 3:

		{
			char SizeName[30], SizeJob[20];
			int SizeId;
			double SizeSalary;

			knownSizeRegister->open_file((char *)"knownSizeFieldFile.dat");

			cout << "Ingrese el id: " << endl;
			cin >> SizeId;

			cout << "Ingrese el nombre: " << endl;
			cin >> SizeName;

			cout << "Ingrese el trabajo: " << endl;
			cin >> SizeJob;

			cout << "Ingrese el salario: " << endl;
			cin >> SizeSalary;

			char *data = s.serializeKnownVarSize(SizeId, SizeName, SizeSalary, SizeJob, sizeof(SizeName), sizeof(SizeJob));

			knownSizeRegister->fromChar(data);
			knownSizeRegister->write_into_file();
		}

		break;
		case 4:

		{
			int knownSizePosition;
			cout << "Ingrese la posición: " << endl;
			cin >> knownSizePosition;

			knownSizeRegister->open_file((char *)"knownSizeFieldFile.dat");

			knownSizeRegister->read_into_file(knownSizePosition);
			knownSizeRegister->print_register();
		}

		break;
		
		case 5:

			continueI = false;

			break;

		cout << "¿Desea continuar, ingrese 's' para continuar? " << endl;
		char f = 's';
		cin >> f;
		if (f != 's') {

			continueI = false;
		}
	}

	return 0;
}