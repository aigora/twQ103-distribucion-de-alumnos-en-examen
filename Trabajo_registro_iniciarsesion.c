/*DISTRIBUCION DE ALUMNOS EN UN EXAMEN.
AUTORAS: Paula De Antonio Grondona							
		 Maria Dolores de la Fuente Fernandez							
		 Ines Reviejo vaillo
*/

#include<stdio.h>
#include<string.h>

#define NUMERO_ALUMNOS_MAX 100

struct Registro{
	int matricula;
	char nombre[20];
	char apellidos[50];
	char correo[100];
	int telefono;
	char contrasena[20];
	char contrasena2[20];
	char asignatura;
};

int main()
{
	struct Registro registro_alumno[NUMERO_ALUMNOS_MAX];
	int nalumnos = 0; 
	int i;
	char opcion;
	FILE *puntero;
	
	// Variables iniciar sesion
	int j;
	int matricula_inicio;
	int auxiliar_inicio;
	char contrasena_inicio[20];
	char contrasenainicio[20];
	// Variables recuperar contraseña
	char nombrecontrasena[20], apellidoscontrasena[50], correocontrasena[100];
	
	//LEER FICHERO
	puntero= fopen("REGISTRO.txt","r");
	while(fscanf(puntero,"%d\t%c\t%s\t%s\t%s\t%d\t%s\n",
					&registro_alumno[nalumnos].matricula, 
					&registro_alumno[nalumnos].asignatura, 
					registro_alumno[nalumnos].nombre, 
					registro_alumno[nalumnos].apellidos, 
					registro_alumno[nalumnos].correo,
					&registro_alumno[nalumnos].telefono,
					registro_alumno[nalumnos].contrasena) != EOF)
					
	fclose(puntero);
	

	do{
		system("cls");
		printf("***MENU***\n");
		printf("A. Registrarse.\n");
		printf("B. Iniciar sesion.\n");
		printf("C. Salir.\n");
		
		printf("Selecciona una opcion: ");
		fflush(stdin);
		scanf("%c", &opcion);
		fflush(stdin);
		printf("\n");	
		
		system("cls");
			
		switch(opcion){
			case 'A':
			case 'a':{
				// Limpiar el compilador-> dejarlo bonito
				//system("cls");
				printf("***REGISTRO***\n\n");
				printf("Numero de registro %d\n", nalumnos+1); //Para contabilizar el numero de alumnos registrados y poder guardarlos: nalumnos.
				
				printf("Numero de matricula: ");
				scanf("%d", &registro_alumno[nalumnos].matricula);
				printf("Nombre: ");
					fflush(stdin);
					gets(registro_alumno[nalumnos].nombre);
				printf("Apellidos: ");
					gets(registro_alumno[nalumnos].apellidos);
				printf("Correo electronico: ");
					gets(registro_alumno[nalumnos].correo);
				printf("Telefono de contacto: ");
					scanf("%d", &registro_alumno[nalumnos].telefono);
										
				fflush(stdin);
								
				do{
					printf("Contrasena: ");
					fflush(stdin);
					scanf("%s", registro_alumno[nalumnos].contrasena);
				
					printf("Repetir contrasena: ");
					fflush(stdin);
					scanf("%s",registro_alumno[nalumnos].contrasena2);
					
					if (strcmp(registro_alumno[nalumnos].contrasena, registro_alumno[nalumnos].contrasena2)!=0){
						printf("Las contrasenas no coinciden, intentelo de nuevo. \n");
					}
				}while(strcmp(registro_alumno[nalumnos].contrasena, registro_alumno[nalumnos].contrasena2)!=0);
				
				do{
				printf("\nAsignatura examen:\n");
				printf("QUIMICA: Q\n");
				printf("FISICA: F\n");
				printf("INFORMATICA: I\n");
				printf("ALGEBRA: A\n");
				printf("ECONOMIA: E\n");
				printf("\nSelecciona una:");
				fflush(stdin);
				scanf("%c", &registro_alumno[nalumnos].asignatura);
				
				if(registro_alumno[nalumnos].asignatura != 'Q' && registro_alumno[nalumnos].asignatura != 'F' &&registro_alumno[nalumnos].asignatura != 'I' &&registro_alumno[nalumnos].asignatura != 'A' &&registro_alumno[nalumnos].asignatura != 'E')
					printf("Asignatura incorrecta. Intentelo de nuevo.\n");
					
				}while(registro_alumno[nalumnos].asignatura != 'Q' && registro_alumno[nalumnos].asignatura != 'F' &&registro_alumno[nalumnos].asignatura != 'I' &&registro_alumno[nalumnos].asignatura != 'A' &&registro_alumno[nalumnos].asignatura != 'E');
					
				nalumnos++;
				
				//Abrimos fichero REGISTRO para escribir los datos
				puntero = fopen("REGISTRO.txt","w");
	
				if(puntero == NULL)
				{
					printf("No es posible abrir el fichero\n");
					return -1;
				}
				
				
				for (i=0; i<nalumnos; i++)
				{
					fprintf(puntero,"%d\t%c\t%s\t%s\t%s\t%d\t%s\n", 
					registro_alumno[i].matricula, 
					registro_alumno[i].asignatura, 
					registro_alumno[i].nombre, 
					registro_alumno[i].apellidos, 
					registro_alumno[i].correo,
					registro_alumno[i].telefono,
					registro_alumno[i].contrasena);
				}
				
				//Cerramos el fichero
				fclose(puntero);
				
				printf("\nREGISTRO COMPLETADO\n\n");
			break;
			}
				
			case 'B':
			case 'b':{
				
				printf("***INICIAR SESION***\n(Pulse '0' si desea volver al menu principal)\n\n");
				do{
					auxiliar_inicio=0;
					printf("Introduzca su numero de matricula: ");
					fflush(stdin);
					scanf("%d", &matricula_inicio);
					
					if (matricula_inicio == 0){
						printf("\nVolviendo a menu principal...\n");
						auxiliar_inicio = 1;
					}
				
					else{
						printf("\nContraseña: ");
						fflush(stdin);
						scanf("%s", contrasena_inicio);
						fflush(stdin);
						
						for (j=0;j<nalumnos;j++)
							{
								
								if (matricula_inicio == registro_alumno[j].matricula && (strcmp(contrasena_inicio, registro_alumno[j].contrasena) == 0) )
								{
									printf("\nBIENVENIDO %s %s\n\n", registro_alumno[j].nombre, registro_alumno[j].apellidos);
									auxiliar_inicio = 2;
									
								}
								else if(strcmp(contrasena_inicio, registro_alumno[j].correo) == 0)
									{
										printf("\n\nHola %s %s\n", registro_alumno[j].nombre, registro_alumno[j].apellidos);
										printf("Su contraseña es: %s\n\n",registro_alumno[j].contrasena);
										printf("Intentelo de nuevo: \n");
										auxiliar_inicio=3;
								}
							}
							
						if (auxiliar_inicio!=2 && auxiliar_inicio!=3)
							{
								system("cls");
								printf("\nUsuario o contraseña incorrectos. Intentelo de nuevo.\n\n");
								printf("¿Ha olvidado su contrasena? Introduzca su correo electronico en lugar de la contraseña y se la enviaremos.\n");
								printf("(Pulse '0' si desea volver al menu principal)\n\n");
							}
						}
					
					}while(auxiliar_inicio != 1 && auxiliar_inicio != 2);
				
					
					
				// Limpiar el compilador-> dejarlo bonito
				//system("cls");
			break;
			}
				
			case 'C':
			case 'c':{
				// Limpiar el compilador-> dejarlo bonito
				system("cls");
				printf("Saliendo del programa...\n");
				
				break;
			}
			default:
				printf("Opcion incorrecta.\n");
				// Limpiar el compilador-> dejarlo bonito
				system("cls");
		}
				
			
	}while(opcion!='D' && opcion!='d');

	return 0;
}
