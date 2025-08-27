#include <iostream>

using namespace std;

class Noh{

        friend class Pilha;

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


class Pilha{
        
        private:
            Noh* topo;
            int tamanho;
        public:
            Pilha(){
                this->topo = NULL;
                this->tamanho = 0;
            }
            void empilha(int valor){
                cout <<"topo antes de empilhar: " << topo << endl;
                Noh* novo = new Noh(valor);
                novo->proximo = this->topo;
                this->topo = novo;
                this->tamanho++;
                cout <<"topo depois de empilhar: " << topo << endl;
                cout <<"proximo topo: " << topo->proximo << endl;
            }
            int desempilha(){
                int valor = topo->valor;
                Noh* temp = topo;
                topo = topo->proximo;
                delete temp;
                tamanho--;
                return valor;
            }
            void limpaPilha(){
                while(tamanho > 0){
                    desempilha();
                }
            }
            bool vazia(){
                return (tamanho == 0);
            }
            ~Pilha(){
                limpaPilha();
            }
            int getTamanho(){
                return tamanho;
            }
};


int main(){

    Pilha p1;

    int num;
    cin >> num;

    while(num >= 0){
        p1.empilha(num);
        cin >> num;
    }

    cout << "Tamanho: " << p1.getTamanho() << endl;
    cout << "Elementos:" << endl;

    while(!p1.vazia()){
        cout << p1.desempilha() << " " << endl;
    }


    return 0;
}