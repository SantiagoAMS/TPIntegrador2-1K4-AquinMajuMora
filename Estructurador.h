#include <wchar.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char mayusculas[27]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}, minusculas[27]={"abcdefghijklmnopqrstuvwxyz"}, simbolos[9]={"+-/*?¿!¡"};

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct personal
{
	char usuario[11];
	char contrasenia[33];
	char apeNom[61];
};

struct veterinario
{
	char usuario[11];
	char contrasenia[33];
	int catenciones;
	char apeNom[61];
	int matricula;
	char dni[9];
	char telefono[11];
	
};

struct mascota
{
	char apeNom[61];
	char Domicilio[61];
	char dniDuenio[9];
	char Localidad[61];
	fecha fecNac;
	float Peso;
	char Telefono[11];
	char atenciones[380];
	fecha ate;
	
};

struct turnos
{
	int matricula;
	fecha fec;
	char dniDuenio[9];
	char DetalleDeAtencion[381] ;
};

	veterinario regVete, lectura1;
	personal regPers, lectura2;
	mascota regMasc, lectura3;
	turnos regTurn, lectura4;

int opcion=0, LeaveProgram=0, repeticiones=0, errores=0;

int menu(int modo);
int confirmo(int display);

int menu(int modo)
{
	bool confirmar=0;
	int errores=0;
	char noIniciasteSesion[100]={"Tienes que iniciar sesion para utilizar esta funcion"};
	do
	{
		errores=0;
		system("cls");
		if (modo==1 or modo==4)
		{
			system("color 0a");
			//printf("\n\n\n");
			printf("\n\tPrimer modulo: Consultorio veterinario");
			printf("\n\t====================================================");
			if (modo==4) printf("\n\t 1.- Cerrar sesion. ");
			else printf("\n\t 1.- Iniciar Sesion. ");
			printf("\n\t 2.- Visualizar Lista de Espera de Turnos (informe). ");
			printf("\n\t 3.- Registrar Evolucion de la Mascota. ");
   			printf("\n\t 4.- Cerrar la aplicacion. ");
   			modo=1;
		}
		else if (modo==2 or modo==5)
		{
			
			system("color 0b");
		    //printf("\n\n\n");
			printf("\n\tSegundo modulo: Asistente");
			printf("\n\t====================================================");
			if (modo==5) printf("\n\t 1.- Cerrar Sesion  ");
			else printf("\n\t 1.- Iniciar Sesion  ");
			printf("\n\t 2.- Registrar Mascota  ");
			printf("\n\t 3.- Registrar Turno ");
		    printf("\n\t 4.- Listado de Atenciones por Veterinario y Fecha ");
		 	printf("\n\t 5.- Cerrar la aplicacion. ");
		 	modo=2;
		}
		else if (modo==3)
		{
			
			system("color 0c");
			//printf("\n\n\n");
			printf("\n\tTercer modulo: Administracion");                                                                                      
			printf("\n\t ========================="); 
			printf("\n\t 1.- Registrar Veterinario "); 
			printf("\n\t 2.- Registrar Usuario Asistente"); 
			printf("\n\t 3.- Atenciones por Veterinarios "); 
			printf("\n\t 4.- Ranking de Veterinarios por Atenciones "); 
			printf("\n\t 5.- Cerrar la aplicacion. "); 
		}
		printf("\n\n\tIngrese una opcion: ");
		scanf("%i",&opcion);
		
		if (opcion == 1)
		{
			if (confirmo(1)==1) 
			{
				/*if (modo==1) return 1//sesion(1);
				else if (modo==2) sesion(2);
				else if (modo==3) sesion(3);*/ return 1;												
			}
		}
		else if (opcion==2)
		{
			if (confirmo(2)==1)
			{
				/*if (modo==1);// cargar();
				else if (modo==2);// cargar();
				else if (modo==3) sesion(4);*/ return 2;	
			}
		}
		else if (opcion==3)
		{
			if (confirmo(3)==1)
			{/*
				if (modo==1);// cargar();
				else if (modo==2);// cargar();
				else if (modo==3);// cargar();*/ return 3;
			}
		}
		else if (opcion==4)
		{
			if (confirmo(4)==1)
			{
				/*if (modo==1) LeaveProgram=1;
				else if (modo==2);// cargar();
				else if (modo==3);// cargar();*/return 4;
			}
		}
		else if (opcion==5)
		{
			if (modo==1) {printf("\n\tHas ingresado una opcion no valida...\n\n\t"); errores=1; system("pause");}
			else if (confirmo(5)==1)
			{
				/*if (modo==2) LeaveProgram=1;
				else if (modo==3) LeaveProgram=1;*/return 5;
			}
		}
		
		else {printf("\n\tHas ingresado una opcion no valida...\n\n\t"); errores=1; system("pause");}
	} while (errores==1);
	return 0;
}

int confirmo(int display)
{
	int yesno;
	printf ("\n\tSeleccionaste la opcion '%i', estas seguro de tu eleccion?",display);
	printf ("\n\t(1=SI,0=NO): ");
	scanf("%i",&yesno);
	
	return yesno;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
tipo==1 -> Iniciar sesion - modulo veterinario
tipo==2 -> Iniciar sesion - modulo asistente
tipo==3 -> Registrar veterinario - modulo administracion
tipo==4 -> Registrar asistente - modulo administracion*/
