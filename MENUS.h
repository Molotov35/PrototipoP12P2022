#include <iostream>
#include <cstdlib>

#include "LISTAR USUARIOS.h"

using namespace std;

class Menu
{
	public:
		void MenuInicial()
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
			switch (opc) {
			case 1:
				usuarios lista;
				lista.menuListarUsuarios();
				break;

			case 2:
				//menuRegistrarUsuario();
				break;

			case 3:
				//menuIniciarSesion();
				break;

			case 0:
				exit;
			}

		}
};
