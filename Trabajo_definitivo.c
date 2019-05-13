/*DISTRIBUCION DE ALUMNOS EN UN EXAMEN.
AUTORAS: Paula De Antonio Grondona							
		 Maria Dolores de la Fuente Fernandez							
		 Ines Reviejo vaillo
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define NUMERO_ALUMNOS_MAX 100

char menu(); //El return de la funcion es un char, y no es necesario ningun argumento
char menuAsignaturas(); //Funcion para la eleccion de la asignatura en el momento del registro.
void tableroAula(int nbutaca);//Funcion para imprimir matriz

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

int main(){
	system("color 71");
	//Variables registro
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
	FILE *punteroexamen;
	int butaca_Q=-4, butaca_F=-3, butaca_I=-2, butaca_A=-1, butaca_E=0;
	char caracter;
	
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
					nalumnos++;
								
	fclose(puntero);
	
	do{
		opcion= menu();
		switch(opcion){
			case 'A':
			case 'a':{
				printf("\t\tREGISTRO\n\n");
				printf("(Pulse '0' si desea volver al menu principal)\n\n");
				printf("\tNumero de registro %d\n", nalumnos+1); //Para contabilizar el numero de alumnos registrados y poder guardarlos: nalumnos.
				printf("\tNumero de matricula: ");
					scanf("%d", &registro_alumno[nalumnos].matricula);
					if (registro_alumno[nalumnos].matricula == 0){
						printf("\nVolviendo a menu principal...\n");
						Sleep(2000);
						break;
						}
				printf("\tNombre: ");
					fflush(stdin);
					gets(registro_alumno[nalumnos].nombre);
				printf("\tApellidos: ");
					gets(registro_alumno[nalumnos].apellidos);
				printf("\tCorreo electronico: ");
					gets(registro_alumno[nalumnos].correo);
				printf("\tTelefono de contacto: ");
					scanf("%d", &registro_alumno[nalumnos].telefono);
										
				fflush(stdin);
				
				//COMPARACION DE CONTRASEÑA CON FUNCION (Sin terminar)!!			
				do{
					printf("\tContrasena: ");
					fflush(stdin);
					scanf("%s", registro_alumno[nalumnos].contrasena);
				
					printf("\tRepita la contrasena: ");
					fflush(stdin);
					scanf("%s",registro_alumno[nalumnos].contrasena2);
					
					if (strcmp(registro_alumno[nalumnos].contrasena, registro_alumno[nalumnos].contrasena2)!=0){
						printf("\nLas contrasenas no coinciden, intentelo de nuevo.\n\n");
						Sleep(1500);}
						
				}while(strcmp(registro_alumno[nalumnos].contrasena, registro_alumno[nalumnos].contrasena2)!=0);
				
				do{
					registro_alumno[nalumnos].asignatura= menuAsignaturas();
					
					if(registro_alumno[nalumnos].asignatura != 'Q' && registro_alumno[nalumnos].asignatura != 'F' &&registro_alumno[nalumnos].asignatura != 'I' &&registro_alumno[nalumnos].asignatura != 'A' &&registro_alumno[nalumnos].asignatura != 'E')
						printf("\nAsignatura incorrecta. Intentelo de nuevo.\n");
						Sleep(1500);
				}while(registro_alumno[nalumnos].asignatura != 'Q' && registro_alumno[nalumnos].asignatura != 'F' &&registro_alumno[nalumnos].asignatura != 'I' &&registro_alumno[nalumnos].asignatura != 'A' &&registro_alumno[nalumnos].asignatura != 'E');
					
				nalumnos++;
				
				//Abrimos fichero REGISTRO para escribir los datos (los que ya habia y hemos leido + los nuevos)
				puntero = fopen("REGISTRO.txt","w");
	
				if(puntero == NULL){
					printf("No es posible abrir el fichero\n");
					return -1;
				}
				
				for (i=0; i<nalumnos; i++){
					fprintf(puntero,"%d\t%c\t%s\t%s\t%s\t%d\t%s\n", 
					registro_alumno[i].matricula, 
					registro_alumno[i].asignatura, 
					registro_alumno[i].nombre, 
					registro_alumno[i].apellidos, 
					registro_alumno[i].correo,
					registro_alumno[i].telefono,
					registro_alumno[i].contrasena);
				}
				fclose(puntero);
				
				printf("\nREGISTRO COMPLETADO\n\n");
				system("PAUSE");
			break;
			}
				
			case 'B':
			case 'b':{
				printf("\t\tINICIAR SESION\n\n");
				printf("(Pulse '0' si desea volver al menu principal)\n\n");
				
				do{
					auxiliar_inicio=0;
					printf("\tIntroduzca su numero de matricula: ");
						fflush(stdin);
						scanf("%d", &matricula_inicio);
					
					if (matricula_inicio == 0){
						printf("\nVolviendo a menu principal...\n");
						auxiliar_inicio = 1;
					}else{
						printf("\n\tContrasena: ");
						fflush(stdin);
						scanf("%s", contrasena_inicio);
						fflush(stdin);
						//Comparacion de numero de matriculas y contraseñas:
						for (j=0;j<nalumnos;j++){
							if (matricula_inicio == registro_alumno[j].matricula && (strcmp(contrasena_inicio, registro_alumno[j].contrasena) == 0) ){
									printf("\n\nSesion iniciada correctamente. Bienvenido %s %s\n\n", registro_alumno[j].nombre, registro_alumno[j].apellidos);
									auxiliar_inicio = 2;
									system("PAUSE");
									system("cls");
									
									switch(registro_alumno[j].asignatura){
										case 'Q':{
											punteroexamen=fopen("EXAMEN_QUIMICA.txt", "r");   
											butaca_Q+=5;
											tableroAula(butaca_Q);
											printf("\nSu butaca es la numero: %d\n\n",butaca_Q);
										break;}
										
										case 'F':{
											punteroexamen=fopen("EXAMEN_FISICA.txt", "r"); 
											butaca_F+=5;
											tableroAula(butaca_F);
											printf("\nSu butaca es la numero: %d\n\n",butaca_F);
										break;}
										
										case 'I':{
											punteroexamen=fopen("EXAMEN_INFORMATICA.txt", "r");
											butaca_I+=5; 
											tableroAula(butaca_I);
											printf("\nSu butaca es la numero: %d\n\n",butaca_I);
										break;}
										
										case 'A':{
											punteroexamen=fopen("EXAMEN_ALGEBRA.txt", "r");
											butaca_A+=5;
											tableroAula(butaca_A);
											printf("\nSu butaca es la numero: %d\n\n",butaca_A);
										break;}
										
										case 'E':{
											punteroexamen=fopen("EXAMEN_ESTADISTICA.txt", "r");  
											butaca_E+=5;
											tableroAula(butaca_E);
											printf("\nSu butaca es la numero: %d\n\n",butaca_E);
										break;}
									}
									system("PAUSE");
									system("cls");
  									printf("\nEspere unos segundos, estamos imprimiendo su examen...\n");
									Sleep(3000);
									system("cls");
									while((caracter=fgetc(punteroexamen))!=EOF)
											printf("%c", caracter); 
  											printf("\n\n\n"); 
  											fclose(punteroexamen);
  						
  									system("PAUSE");
									
							}else if(strcmp(contrasena_inicio, registro_alumno[j].correo) == 0){
									printf("\nHola %s %s\n", registro_alumno[j].nombre, registro_alumno[j].apellidos);
									printf("Su contrasena es: %s\n",registro_alumno[j].contrasena);
									printf("\n\n\tInicie sesion de nuevo: \n");
									auxiliar_inicio=3;
							}
						}
						if (auxiliar_inicio!=2 && auxiliar_inicio!=3)
							{
								system("cls");
								printf("\tUsuario o contrasena incorrectos. Intentelo de nuevo.\n\n");
								printf("Si olvido su contrasena, introduzca su correo electronico en lugar de la contraseña y se la proporcionaremos.\n");
								printf("(Pulse '0' si desea volver al menu principal)\n\n");
							}
					}
					
					}while(auxiliar_inicio != 1 && auxiliar_inicio != 2);
			break;
			}
				
			case 'C':
			case 'c':{
				printf("Saliendo del programa...\n");
				system("PAUSE");	
			break;
			}
			
			default:
				printf("Opcion incorrecta.\n");
				system("cls");
		}
				
			
	}while(opcion!='D' && opcion!='d');

	return 0;
}

//Funcion 1: Menu de opciones
char menu(){
	char opc;
	system("cls");
	printf("\t\tMENU\n\n");
	printf("\tA. Registrarse.\n");
	printf("\tB. Iniciar sesion.\n");
	printf("\tC. Salir.\n");
	
	printf("\n\tSelecciona una opcion: ");
	fflush(stdin);
	scanf("%c", &opc);
	printf("\n");	
	
	system("cls");
	return opc;
}

//Funcion 2: Eleccion de asignatura
char menuAsignaturas(){
	char asig;
	printf("\n\tAsignatura examen:\n");
	printf("\t   -Quimica: Q\n");
	printf("\t   -Fisica: F\n");
	printf("\t   -Informatica: I\n");
	printf("\t   -Algebra: A\n");
	printf("\t   -Economia: E\n");
	printf("\n\tSeleccione la asignatura de la que se va a examinar:");
	fflush(stdin);
	scanf("%c", &asig);
	
	return asig;
}
										      
void tableroAula(int butaca_asignatura){
	int aula[16][26];
	int i, j, numero=1; 
	
	printf("\n\n\t\t\t\t\t\tCOLOCACION EN EL AULA\n\n");
	for(i= 0; i < 16; i++) { 
		for(j = 0; j < 26; j++){
			aula[i][j]=numero;
			numero++;}
		}
		
	for(i= 0; i < 16; i++) { 
		printf("FILA %d:   ",i+1);
		for(j = 0; j < 26; j++){
		
			if(butaca_asignatura==aula[i][j])
				printf("[%d] ",butaca_asignatura);
			else	
				printf("[ ] ");  
			}
			printf("\n\n"); 
		}
	
}										
	
