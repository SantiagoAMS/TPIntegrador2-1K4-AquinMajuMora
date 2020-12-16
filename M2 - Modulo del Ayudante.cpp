#include "Estructurador.h"

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
	}
	while (opcion!=5);
	fclose(FMascotas);
	fclose(FTurnos);
	fclose(FVeterinarios);
	fclose(FUsuarios);
}
