#include <iostream>
#define TAMANHO 6

using namespace std;

struct Arquivo{
	int tam;
	int utilizado;
	int id;
};

void Troca(Arquivo v[], int A, int B){
	int aux;
	aux = v[A].tam;
	v[A].tam = v[B].tam;
	v[B].tam = aux;
}

void SelectionSort(Arquivo v[]){
	int min;
	for(int i = 0; i < TAMANHO; i++){
		min = i;	
		for(int j = i+1; j < TAMANHO; j++){
			if(v[min].tam > v[j].tam){
				min = j;	
			}
		}
		Troca(v, i, min);
	}
}

void Imprimir(Arquivo v[]){
	for(int i = 0; i < TAMANHO; i++){
		if(v[i].utilizado == 1){
			cout << "ID do arquivo: " << v[i].id << " - ";
			cout << "Tamanho: " << v[i].tam << endl;	
		}
	}
}

void InicializarArquivo(Arquivo a[]){
	for(int i = 0; i < TAMANHO; i++){
		a[i].utilizado = 0;
	}
}

void Guloso_Pendrive(Arquivo a[], int kbmax){
	int tam_uti = 0;
	InicializarArquivo(a);
	SelectionSort(a);
	int i = 0;
	while(tam_uti <= kbmax && i <= TAMANHO){
		if(a[i].tam <= kbmax - tam_uti){
			tam_uti = tam_uti + a[i].tam;
			a[i].utilizado = 1;
		}
		i++;
	}
}

int main(){
	Arquivo arquivos[TAMANHO];
	arquivos[0].tam = 2;
	arquivos[0].id = 0;
	arquivos[1].tam = 10;
	arquivos[1].id = 1;
	arquivos[2].tam = 10;
	arquivos[2].id = 2;
	arquivos[3].tam = 10;
	arquivos[3].id = 3;
	arquivos[4].tam = 10;
	arquivos[4].id = 4;
	arquivos[5].tam = 10;
	arquivos[5].id = 5;

	Guloso_Pendrive(arquivos, 48);
	Imprimir(arquivos);
}