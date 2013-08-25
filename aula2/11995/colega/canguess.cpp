#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

#define INIT -1
#define S 1
#define Q 2
#define P 3
#define SQ 12
#define SP 13
#define QP 23
#define SQP 123
#define IMP 0

int n;

stack<int> valorespilha;
stack<int> saidaspilha;
int* valores;
int* saidas;

int queue(int ins, int outs){

	int i = 0;

	for(int j = 0; saidas[j] != -1; ++j) {
		if(saidas[j] != valores[i++])
			return 0;
	}

	return 1;

}


int fstack(int ins, int outs){

	int i = ins;

	while(saidaspilha.size() > 0) {
		if(saidaspilha.top() != valorespilha.top())
			return 0;
		valorespilha.pop();
		saidaspilha.pop();
	}

	return 1;

}



int retira_maior(int** valores, int n) {


	int* val = *valores;

	//encontra maior

	int maior = -1;

	for(int i=0; val[i] != -1; i++) {
		if(val[i] > maior)
			maior = val[i];
	}


	//retira maior

	int i = 0;

	for(i=0; val[i] != maior; i++);

	for(int k = i; val[k] != -1; k++) {
		val[k] = val[k+1];
	}

	//retorna maior

	return maior;

}


int pqueue(int max, int ins, int outs){

	int* copyvalores;

	copyvalores = (int*)malloc(max*sizeof(int));

	for(int i = 0; i<max; ++i){
		copyvalores[i] = valores[i];
	}


	for(int j = 0; saidas[j] != -1; ++j) {
		if(saidas[j] != retira_maior(&copyvalores, max)) {
			free(copyvalores);
			return 0;
		}
	}


	free(copyvalores);
	return 1;

}


int main()
{
	while (cin >> n) {

		int state = INIT;
		string saida = "error";

		valores = (int*)malloc(n*sizeof(int));
		saidas = (int*)malloc(n*sizeof(int));

		for(int i = 0; i<n; ++i) {
			valores[i] = -1;
			saidas[i] = -1;
		}

		int i = 0, j = 0;
		int lines = n;

		while(lines--) {

			int tipo = -1, x = -1;

			cin >> tipo >> x;

			if(tipo == 1) {
				valores[i++] = x;
				valorespilha.push(x);
			}
			else if(tipo == 2) {
				saidas[j++] = x;
				saidaspilha.push(x);


				if(queue(i, j) && fstack(i, j) && pqueue(n, i, j)) {

					//cout << SQP << endl;

					if(state == INIT) state = SQP;
					else if(state != SQP) state = IMP;	
				}


				if(queue(i, j) && fstack(i, j)) {

					//cout << SQ << endl;

					if(state == INIT || state == SQ) state = SQ;
					else if(state == SQP) state = SQ;
					else if(state != SQ) state = IMP;
				}

				else if(queue(i, j) && pqueue(n, i, j)) {

					//cout << QP << endl;

					if(state == INIT || state == QP) state = QP;
					else if(state == SQP) state = QP;
					else if(state != QP) state = IMP;	
				}

				else if(fstack(i, j) && pqueue(n, i, j)) {

					//cout << SP << endl;

					if(state == INIT || state == SP) state = SP;
					else if(state == SQP) state = SP;
					else state = IMP;
				}

				else if(fstack(i, j)) {

					//cout << S << endl;

					if(state == INIT || state == S) state = S;
					else if(state == SQP) state = S;
					else if(state == SP) state = S;
					else if(state == SQ) state = S;
					else state = IMP;
				}

				else if(queue(i, j)) {

					//cout << Q << endl;


					if(state == INIT) state = Q;
					else if(state == SQP) state = Q;
					else if(state == SQ) state = Q;
					else if(state == QP) state = Q;
					else if(state != Q) state = IMP;
				}

				else if(pqueue(n, i, j)) {

					//cout << P << endl;

					if(state == INIT) state = P;
					else if(state == SQP) state = P;
					else if(state == SP) state = P;
					else if(state == QP) state = P;
					else if(state != P) state = IMP;
				}

				else state = IMP;
			
			}

		}

		if(state == SQ || state == SP || state == QP) saida = "not sure";
		else if(state == S) saida = "stack";
		else if(state == Q) saida = "queue";
		else if(state == P) saida = "priority queue";
		else saida = "impossible";
		

		cout << saida << endl;

		free(valores); free(saidas);

	}

	return 0;
}
