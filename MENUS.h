#include <iostream>
#include <cstdlib>


using namespace std;

class Menu
{
	public:
		int MenuInicial()
		{
			int opc;
			system ("cls");
			cout<<"\n\t\t\tMENU INICIAL\n";
			cout<<"\t\t\t============\n";
			cout<<"\n\t\t[1]. Ver usuarios registrados\n";
			cout<<"\t\t[2]. Registrar usuario nuevo\n";
			cout<<"\t\t[3]. Ingresar al sistema\n";
			cout<<"\t\t[0]. Salir\n";
			cout<<"\n\t\tIngrese su opcion: ";
			cin>>opc;
			return opc;
		}
};
