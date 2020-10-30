// DU1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <stdio.h>

int main()
{
	int rok = 1999;
	int mesic = 3;

	int pocatecniRok = 1995;
	int indexRok;
	int indexMesic;

	double temp[16][12] = { -1.1,-0.3,7.6,12.7,19.2,27.6,29.3,29.1,22.4,14.2,8.1,0.5,
		-2.1,-1.1,5.4,11.0,18.4,23.9,32.5,26.0,19.4,11.8,6.2,-0.5,
		-0.3,-1.3,9.9,13.7,20.3,22.0,28.4,28.1,20.2,14.6,7.3,0.4,
		1.1,-0.7,10.6,14.0,17.5,25.0,27.3,30.2,23.2,10.9,5.2,0.0,
		-8.6,-2.5,5.1,12.2,15.2,25.0,25.3,28.3,24.9, 9.2,1.5,0.2,
		-3.1,-0.3,4.6,12.3,14.0,28.6,29.0,32.5,22.0,12.3,9.1,4.3,
		-2.5,0.8,7.7,11.4,17.2,21.9,29.0,26.9,17.1,13.3,3.1,0.6,
		-1.0,-1.1,7.3,16.6,18.0,22.9,27.1,28.5,19.4,14.3,8.0,0.9,
		0.0,2.6,7.8,10.9,19.1,28.8,28.1,28.1,18.5,13.8,6.0,1.5,
		0.2,1.4,8.6,10.0,18.1,25.5,32.5,27.0,20.4,12.0,2.0,2.5,
		-0.7,-0.1,6.1,13.0,18.4,24.1,31.9,29.0,21.6,11.0,5.3,3.0,
		-5.4,3.3,11.6,12.8,16.9,23.8,28.7,29.0,23.4,13.7,3.8,4.1,
		-3.8,0.8,13.1,12.6,13.7,23.7,26.3,25.8,20.8,14.9,6.7,1.3,
		-1.2,0.0,8.6,15.9,15.6,26.6,29.2,26.6,20.8,15.1,4.1,-7.4,
		-2.5,2.5,8.8,11.7,19.8,27.3,33.3,25.4,22.9,14.1,4.1,2.9,
		-6.4,-6.3,2.5,13.8,19.1,27.6,28.1,23.2,20.1,12.0,5.1,0.8 };

	printf("Tabulka teplot:\n\n");
	printf("Mesic     01    02    03    04    05    06    07    08    09    10    11    12\n");
	printf("Rok   -------------------------------------------------------------------------\n");

	for (indexRok = 0; indexRok < 16; indexRok++)
	{
		printf("%d: ", pocatecniRok + indexRok);
		for (indexMesic = 0; indexMesic < 12; indexMesic++)
		{
			printf("%6.1lf", temp[indexRok][indexMesic]);
		}
		printf("\n");
	}

	//Výpis podle zadání int: rok, mesic
	printf("\nPrumerna teplota v mesici %d ", mesic);
	printf("roku %d ", rok);
	printf("byla %0.1lf C\370.", temp[rok - pocatecniRok][mesic - 1]);

	//Array pro prumer v roce avgRok
	double avgRok[16];
	for (indexRok = 0; indexRok < 16; indexRok++)
	{
		double teplota = 0;
		for (indexMesic = 0; indexMesic < 12; indexMesic++)
		{
			teplota = teplota + temp[indexRok][indexMesic];
		}
		avgRok[indexRok] = teplota / 12;
	}

	//Vypis avgRok
	printf("\n\n");
	printf("Rocni prumerne teploty v letech:\n");
	for (indexRok = 0; indexRok < 16; indexRok++)
	{
		printf("%d: ", pocatecniRok + indexRok);
		printf("%.1f C\370 \n", avgRok[indexRok]);
	}

	//Array pro prumer v roce avgMesic za vsechny roky
	double avgMesic[12];
	for (indexMesic = 0; indexMesic < 12; indexMesic++)
	{
		double teplota = 0;
		for (indexRok = 0; indexRok < 16; indexRok++)
		{
			teplota = teplota + temp[indexRok][indexMesic];
		}
		avgMesic[indexMesic] = teplota / 16;
	}

	//Vypis avgMesic
	printf("\n");
	printf("Prumerne teploty v jednotlivych mesicich (za obdobi: 1995 - 2010):\n");
	for (indexMesic = 0; indexMesic < 12; indexMesic++)
	{
		printf("%d: ", indexMesic + 1);
		printf("%.1lf C\370 \n", avgMesic[indexMesic]);
	}

	//Nejteplejsi mesice v letech maxRok
	double maxRok[16];
	for (indexRok = 0; indexRok < 16; indexRok++)
	{
		int maxMesic = 0;
		double max = 0;
		for (indexMesic = 0; indexMesic < 12; indexMesic++)
		{
			if (max < temp[indexRok][indexMesic]) {
				maxMesic = indexMesic + 1;
				max = temp[indexRok][indexMesic];
			}
		}
		maxRok[indexRok] = maxMesic;
	}

	//Vypis maxRok
	printf("\n");
	printf("Nejteplejsi mesice v letech:\n");
	for (indexRok = 0; indexRok < 16; indexRok++)
	{
		printf("%d:", pocatecniRok + indexRok);
		printf("%.0f \n", maxRok[indexRok]);
	}

	//Nejstudenejsi mesice v letech maxRok
	double minRok[16];
	for (indexRok = 0; indexRok < 16; indexRok++)
	{
		int minMesic = 0;
		double min = 0;
		for (indexMesic = 0; indexMesic < 12; indexMesic++)
		{
			if (min > temp[indexRok][indexMesic]) {
				minMesic = indexMesic + 1;
				min = temp[indexRok][indexMesic];
			}
		}
		minRok[indexRok] = minMesic;
	}

	//Vypis min
	printf("\n");
	printf("Nejstudenejsi mesice v letech:\n");
	for (indexRok = 0; indexRok < 16; indexRok++)
	{
		printf("%d:", pocatecniRok + indexRok);
		printf("%.0f \n", minRok[indexRok]);
	}

	return 0;
}