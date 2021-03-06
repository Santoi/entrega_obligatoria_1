#include <stdio.h>
#include <stdlib.h>
#include "./data.h"
#include "./mensaje.h"
#include "./error.h"

/*
 * Alumno: Santiago Lopez
 * Padron: 100566
 * */

int main (void)
{
	float monto_carga, km_recorr = 0, precioxlitro, rend, rend_promedio;
	float mejor_rend, peor_rend, km_total = 0, litro_total = 0, monto_total = 0;
	/* los valores de los totales se inicializan en 0 para que al sumar
	 * no se tomen por error los valores pre-guardados en memoria */
	int c;
	bool_t hay_datos = FALSO;
	/* variable para el chequeo de que haya datos para procesar */
	
	do {
		printf ("%s: ", MSJ_INGRESO_KM);
		if (scanf ("%f", &km_recorr) != 1) {
			fprintf (stderr, "%s: %s\n", ERROR, ERROR_DATO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar ()) != '\n' && c != EOF)
			;
		
		/* validación de que scanf lea lo que tenga que leer, y limpieza del buffer */
		if (km_recorr == NUMERO_TERMINANTE)
			break; /* si se ingresa en caracter terminante se sale del ciclo */
		
		if (km_recorr < 0) {
			fprintf (stderr, "%s: %s\n", ERROR, ERROR_DATO_INVALIDO);
			return EXIT_FAILURE;
		}
		/* aseguramiento de que los datos no sean inválidos */
		
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
		if (precioxlitro <= 0) {
			fprintf (stderr, "%s: %s\n", ERROR, ERROR_DATO_INVALIDO);
			return EXIT_FAILURE;
		}
		/* el precio por litro no puede ser 0 por la division a continuacion */
		
		/* se calcula la cantidad de litros de nafta cada una x cantidad de km
		 * recorridos */
		 
		rend = (monto_carga / precioxlitro) * CANTIDAD_KM / km_recorr;
		
		if (hay_datos == FALSO) {
			mejor_rend = rend;
			peor_rend = rend;
		/* si es el primer rendimiento calculado, se lo asigna al mejor y peor */
		}
		printf ("%s: %.2f\n\n", MSJ_RENDIMIENTO, rend);
		hay_datos = VERDADERO; /* ya hay datos para procesar */
		
		if (rend < mejor_rend)
			mejor_rend = rend;
			
		else if (rend > peor_rend)
			peor_rend = rend;
			
		km_total += km_recorr;
		litro_total += (monto_carga / precioxlitro);
		monto_total += monto_carga;
	}
	while (km_recorr != NUMERO_TERMINANTE);
	
	if (hay_datos == FALSO) 
		printf ("%s\n", MSJ_SIN_DATOS);
	
	else {
		rend_promedio = CANTIDAD_KM * litro_total / km_total;
		printf ("\n\n%s: %.4f\n", MSJ_RENDIMIENTO_PROMEDIO, rend_promedio);
		printf ("%s: %.2f\n", MSJ_MEJOR_RENDIMIENTO, mejor_rend);
		printf ("%s: %.2f\n", MSJ_PEOR_RENDIMIENTO, peor_rend);
		printf ("%s: %.2f\n", MSJ_KM_TOTAL, km_total);
		printf ("%s: %.2f\n", MSJ_COMBUSTIBLE_TOTAL, litro_total);
		printf ("%s: %.2f\n", MSJ_MONTO_TOTAL, monto_total);
	}
	
	return EXIT_SUCCESS;
}
