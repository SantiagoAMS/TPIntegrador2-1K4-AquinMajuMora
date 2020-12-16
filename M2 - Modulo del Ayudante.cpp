#include "Estructurador.h"

// Desde aquí se hace ingreso de las mascotas, y la registración de los turnos
// obtener un informe de las mascotas atendidos en determinada fecha por un determinado veterinario

int sesion(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void FUNCturnos(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void FUNCmascotas(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);
void atenciones(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios);

int numerito=0, logeado=0, reintentar=0;
//-1 = reintentar en el item 1
// 0 = uso deslogeado
// 1 = reintentar en el item 1
// 2 = salir logeado del item 1
main ()
{
	FILE *FMascotas, *FTurnos, *FUsuarios, *FVeterinarios;
	setlocale(LC_ALL, "");
	FMascotas=fopen("Mascotas.dat","r+b");
	FTurnos=fopen("Turnos.dat","r+b");
	FUsuarios=fopen("Usuarios.dat","r+b");
	FVeterinarios=fopen("Veterinarios.dat","r+b");
	do
	{
		opcion = menu(2);
		if (opcion==1);//Iniciar sesion
		else if (opcion==2);//Registrar mascota
		else if (opcion==3);//registrar turno
		else if (opcion==4);//listado de atenciones por veterinario y fecha
		
	} while (opcion!=5);
	
	do
	{
		if (numerito==2 or logeado==1)//SI la sesion esta iniciada
		{
			menu(5);
			
			if (opcion==1) numerito = sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);
			else if (opcion==2); //
			else if (opcion==3); //
			else if (opcion==4); //
		}
		else if (numerito==1)//MARCADO para reinicio
		{
			numerito=sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);
		}
		else if (numerito==0)//SESION NO INICIADA
		{
			opcion = menu(2);
			
			if (opcion==1)numerito=sesion(FMascotas, FTurnos, FUsuarios, FVeterinarios);
			else if (opcion==2 or opcion==3 or opcion==4)
			{
				printf("\n\n\n\tTienes que iniciar sesion para utilizar esta funcion...\n\n\t");
				system("pause");
			}
		}
	} while (opcion!=5);
	fclose(FMascotas);
	fclose(FTurnos);
	fclose(FVeterinarios);
	fclose(FUsuarios);
}

int sesion(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	veterinario regVete;
	personal regPers;
	mascota regMasc;
	turnos regTurn;
	int logreg, errorA=0, errores=0, encontrado=0, confirmo=0;
	char busquedaUSU[11], busquedaCON[61];
	system("cls");
	if (logeado==0)
	{
		do
		{
			errores=1;
			encontrado=0;
			printf("\n\tNombre de usuario del asistente: ");
			_flushall();
			gets(busquedaUSU);

			//rewind(FFUsuarios);
			rewind(FFVeterinarios);
			//fread(&lectura2, sizeof(personal), 1, FFUsuarios);
			fread(&lectura1, sizeof(veterinario), 1, FFVeterinarios);	
			while(!feof(FFVeterinarios)and encontrado==0)
			{
				if (strcmp(lectura1.usuario,busquedaUSU)==0/* or strcmp(lectura2.usuario,usuarioF)==0*/)
				{
					encontrado=1;
					errores=0;
					printf("\n\tUsuario '%s' encontrado con exito\n\n\t",busquedaUSU);
					system("pause");
				}
				else
				{
					fread(&lectura1, sizeof(veterinario), 1, FFVeterinarios);
					//fread(&lectura2, sizeof(personal), 1, FFUsuarios);
				}
			};
			if (encontrado==0)
			{
				system("cls");
				printf("\n\tNo se encontro al usuario '%s', vuelva a intentarlo...\n\n\t",busquedaUSU);
				system("pause");
				system("cls");
			}
	
		} while (errores!=0);
		
		do
		{
			errores=1;
			encontrado=0;
			system("cls");
			printf("\n\tUsuario: %s",busquedaUSU);
			printf("\n\tContraseña del asistente: ");
			_flushall();
			gets(busquedaCON);
			
			if (strcmp(lectura1.contrasenia,busquedaCON)!=0) //
			{
				printf("\n\tContraseña incorrecta\n\n\n\tDeseas ingresar otro usuario, o intentar con el mismo?\n\t(1=OTRO, 0=MISMO): ");
				do
				{
					scanf("%i",&numerito);
					if (numerito==1 or numerito==0) return numerito;
					else
					{
						printf("\n\n\tOpcion no valida, vuelve a ingresarla\n\n\tOpcion: ");
					};
				} while (numerito!=1 or numerito!=0);
			}
			else
			{
				system("cls");
				logeado=1;
				errores=0;
				printf("\n\tBienvenido %s!\n\n\t",lectura1.apeNom);
				system("pause");
				numerito=2;
			}
		} while (errores==1 and reintentar!=1);
	} 
	else if (logeado==1)
	{
		printf("\tDeseas cerrar sesion?(1=SI, 0=NO): ");
		scanf("%i",&confirmo);
		if (confirmo==1)
		{
			logeado=0;
			printf("\nSesion cerrada exitosamente. ¡Que tenga un buen dia!");
			numerito=0;
			system("pause");
		};
	};
}

void FUNCturnos(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	turnos tur;
	system("cls");	
	printf("---Registrar Turno---");
	printf("\n\nFecha del turno");
	
	do
	{
		errores=1;
		printf("\n\tAño: ");
		scanf("%i", &tur.fec.anio);
		if (tur.fec.anio>=1000 and tur.fec.anio<=9999) errores=0;
		else printf("Tienes que ingresar un año valido (1000-9999)...\n");
	} while (errores==1);
	
	do
	{
		errores=1;
		printf("\tMes: ");
		scanf("%i", &tur.fec.mes);
		if (tur.fec.mes>0 and tur.fec.mes<13) errores=0;
		else printf("Tienes que ingresar un mes valido (1-12)...\n");
	} while (errores==1);
	
	do
	{
		errores=1;
		printf("\tDia: ");
		scanf("%i", &tur.fec.dia);
		if (tur.fec.anio % 4 ==0)
		{
			if (tur.fec.mes==2)
			{
				if (tur.fec.dia>0 and tur.fec.dia<30) errores=0;
				else printf("Tienes que ingresar un dia valido para un año biciesto(1-29)...\n");
			}
			else if (tur.fec.dia>0 and tur.fec.dia<32) errores=0;
			else printf("Tienes que ingresar un dia valido (1-31)...\n");
		}
		else if (tur.fec.mes==2)
		{
			if (tur.fec.dia>0 and tur.fec.dia<29) errores=0;
			else printf("Tienes que ingresar un dia valido (1-28)...\n");
		}
		else if (tur.fec.dia>0 and tur.fec.dia<32) errores=0;
		else printf("Tienes que ingresar un dia valido (1-31)...\n");
		
	} while (errores==1);
	
	int conteo=0;
	do
	{
		system("cls");
		errores=0;
		conteo=0;
		
		printf("Ingrese el dni del dueño: ");
		_flushall();
		gets(tur.dniDuenio);
		
		for (int i=0;i<7;i++)
		{
			if (isdigit(tur.dniDuenio[i]))conteo++;
			else
			{
				i=10;
				errores=1;
			}
		};
		if (conteo!=7)
		{
			printf("\nEl numero tiene que tener 7 digitos (numeros)\n\n");
			errores=1;
			system("pause");
		}
		
	} while (errores==1);


	
	printf("\nMatricula de Veterinario:");scanf("%d",&tur.matricula);
	
	printf("\nDetalles de Atencion:");_flushall();gets(tur.DetalleDeAtencion);
	
	fwrite(&tur,sizeof(turnos),1,FFTurnos);
}

void FUNCmascotas(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	mascota masc;
	system("cls");
	puts("Datos de la Mascota: ");
	printf("\nNombre: ");_flushall();gets(masc.apeNom);
	printf("Domicilio: ");_flushall();gets(masc.Domicilio);
	//printf("DNI del Dueño:");scanf("%d",&masc.dniDuenio);
	int conteo=0;
	do
	{
		system("cls");
		errores=0;
		conteo=0;
		
		printf("DNI del dueño: ");
		_flushall();
		gets(masc.dniDuenio);
		
		for (int i=0;i<7;i++)
		{
			if (isdigit(masc.dniDuenio[i]))conteo++;
			else
			{
				i=10;
				errores=1;
			}
		};
		if (conteo!=7)
		{
			printf("\nEl numero tiene que tener 7 digitos (numeros)\n\n");
			errores=1;
			system("pause");
		}
		
	} while (errores==1);
	
	printf("Localidad: ");_flushall();gets(masc.Localidad);
	printf("Fecha de Nacimiento de la mascota: ");
	
	do
	{
		errores=1;
		printf("\n\tAño: ");
		scanf("%i", &masc.fecNac.anio);
		if (masc.fecNac.anio>=1000 and masc.fecNac.anio<=9999) errores=0;
		else printf("Tienes que ingresar un año valido (1000-9999)...\n");
	} while (errores==1);
	
	do
	{
		errores=1;
		printf("\tMes: ");
		scanf("%i", &masc.fecNac.mes);
		if (masc.fecNac.mes>0 and masc.fecNac.mes<13) errores=0;
		else printf("Tienes que ingresar un mes valido (1-12)...\n");
	} while (errores==1);
	
	do
	{
		errores=1;
		printf("\tDia: ");
		scanf("%i", &masc.fecNac.dia);
		if (masc.fecNac.anio % 4 ==0)
		{
			if (masc.fecNac.mes==2)
			{
				if (masc.fecNac.dia>0 and masc.fecNac.dia<30) errores=0;
				else printf("Tienes que ingresar un dia valido para un año biciesto(1-29)...\n");
			}
			else if (masc.fecNac.dia>0 and masc.fecNac.dia<32) errores=0;
			else printf("Tienes que ingresar un dia valido (1-31)...\n");
		}
		else if (masc.fecNac.mes==2)
		{
			if (masc.fecNac.dia>0 and masc.fecNac.dia<29) errores=0;
			else printf("Tienes que ingresar un dia valido (1-28)...\n");
		}
		else if (masc.fecNac.dia>0 and masc.fecNac.dia<32) errores=0;
		else printf("Tienes que ingresar un dia valido (1-31)...\n");
		
	} while (errores==1);
	/*printf("\nDia:");scanf("%d",&masc.fecNac.dia);
	printf("Mes:");scanf("%d",&masc.fecNac.mes);
	printf("Año:");scanf("%d",&masc.fecNac.anio);*/
	printf("Peso:");scanf("%f",&masc.Peso);
	//printf("Numero de telefono:");_flushall();gets(masc.Telefono);
	
	do
		{
			errores=0;
			conteo=0;
			printf("\nNumero de telefono del dueño: ");
			printf("\nEl formato solicitado es el siguiente: XXX XXX-XXXX (sin espacios o signos, solo numeros): ");
			printf("\n                              Ejemplo: 381 948-3852 (deberia escribirse como 3819483852)");
			printf("\n                              Ingreso: ");
			_flushall();
			gets(masc.Telefono);
			
			for (int i=0;i<10;i++)
			{
				if (isdigit(masc.Telefono[i]))conteo++;
				else
				{
					i=10;
					errores=1;
				}
			};
			if (conteo!=10)
			{
				printf("El numero tiene que tener 10 digitos (numeros)\n");
				errores=1;
				system("pause");
			}
		} while (errores==1);
		
	fwrite(&masc,sizeof(mascota),1,FFMascotas);
}
void atenciones(FILE *FFMascotas, FILE *FFTurnos, FILE *FFUsuarios, FILE *FFVeterinarios)
{
	
}
