/*#include <iostream>

using namespace std;

class Noh{

        friend class Fila;

        private:
            int valor;
            Noh* proximo;
        public:
            Noh(int valor){
                this->valor = valor;
                this->proximo = NULL;
                cout << "noh criado: " << this << endl;
            }

};

class Fila{        
        private:
            Noh* primeiro;
            Noh* ultimo;
            int tamanho;
        public:
            Fila(){
                this->primeiro = NULL;
                this->ultimo = NULL;
                this->tamanho = 0;
            }
            void enfileira(int valor){
                cout <<"topo antes de enfileirar: " << ultimo << endl;
                Noh* novo = new Noh(valor);
                if(tamanho == 0){
                    primeiro = novo;
                }else{
                ultimo->proximo = novo;
                }
                this->ultimo = novo;
                this->tamanho++;
                cout <<"topo depois de enfileirar: " << ultimo << endl;
                cout <<"proximo topo: " << ultimo->proximo << endl;
            }
            int desenfileira(){
                int valor = primeiro->valor;
                Noh* temp = primeiro;
                primeiro = primeiro->proximo;
                delete temp;
                tamanho--;
                if(tamanho == 0){
                    ultimo = NULL;
                }
                return valor;
            }
            void limpaFila(){
                while(tamanho > 0){
                    desenfileira();
                }
            }
            bool vazia(){
                return (tamanho == 0);
            }
            ~Fila(){
                limpaFila();
            }
            int getTamanho(){
                return tamanho;
            }
};

int main(){

    Fila f1;

    int num;
    cin >> num;

    while(num >= 0){
        f1.enfileira(num);
        cin >> num;
    }

    cout << "Tamanho: " << f1.getTamanho() << endl;
    cout << "Elementos:" << endl;

    while(!f1.vazia()){
        cout << f1.desenfileira() << " " << endl;
    }


    return 0;
}*/


#include <iostream>

using namespace std;

class FilaCircular{        
        private:
            int inicio;
            int fim;
            int* dados;
            int capacidade;
            int tamanho;
        public:
            FilaCircular(int capacidade = 10){
                this->inicio = -1;
                this->fim = -1;
                this->capacidade = capacidade;
                this->dados = new int[capacidade];
                this->tamanho = 0;
            }
            void enfileira(int valor){
                if(tamanho <= capacidade){
                     fim++;
                     fim = fim % capacidade;
                     dados[fim] = valor;
                if(tamanho == 0){
                     inicio++;
                }
                    tamanho++;
                }else{
                     cerr << "Fila cheia" << endl;
                }
            }
            int desenfileira(){
                if(tamanho > 0){
                    int valor = dados[inicio];
                    tamanho--;
                    if(tamanho > 0){
                        inicio++;
                        inicio = inicio % capacidade;
                    }
                    else{
                        inicio = -1;
                        fim = -1;
                    }
                    return valor;  
                }else{
                    cerr << "Fila vazia" << endl;
                    return -1;
                }
            }
            bool vazia(){
                return (tamanho == 0);
            }
            ~FilaCircular(){
                delete[] dados;
            }
            int getTamanho(){
                return tamanho;
            }
            void depura(){
                cout << "inicio:" << inicio << endl;
                cout << "fim:" << fim << endl;
                cout << "tamanho:" << tamanho << endl;
                cout << "vetor de dados:";
                for(int i = -1; i<capacidade; i++){
                    cout << dados[i] << " ";
                }
                    cout << endl;
            }
};

int main(){

    FilaCircular f1(20);

    int num;
    cin >> num;

    for(int i=-1; i<5; i++){
        cin >> num;
        f1.enfileira(num);
    }

    cout << "Tamanho: " << f1.getTamanho() << endl;
    cout << "Elementos:" << endl;

    for(int i=-1; i<5; i++){
        cout << f1.desenfileira() << " " << endl;
    }
    f1.depura();

    return 0;
}