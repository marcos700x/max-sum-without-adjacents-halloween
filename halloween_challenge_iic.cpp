#include <iostream>
#include <vector>
using namespace std;

int calcularDulcesMaximos(vector<int>& dulcesPorCasa) {
	int numeroDeCasas = dulcesPorCasa.size(); // Obtenemos el número total de casas.

	if (numeroDeCasas == 0) return 0; // Si no hay casas, no se pueden recoger dulces.
	if (numeroDeCasas == 1) return dulcesPorCasa[0]; // Si solo hay una casa, el máximo de dulces es de esa casa.
	if (numeroDeCasas == 2) return max(dulcesPorCasa[0], dulcesPorCasa[1]); // Si hay dos casas, regresamos el valor máximo de esas dos.

	vector<int> maximaSumaDulcesActual(numeroDeCasas);

	maximaSumaDulcesActual[0] = dulcesPorCasa[0]; // Solo se puede tomar de la primera casa.
	maximaSumaDulcesActual[1] = max(dulcesPorCasa[0], dulcesPorCasa[1]); // Tomamos el máximo de las dos primeras casas.

	for (int i = 2; i < numeroDeCasas; i++) {

		maximaSumaDulcesActual[i] = max((maximaSumaDulcesActual[i - 1]), (maximaSumaDulcesActual[i - 2] + dulcesPorCasa[i]));
		//(maximaSumaDulcesActual[i - 1]) = No tomar dulces de la casa actual
		//maximaSumaDulcesActual[i - 2] + dulcesPorCasa[i] = Tomar dulces de la casa actual y sumar la maxima suma hasta la casa, dos lugares atras
	}

	// Devolvemos la máxima suma de dulces posible hasta la última casa.
	return maximaSumaDulcesActual[numeroDeCasas - 1];
}

int main()
{
	int T, N; //T = numero de casos de prueba, N = numero de casas

	cout << "Ingresa la cantidad de casos de prueba (T): " << endl;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cout << "Ingresa el numero de casas (N): ";
		cin >> N;

		vector<int> dulces(N); //Vector del tamaño del numero de casas, donde se guardara la cantidad de dulces por casa

		cout << "Ingresa la cantidad de dulces que puede dar cada casa:" << endl;
		cout << "Ejemplo: 1 2 3 ... N (separados por espacios)" << endl;
		for (int i = 0; i < N; i++) {
			cin >> dulces[i];
		}
		//Imprimimos la cantidad maxima de dulces que puede obtener
		cout << endl << calcularDulcesMaximos(dulces) << endl;
	}


	return 0;
}
