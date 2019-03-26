#include<stdio.h>

//DISTRIBUCION DE ALUMNOS EN UN EXAMEN: MENU OPCIONES.

/* AUTORAS: Paula De Antonio Grondona							
		Maria Dolores de la Fuente Fernandez							
		Ines Reviejo vaillo
*/

int main()
{
	// Variables registro
	char opcion;	
	int matricula;
	char nombre[20], apellidos[50], telefono[10], correo[100], contrasena[20], contrasena2[20];
	// Variables iniciar sesion
	int matriculainicio;
	char contrasenainicio[20];
	// Variables recuperar contraseña
	char nombrecontrasena[20], apellidoscontrasena[50], correocontrasena[100];
	
	

	do
	{
		printf("MENU:\n");
		printf("A. Registrarse.\n");
		printf("B. Iniciar sesion.\n");
		printf("C. Salir.\n");
		
		printf("Selecciona una opcion.\t");
		fflush(stdin);
		scanf("%c", &opcion);
		fflush(stdin);
		printf("\n");		
			
		switch(opcion)
		{
			case 'A':
			case 'a':
			{
				printf("Numero de matricula: ");
				scanf("%i",&matricula);
				
				printf("Nombre: ");
				fflush(stdin);
				gets(nombre); // para nombres compuestos
				
				printf("Apellidos: ");
				fflush(stdin);
				gets(apellidos);
				
				printf("Telefono de contacto: ");
				fflush(stdin);
				scanf("%s",telefono);
				
				printf("Correo electrónico: ");
				fflush(stdin);
				scanf("%s",correo);
		
				
				do
				{
					
					printf("Contraseña: ");
					fflush(stdin);
					scanf("%s",contrasena);
				
					printf("Repetir contraseña: ");
					fflush(stdin);
					scanf("%s",contrasena2);
					
					if (strcmp(contrasena,contrasena2)!=0)
					{
						printf("Las contraseñas no coinciden, intentelo de nuevo. \n");
					}
					
				}while(strcmp(contrasena,contrasena2)!=0);
				
				printf("\nREGISTRO COMPLETADO\n\n");
				
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
