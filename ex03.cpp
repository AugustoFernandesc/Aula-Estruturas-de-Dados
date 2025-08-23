//desafio: redimensionar o vetor mais n por tamanho e sim por capacidade, no caso o vetor pode ter um tamanho 100, mais usar so 20 de capacicdade.
//desafio: tentar melhorar este codigo


#include <iostream>
#include <cstdlib>

using namespace std;

class VectorX{
    private:
            int tamanho;
            int* dados;

    
    public:
             VectorX(int tamanho){
                cout << "Construtor1..." << endl;
                this->tamanho = tamanho;
                this->dados = new int[tamanho];
            }
            VectorX(){
                cout << "Construtor2..." << endl;
                this->tamanho = 10;
                this->dados = new int[10];
            }
             VectorX(const VectorX& v){
                cout << "Construtor de copia..." << endl;
                this->tamanho = v.tamanho; 
                this->dados = new int[this->tamanho];
                 for(int i=0; i<this->tamanho; i++){
                   this->dados[i] = v.dados[i];
                }
            }
            void preencher(){
                for(int i=0; i<tamanho; i++){
                    dados[i] = random()%100;
                }
            }
            /*void imprimir(){
                 for(int i=0; i<tamanho; i++){
                    cout << dados[i] << " ";
                }
                    cout << endl;
            }*/
           friend ostream& operator<<(ostream& output, VectorX& v){
                 for(int i=0; i<v.tamanho; i++){
                    output << v.dados[i] << " ";
                }
                    return output;
           }
            int getTamanho(){
                return tamanho;
            }
            /*int& acessarPosicao(int posicao){
                if ((posicao >= 0) and (posicao < tamanho)){
                    return dados[posicao];
                }else{
                    cerr << "erro: posicao invalida!" << endl;
                    exit(EXIT_FAILURE);
                    return dados[0]; //NO FUTURO USAR TRATAMENTO DE EXEÇÃO
                }
            }*/
            int& operator[](int posicao){
                if ((posicao >= 0) and (posicao < tamanho)){
                    return dados[posicao];
                }else{
                    cerr << "erro: posicao invalida!" << endl;
                    exit(EXIT_FAILURE);
                    return dados[0];
                }
            }
             ~VectorX(){
                cout << "Destruindo..." << endl;
                delete[] dados;
            }
            

};



int main(){

        int tam{5};
        srand(time(NULL));
        
        VectorX v1(tam);
        VectorX v2;


        v1.preencher();
        //v1.imprimir();
        cout << v1 << endl;
        v2.preencher();
        //v2.imprimir();
        cout << v2 << endl;
        
        /*cout << v1.acessarPosicao(3) << endl;
        cout << v1.acessarPosicao(8) << endl;
        v1.acessarPosicao(2) = 1000000;
        cout << v1.acessarPosicao(2) << endl;
        v1.imprimir();*/
        cout << v1.getTamanho() << endl;
        cout << v1[3] << endl;
        cout << v1[4] << endl;
        v1[2] = 551010;
        cout << v1 << endl;
    


    return 0;
}