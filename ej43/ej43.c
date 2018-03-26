#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "mensaje.h"
#include "error.h"

/*
 * Alumno: Santiago Lopez
 * Padron: 100566
 * */

int main (void)
{
	float monto_carga, km_recorr = 0, precioxlitro, rend, rend_promedio;
	float mejor_rend = 1000, peor_rend = 0, km_total = 0, litro_total = 0, monto_total = 0;
	/*se le dan esos valores al mejor y peor rendimiento para que 
	 * haya algo con que comparar los primeros datos ingresados*/
	/*los valores de los totales se inicializan en 0 para que al sumar
	 * no se tomen por error los valores pre-guardados en memoria*/
	int c, hay_datos = 0;
	/*chequeo que haya datos para procesar*/
	
	while (1) {
		printf ("%s: ", MSJ_INGRESO_KM);
		if (scanf ("%f", &km_recorr) != 1) {
			fprintf (stderr, "%s: %s\n", ERROR, ERROR_DATO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar ()) != '\n' && c != EOF)
			;
		/*validación de que scanf lea lo que tenga que leer, y limpieza del buffer*/
		if (km_recorr == CARACTER_TERMINANTE)
			break; /*si se ingresa en caracter terminante se sale del ciclo*/
		
		if (km_recorr < 0) {
			fprintf (stderr, "%s: %s\n", ERROR, ERROR_DATO_INVALIDO);
			return EXIT_FAILURE;
		}
		/*aseguramiento de que los datos no sean inválidos*/
		
		printf ("%s: ", MSJ_INGRESO_MONTO);
		if (scanf ("%f", &monto_carga) != 1) {
			fprintf (stderr, "%s: %s\n", ERROR, ERROR_DATO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar ()) != '\n' && c != EOF)
			;
		if (monto_carga < 0) {
			fprintf (stderr, "%s: %s\n", ERROR, ERROR_DATO_INVALIDO);
			return EXIT_FAILURE;
		}
		
		printf ("%s: ", MSJ_INGRESO_PRECIOXLITRO);
		if (scanf ("%f", &precioxlitro) != 1) {
			fprintf (stderr, "%s: %s\n", ERROR, ERROR_DATO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar ()) != '\n' && c != EOF)
			;
		if (precioxlitro < 0) {
			fprintf (stderr, "%s: %s\n", ERROR, ERROR_DATO_INVALIDO);
			return EXIT_FAILURE;
		}
		/*Se calcula la cantidad de litros de nafta cada 100km
		 * recorridos*/
		 
		rend = (monto_carga / precioxlitro) * 100 / km_recorr;
		printf ("%s: %.2f\n\n", MSJ_RENDIMIENTO, rend);
		hay_datos = 1; /*ya hay datos para procesar*/
		
		if (mejor_rend > rend)
			mejor_rend = rend;
			
		if (peor_rend < rend)
			peor_rend = rend;
			
		km_total += km_recorr;
		litro_total += (monto_carga / precioxlitro);
		monto_total += monto_carga;
	}
	if (hay_datos == 0) 
		printf ("%s\n", MSJ_SIN_DATOS);
	
	else {
		rend_promedio = 100 * litro_total / km_total;
		printf ("\n\n%s: %.4f\n", MSJ_RENDIMIENTO_PROMEDIO, rend_promedio);
		printf ("%s: %.2f\n", MSJ_MEJOR_RENDIMIENTO, mejor_rend);
		printf ("%s: %.2f\n", MSJ_PEOR_RENDIMIENTO, peor_rend);
		printf ("%s: %.2f\n", MSJ_KM_TOTAL, km_total);
		printf ("%s: %.2f\n", MSJ_COMBUSTIBLE_TOTAL, litro_total);
		printf ("%s: %.2f\n", MSJ_MONTO_TOTAL, monto_total);
	}
	
	return EXIT_SUCCESS;
}
