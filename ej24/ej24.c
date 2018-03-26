#include <stdio.h>
#include <stdlib.h>
#include "mensaje.h"
#include "error.h"
#include "data.h"
#include "types.h"

/*
 * Alumno: Santiago Lopez
 * Padron: 100566
 * */

/*Para el funcionamiento de este programa se asume que el año comienza
 * un lunes*/

int main (void)
{
	int dia, c;
	dia_semana_t dia_semana;
	
	puts (MSJ_INGRESO_DIA);
	if (scanf ("%d", &dia) != 1) {
		fprintf (stderr, "%s\n", ERROR_LECTURA);
		return EXIT_FAILURE;
	}
	while ((c = getchar ()) != '\n' && c != EOF)
		;
	if (dia < DIA_MIN || dia > DIA_MAX) {
		fprintf (stderr, "%s\n", ERROR_DIA);
		return EXIT_FAILURE;
	}
	
	dia_semana = dia % DIASXSEMANA;
	
	switch (dia_semana) {
		case LUNES:
			printf ("%s\n", MSJ_LUNES);
			break;
		case MARTES:
			printf ("%s\n", MSJ_MARTES);
			break;
		case MIERCOLES:
			printf ("%s\n", MSJ_MIERCOLES);
			break;
		case JUEVES:
			printf ("%s\n", MSJ_JUEVES);
			break;
		case VIERNES:
			printf ("%s\n", MSJ_VIERNES);
			break;
		case SABADO:
			printf ("%s\n", MSJ_SABADO);
			break;
		case DOMINGO:
			printf ("%s\n", MSJ_DOMINGO);
			break;
		default:
			fprintf (stderr, "%s\n", ERROR_DIA);
			return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
