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
int funcion_numeroButaca(int posicion_asignatura);//Funcion para decir numero de butaca
void tableroAula(int nbutaca);//Funcion para imprimir matriz, faltan cosas

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
	char caracter;
	int butaca=0;
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
				printf("\tREGISTRO\n\n");
				printf("(Pulse '0' si desea volver al menu principal)\n\n");
				printf("Numero de registro %d\n", nalumnos+1); //Para contabilizar el numero de alumnos registrados y poder guardarlos: nalumnos.
				printf("Numero de matricula: ");
					scanf("%d", &registro_alumno[nalumnos].matricula);
					if (registro_alumno[nalumnos].matricula == 0){
						printf("\nVolviendo a menu principal...\n");
						Sleep(2000);
						break;
						}
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
				
				//COMPARACION DE CONTRASEÑA CON FUNCION (Sin terminar)!!			
				do{
					printf("Contrasena: ");
					fflush(stdin);
					scanf("%s", registro_alumno[nalumnos].contrasena);
				
					printf("Repita la contrasena: ");
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
				printf("\tINICIAR SESION\n\n");
				printf("(Pulse '0' si desea volver al menu principal)\n\n");
				
				do{
					auxiliar_inicio=0;
					printf("Introduzca su numero de matricula: ");
						fflush(stdin);
						scanf("%d", &matricula_inicio);
					
					if (matricula_inicio == 0){
						printf("\nVolviendo a menu principal...\n");
						auxiliar_inicio = 1;
					}else{
						printf("\nContrasena: ");
						fflush(stdin);
						scanf("%s", contrasena_inicio);
						fflush(stdin);
						//Comparacion de numero de matriculas y contraseñas:
						for (j=0;j<nalumnos;j++){
							if (matricula_inicio == registro_alumno[j].matricula && (strcmp(contrasena_inicio, registro_alumno[j].contrasena) == 0) ){
									printf("Sesion iniciada correctamente. Bienvenido %s %s\n\n", registro_alumno[j].nombre, registro_alumno[j].apellidos);
									auxiliar_inicio = 2;
									
									printf("\nEspere unos segundos, estamos imprimiendo su examen...\n");
									Sleep(3000);
									system("cls");
									
									switch(registro_alumno[j].asignatura){
										case 'Q':{
											punteroexamen=fopen("EXAMEN_QUIMICA.txt", "r");   
											butaca+=funcion_numeroButaca(-4);
											   
										break;}
										
										case 'F':{
											punteroexamen=fopen("EXAMEN_FISICA.txt", "r"); 
											butaca+=funcion_numeroButaca(-3);
										break;}
										
										case 'I':{
											punteroexamen=fopen("EXAMEN_INFORMATICA.txt", "r");
											butaca+=funcion_numeroButaca(-2); 
										break;}
										
										case 'A':{
											punteroexamen=fopen("EXAMEN_ALGEBRA.txt", "r");
											butaca+=funcion_numeroButaca(-1); 
										break;}
										
										case 'E':{
											punteroexamen=fopen("EXAMEN_ESTADISTICA.txt", "r");  
											butaca+=funcion_numeroButaca(0); 
										break;}
									}
									while((caracter=fgetc(punteroexamen))!=EOF)
											printf("%c", caracter); 
  											printf("\n\n\n"); 
  											fclose(punteroexamen);
  									
									system("PAUSE");
									system("cls");
  									printf("Su butaca es la numero %d\n\n",butaca);
  									printf("Puede ver su posicion en el siguiente tablero:\n");
  									tableroAula(butaca);
  									//funcion matriz aula
  									
  									system("PAUSE");
									
							}else if(strcmp(contrasena_inicio, registro_alumno[j].correo) == 0){
									printf("\nHola %s %s\n", registro_alumno[j].nombre, registro_alumno[j].apellidos);
									printf("Su contrasena es: %s\n",registro_alumno[j].contrasena);
									printf("\tInicie sesion de nuevo: \n");
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
	printf("\tMENU\n");
	printf("A. Registrarse.\n");
	printf("B. Iniciar sesion.\n");
	printf("C. Salir.\n");
	
	printf("Selecciona una opcion: ");
	fflush(stdin);
	scanf("%c", &opc);
	printf("\n");	
	
	system("cls");
	return opc;
}

//Funcion 2: Eleccion de asignatura
char menuAsignaturas(){
	char asig;
	printf("\nAsignatura examen:\n");
	printf("   -Quimica: Q\n");
	printf("   -Fisica: F\n");
	printf("   -Informatica: I\n");
	printf("   -Algebra: A\n");
	printf("   -Economia: E\n");
	printf("\n\nSeleccione la asignatura de la que se va a examinar:");
	fflush(stdin);
	scanf("%c", &asig);
	
	return asig;
}

//No funciona bien
int funcion_numeroButaca(int posicion_asignatura){
	posicion_asignatura+=5;
	return posicion_asignatura;
}			
//Funciona bien pero como depende de la anterior lo hace mal										      
void tableroAula(int nbutaca){
	int aula[8][13];
	int ii, jj, numero=1; 
	for(ii = 0; ii < 8; ii++) { 
		for(jj = 0; jj < 13; jj++){
			aula[ii][jj]=numero;
			numero++;}
		}
		
	for(ii = 0; ii < 8; ii++) { 
		for(jj = 0; jj < 13; jj++){
		
			if(nbutaca==aula[ii][jj])
				printf("[%d]",nbutaca);
			else	
				printf("[ ]");  
			}
			printf("\n"); 
		}
}										
	
