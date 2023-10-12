#include <iostream>
using namespace std;

struct No {
	int data;
	No *next;
};

struct NoStr {
	string data;
	NoStr *next;
};

struct itemPilhaF{
	int data;
	bool ocupado;
};

void push(No *&topo, int data){
	No *novoNo = new No;
	novoNo -> data = data;
	novoNo -> next = topo;
	topo = novoNo;
}

void pushStr(NoStr *&topo, char data){
	NoStr *novoNo = new NoStr;
	novoNo -> data = data;
	novoNo -> next = topo;
	topo = novoNo;
}

bool isFullF(itemPilhaF pilha[], int tamanho){
	return pilha[tamanho-1].ocupado;
}

void pushF(itemPilhaF pilha[], int tamanho, int valor){
	if(isFullF(pilha, tamanho)){
		cout << "acao impossivel, pilha cheia" << endl;
		return;
	}
	itemPilhaF novoItem;
	novoItem.data = valor;
	novoItem.ocupado = true;
	for(int i = tamanho - 1; i>0; i--){
		pilha[i] = pilha[i-1];
	}
	pilha[0] = novoItem;
}

void popF(itemPilhaF pilha[], int tamanho){
	if(pilha[0].ocupado){
		for(int i = 0; i < tamanho -1; i++){
			pilha[i] = pilha[i+1];
		}
		itemPilhaF itemDefault;
		itemDefault.data = 0;
		itemDefault.ocupado = false;
		pilha[tamanho-1] = itemDefault;
		return;
	}
	cout << "acao impossivel, pilha vazia" << endl;
}

void topF(itemPilhaF pilha[]){
	if(!pilha[0].ocupado){
		cout << "pilha vazia" << endl;
		return;
	}
	cout << "topo: " << pilha[0].data << endl;
}

void top(No *&topo){
	if(topo == NULL){
		cout << "pilha vazia" << endl;
		return;
	}
	cout << "topo: " << topo -> data;
}

string topStr(NoStr *&topo){
	if(topo == NULL){
		cout << "pilha vazia" << endl;
		return "";
	}
	return topo -> data;
}

void exibirPilha(No *&topo){
	cout << "[ ";
	No *atual = topo;
	while(atual != NULL){
		cout << atual -> data << " ";
		atual = atual -> next;
	}
	cout << "]" << endl;
}

void exibirPilhaF(itemPilhaF pilha[], int tamanho){
	cout << "[ ";
	for(int i=0; i < tamanho; i++){
		if(pilha[i].ocupado){
			cout << pilha[i].data << " ";
		}
	}
	cout << "]" << endl;
}

int size(No *&topo){
	int count = 0;
	No *atual = topo;
	while(atual != NULL){
		count ++;
		atual = atual -> next;
	}
	return count;
}

void delMeio(No *&topo){
	if(topo == NULL){
		cout << "pilha vazia" << endl;
		return;
	}
	int meio = size(topo)/2;
	int count = 0;
	No *atual = topo;
	No *anterior = NULL;
	while(count < meio){
		count ++;
		anterior = atual;
		atual = atual -> next;
	}
	anterior -> next = atual -> next;
	delete atual;
}

void reverterPilha(No *&topo, int contador = 0, No *novoTopo = NULL){
	contador ++;
	if(size(topo)>1){
		No *atual = topo;
		No *anterior = NULL;
		while(atual -> next != NULL){
			anterior = atual;
			atual = atual -> next;
		}
		atual -> next = anterior;
		anterior -> next = NULL;
		if(contador == 1){
			novoTopo = atual;
		}
		reverterPilha(topo, contador, novoTopo);
	}else{
		topo = novoTopo;
	}
}

string reverterString(string texto){
	NoStr *palavra = new NoStr;
	palavra = NULL;
	for(int i = 0; i < texto.size(); i++){
		pushStr(palavra, texto[i]);
	}
	string reverso = topStr(palavra);
	while(palavra -> next != NULL){
		palavra = palavra -> next; 
		reverso += palavra -> data;
	}
	return reverso;
}

int main() {
	// criando pilha
	No *pilha = new No;
	pilha = NULL;
	push(pilha, 5);
	push(pilha, 6);
	push(pilha, 2);
	push(pilha, 5);
	push(pilha, 9);
	push(pilha, 23);
	push(pilha, -5);
	// exibindo
	exibirPilha(pilha);
	// deletando o do meio
	delMeio(pilha);
	exibirPilha(pilha);
	// revertendo
	reverterPilha(pilha);
	exibirPilha(pilha);	
	string texto;
	cout << "palavra que deseja reverter = ";
	cin >> texto;
	cout << "reverso: " << reverterString(texto) << endl;
	
	//conversor de boolean
	cout << boolalpha;
	// pilha tamanho fixo 4 vazia
	itemPilhaF pilhaF[4];
	itemPilhaF itemDefault;
	itemDefault.data = 0;
	itemDefault.ocupado = false;
	for(int i = 0; i<4; i++){
		pilhaF[i] = itemDefault;
	}
	//exibindo pilha vazia
	exibirPilhaF(pilhaF, 4);
	//isFull?
	cout << "pilha cheia: " << isFullF(pilhaF, 4) << endl;
	//push
	pushF(pilhaF, 4, 7);
	exibirPilhaF(pilhaF, 4);
	pushF(pilhaF, 4, 3);
	pushF(pilhaF, 4, -1);
	pushF(pilhaF, 4, 0);
	//isFull?
	cout << "pilha cheia: " << isFullF(pilhaF, 4) << endl;
	exibirPilhaF(pilhaF, 4);
	//push excedendo o limite
	cout << "tentativa de push acima do limite: ";
	pushF(pilhaF, 4, 5);
	//pop
	popF(pilhaF, 4);
	cout << "pop: ";
	exibirPilhaF(pilhaF, 4);
	
	//top
	topF(pilhaF);
	
	// mais pop
	popF(pilhaF, 4);
	cout << "pop: ";
	exibirPilhaF(pilhaF, 4);
	
	popF(pilhaF, 4);
	cout << "pop: ";
	exibirPilhaF(pilhaF, 4);
	
	popF(pilhaF, 4);
	cout << "pop: ";
	exibirPilhaF(pilhaF, 4);
	
	cout << "pop: ";
	popF(pilhaF, 4);
	
	//top
	cout << "top: ";
	topF(pilhaF);
	return 0;
}
