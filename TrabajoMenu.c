/*DISTRIBUCION DE ALUMNOS EN UN EXAMEN.
AUTORAS: Paula De Antonio Grondona							
		 Maria Dolores de la Fuente Fernandez							
		 Ines Reviejo vaillo
*/

#include<stdio.h>
#include<string.h>

#define NUMEROALUMNOS 3 

struct Registro{
	int matricula;
	char nombre[20];
	char apellidos[50];
	char correo[100];
	int telefono;
	char contrasena[20];
	char contrasena2[20];
};

int main()
{
	struct Registro registro_alumno[NUMEROALUMNOS];
	
	int i=0;
	char opcion, opcion1;
	// Variables iniciar sesion
	int matricula;
	char password[20];
	char contrasenainicio[20];
	// Variables recuperar contraseña
	char nombrecontrasena[20], apellidoscontrasena[50], correocontrasena[100];
	
	do{
		printf("MENU:\n");
		printf("A. Registrarse.\n");
		printf("B. Iniciar sesion.\n");
		printf("C. Salir.\n");
		
		printf("Selecciona una opcion: ");
		fflush(stdin);
		scanf("%c", &opcion);
		fflush(stdin);
		printf("\n");		
			
		switch(opcion){
			case 'A':
			case 'a':{
				printf("Numero de registro %d\n", i+1); //Para contabilizar el numero de alumnos registrados y poder guardarlos: i.
				
				printf("Numero de matricula: ");
				scanf("%d", &registro_alumno[i].matricula);
				printf("Nombre: ");
					fflush(stdin);
					gets(registro_alumno[i].nombre);
				printf("Apellidos: ");
					gets(registro_alumno[i].apellidos);
				printf("Correo electronico: ");
					gets(registro_alumno[i].correo);
				printf("Telefono de contacto: ");
					scanf("%d", &registro_alumno[i].telefono);
										
				fflush(stdin);
								
				do{
					printf("Contrasena: ");
					fflush(stdin);
					scanf("%s", registro_alumno[i].contrasena);
				
					printf("Repetir contrasena: ");
					fflush(stdin);
					scanf("%s",registro_alumno[i].contrasena2);
					
					if (strcmp(registro_alumno[i].contrasena, registro_alumno[i].contrasena2)!=0){
						printf("Las contrasenas no coinciden, intentelo de nuevo. \n");
					}
				}while(strcmp(registro_alumno[i].contrasena, registro_alumno[i].contrasena2)!=0);
				
				printf("\nREGISTRO COMPLETADO\n\n");
				
				i++;
			break;
			}
				
			case 'B':
			case 'b':
			{
				printf("INICIAR SESION\n");
				printf("Pulse 'M' si desea volver al menu principal. \n\n");
				printf("Numero de matricula: ");
				scanf("%i",&matriculainicio);
				printf("\n");
				switch (matriculainicio){
					case 'M':
					case 'm':{
						fflush(stdin);
						printf("Volviendo a menu principal.\n");
					break;
					}
					
					default:{
						printf("Contraseña: ");
						fflush(stdin);
						scanf("%s",contrasenainicio);
					
						// El programa comprobaría si es un usuario registrado en el fichero, si es asi continuario sino daria error.
						// En el caso de dar error el programa indicaria: "Usuario o contraseña incorrectos"
						// En ese caso el programa volveria a pedir los datos, habria una opcion de "Olvide mi contraseña" en la que el programa pediria:
						
						/*
						printf("Nombre: ");
						fflush(stdin);
						//gets(); 
				
						printf("Apellidos: ");
						fflush(stdin);
						//gets();
						printf("Correo electrónico: ");
						fflush(stdin);
						//scanf
						
						//Si se comprobase que el correo electronico coincidiese con ese nombre de usuario, se proporciona la contraseña, o deja entrar iniciar sesion.
						
						*/
						
					 break;
					}
					
				}
			}
			
			case 'C':
			case 'c':{
				printf("Saliendo del programa.\n");
				break;
			}
			default:
				printf("Opcion incorrecta.\n");
			
		}		
			
	}while(opcion!='D' && opcion!='d');

	return 0;
}
