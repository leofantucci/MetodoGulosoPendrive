#include <iostream>
#define TAMANHO 6

using namespace std;

void Troca(int v[], int A, int B){
	int aux;
	aux = v[A];
	v[A] = v[B];
	v[B] = aux;
}

void SelectionSort(int v[]){
	int min;
	for(int i = 0; i < TAMANHO; i++){
		min = i;	
		for(int j = i+1; j < TAMANHO; j++){
			if(v[min] > v[j]){
				min = j;	
			}
		}
		Troca(v, i, min);
	}
}

void Imprimir(int v[]){
	for(int i = 0; i < TAMANHO; i++){
		cout << v[i] << " ";
	}
}

int* Guloso_Pendrive(int a[], int kbmax){
	int tam_uti = 0;
	int ret[TAMANHO];
	SelectionSort(a);
	int i = 0;
	while(tam_uti <= kbmax && i <= TAMANHO){
		if(a[i] <= kbmax - tam_uti){
			ret[i] = a[i];
			tam_uti = tam_uti + a[i];
		}
		i++;
	}
	return ret;
}

int main(){
	int arquivos[TAMANHO] = {8, 24, 256, 1024, 16, 32};
	Imprimir(Guloso_Pendrive(arquivos, 1359));
}
