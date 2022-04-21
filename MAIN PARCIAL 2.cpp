#include <iostream>


#include "LISTAR USUARIOS.h"
#include "MENUS.h"

using namespace std;

int main()
{
	int encendido=1;
	while (encendido==1)
	{
		int opc;
		Menu inicio;
		opc=inicio.MenuInicial();
		cout << opc;
		switch (opc) {
			case 1:
				usuarios lista;
				lista.menuListarUsuarios();
				encendido =1;
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
	return 0;
}
