#include <stdio.h>
#include <cstdlib>
#include <string.h>

#include "Leerlinea.h"

using namespace std;

class users
{
	public:
		void menuListarUsuarios() {
			int numeroUsuarios = 0;
			Usuario *usuarios;
			int i;

			system("cls");
			usuarios = obtenerUsuarios(&numeroUsuarios); /* Retorna un vector dinámico de usuarios */

			if (numeroUsuarios == 0) {
				printf("\n\tNo existe ningun usuario registrado!\n");

			} else {
				printf("\n\t\t    ==> LISTADO DE USUARIOS REGISTRADOS <==\n");
				printf(" ------------------------------------------------------------------------------\n");
				printf("%10s%25s%25s\n", "#", "NOMBRE", "PASSWORD");
				printf(" ------------------------------------------------------------------------------\n");

				/* Se recorre el vector dinámico de productos */
				for (i = 0; i < numeroUsuarios; i++) {
					printf("%10d%25s%25s\n", (i + 1), usuarios[i].nombre, usuarios[i].password);
				}
				printf(" ------------------------------------------------------------------------------\n");
			}

			// Se libera la memoria asignada al vector dinámico
			free(usuarios);
			usuarios = NULL;
			getchar();
		}
		
		
		
		
	private:
		
		char linea[80];
		
		struct usuario {
			char nombre[80];
			char password[80];
		};
		
		
		
		typedef struct usuario Usuario;
		
		
		
		Usuario *obtenerUsuarios(int *n) {
			FILE *archivo;
			Usuario usuario;
			Usuario *usuarios; /* Vector dinámico de usuarios */
			int i;

			/* Abre el archivo en modo lectura */
			archivo = fopen("usuarios.dat", "rb");

			if (archivo == NULL) { /* Si no se pudo abrir el archivo, el valor de archivo es NULL */
				*n = 0; /* No se pudo abrir. Se considera n = 0 */
				usuarios = NULL;

			} else {

				fseek(archivo, 0, SEEK_END); /* Posiciona el cursor al final del archivo */
				*n = ftell(archivo) / sizeof(Usuario); /* # de usuarios almacenados en el archivo. (# de registros) */
				usuarios = (Usuario *)malloc((*n) * sizeof(Usuario)); /* Se asigna memoria para todos los usuarios almacenados en el archivo */

				/* Se recorre el archivo secuencialmente */
				fseek(archivo, 0, SEEK_SET); /* Posiciona el cursor al principio del archivo */
				fread(&usuario, sizeof(usuario), 1, archivo);
				i = 0;
				while (!feof(archivo)) {
					usuarios[i++] = usuario;
					fread(&usuario, sizeof(usuario), 1, archivo);
				}

				/* Cierra el archivo */
				fclose(archivo);
			}

			return usuarios;
		}
		
		
		char existeUsuario(char nombreUsuario[], Usuario* usuario) {
			FILE *archivo;
			char existe;
		
			/* Abre el archivo en modo de lectura */
			archivo = fopen("usuarios.dat", "rb");
		
			if (archivo == NULL) {
				existe = 0;
		
			} else {
				existe = 0;
		
				/* Lee secuencialmente del archivo de usuarios */
				fread(&(*usuario), sizeof(*usuario), 1, archivo);
				while (!feof(archivo)) {
					if (strcmp((*usuario).nombre, nombreUsuario) == 0) {
						/* Encuentra un usuario del archivo con el nombre de usuario buscado */
						existe = 1;
						break;
					}
		
					fread(&(*usuario), sizeof(*usuario), 1, archivo);
				}
		
				/* Cierra el archivo*/
				fclose(archivo);
			}
		
			return existe;
		}
		
		
};
