#include "Estructurador.h"

FILE *FMascotas, *FTurnos, *FUsuarios, *FVeterinarios;

main ()
{
	setlocale(LC_ALL, "");
	FMascotas=fopen("Mascotas.dat","r+b");
	FTurnos=fopen("Turnos.dat","r+b");
	FUsuarios=fopen("Usuarios.dat","r+b");
	FVeterinarios=fopen("Veterinarios.dat","r+b");
	do
	{
		opcion = menu(2);
		if (opcion==1);//
		else if (opcion==2);//
		else if (opcion==3);//
		else if (opcion==4);//
	}
	while (opcion!=5);
}
