#include <wchar.h>
#include <locale.h>

struct fecha
{
	int dia;
	int mes;
	int anio;
};

struct usuarios
{
	char usuario[10];
	char contrasenia[10];
	char apeNom[60];
};

struct veterinario
{
	char apeNom[60];
	int matricula;
	int dni;
	char telefono[25];
};

struct mascota
{
	char apeNom[60];
	char Domicilio[60];
	int dniDuenio;
	char Localidad[60];
	fecha fecNac;
	float Peso;
	char Telefono[25];
	
};

struct turnos
{
	int matricula;
	fecha dniDuenio;
	char DetalleDeAtencion[380] ;
};
	
int opcion=0, LeaveProgram=0, repeticiones=0, errores=0;

void menu(int modo);
int confirmo(int display);

void sesion(int tipo);

void menu(int modo)
{
	bool confirmar=0;
	do
	{
		system("cls");
		if (modo==1)
		{
			system("color 0a");
			//printf("\n\n\n");
			printf("\n\tPrimer modulo: Consultorio veterinario");
			printf("\n\t====================================================");
			printf("\n\t 1.- Iniciar Sesion. ");
			printf("\n\t 2.- Visualizar Lista de Espera de Turnos (informe). ");
			printf("\n\t 3.- Registrar Evolucion de la Mascota. ");
   			printf("\n\t 4.- Cerrar la aplicacion. ");
		}
		else if (modo==2)
		{
			
			system("color 0b");
		    //printf("\n\n\n");
			printf("\n\tSegundo modulo: Asistente");
			printf("\n\t====================================================");
			printf("\n\t 1.- Iniciar Sesion  ");
			printf("\n\t 2.- Registrar Mascota  ");
			printf("\n\t 3.- Registrar Turno ");
		    printf("\n\t 4.- Listado de Atenciones por Veterinario y Fecha ");
		 	printf("\n\t 5.- Cerrar la aplicacion. ");
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
				if (modo==1) sesion(1);
				else if (modo==2) sesion(2);
				else if (modo==3) sesion(3);												
			}
		}
		else if (opcion==2)
		{
			if (confirmo(2)==1)
			{
				if (modo==1);// cargar();
				else if (modo==2);// cargar();
				else if (modo==3) sesion(4);	
			}
		}
		else if (opcion==3)
		{
			if (confirmo(3)==1)
			{
				if (modo==1);// cargar();
				else if (modo==2);// cargar();
				else if (modo==3);// cargar();
			}
		}
		else if (opcion==4)
		{
			if (confirmo(4)==1)
			{
				if (modo==1) LeaveProgram=1;
				else if (modo==2);// cargar();
				else if (modo==3);// cargar();
			}
		}
		else if (opcion==5)
		{
			if (modo==1) {printf("\n\tHas ingresado una opcion no valida..."); system("pause");}
			else if (confirmo(5)==1)
			{
				if (modo==2) LeaveProgram=1;
				else if (modo==3) LeaveProgram=1;
			}
		}
		
		else {printf("\n\tHas ingresado una opcion no valida"); system("pause");}
		
		if (opcion==0)
		{
			if (confirmo(5)==0) opcion=0;
			else printf("\n\tHasta la proxima!!!");
		};
	} while (LeaveProgram==0);
}

int confirmo(int display)
{
	int yesno;
	printf ("\n\tSeleccionaste la opcion '%i', esta seguro de su eleccion?",display);
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

void sesion(int tipo)
{
	char busqueda[11];
	do
	{
		int logreg;
		system("cls");
		if (tipo==1 or tipo==2) //Iniciar sesion
		{
			do
			{
				errores=1;
				printf("Nombre de usuario del veterinario: ");
				gets(busqueda);
				//rewind(FMascotas);
				//rewind(FTurnos);
				//rewind(FUsuarios);
				rewind(FVeterinarios);
				while(!feof(FVeterinarios))
				{
					if (!feof(archivoA))
					{
						fprintf(archivoC,textoA);
						fgets(textoA,80,archivoA);
					};
				}
			} while (errores==1)
		}
		else if (tipo==3 or tipo==4)
		{
			do
			{
				errores=1;
				printf("Nombre de usuario del veterinario");
				gets(busqueda);
				rewind(FVeterinarios);
				while(!feof(FVeterinarios))
				{
					if ()
					{
						char apeNom[60];
						int matricula;
						int dni;
						char telefono[25]
					};
				}
			} while (errores==1)
		}
	}
}
