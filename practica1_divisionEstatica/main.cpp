
#include "multiplicacionMatrices.h"
#include "debug_time.h"

int main(int argc,  char** argv){
	DEBUG_TIME_INIT;
	DEBUG_TIME_START;
	int lado = 0;
	int numeroThreads = 0;
	if(argc > 1){
			lado = atoi(argv[1]);
		}
		else{
			printf("Error en los parametros");
		}

	if(argc > 2){
			numeroThreads = atoi(argv[2]);
		}
		else{
			printf("Error en los parametros");
		}
	//generarMatrizCuadrada(lado, "matriz1");
	//generarMatrizIdentidad(lado, "matriz2");


	float** matriz1 = leerMatriz("matriz1", false);
	float** matriz2 = leerMatriz("matriz2", true);

	float** resultado;
	{
			DEBUG_TIME_INIT;
			DEBUG_TIME_START;
			resultado = multiplicarMatricesParalelo(lado,  matriz1, matriz2, numeroThreads);
			DEBUG_TIME_END;
			DEBUG_PRINT_FINALTIME("Tiempo multiplicar: ")
	}
	pasarMatrizFichero(lado, "matrizResultado", resultado);

	//imprimirMatriz("matrizResultado");
	DEBUG_TIME_END;
	DEBUG_PRINT_FINALTIME("Tiempo final: ")

}