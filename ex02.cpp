#include <iostream>
#include <cstdlib>

using namespace std;

class vectorx{ 
   private: 
        int* vetor;
        int tam;
    
   public:
        vectorx(int n){
            this->vetor = new int[n];
            this->tam = n;
        }
    
        ~vectorx(){
        cout << "Deletando..." << endl;
        delete[] vetor;
        tam = 0;
        }

        void preenche() {
        for (int i = 0; i < tam; i++){
            vetor[i] = rand() % 100;
        }       
    }
        void concatena(vectorx& vec1, vectorx& vec2){
        int tam1 = vec1.tam;
        int tam2 = vec2.tam;
        
        for (int i = 0; i < tam1; i++){
            vetor[i] = vec1.vetor[i];
        }

        for (int i = 0; i < tam2; i++){
            vetor[i+tam1] = vec2.vetor[i];
        }
    }
        void imprime() {
        for (int i = 0; i < tam; i++){
            cout << vetor[i] << " ";
        }   
        cout << endl;
    }
};


int main() {
    
    int tam1, tam2;
    
    cin >> tam1 >> tam2;
    
    // inicialiando gerador de n. aleat.
    srand(time(NULL));

    vectorx vec1(tam1);
    vectorx vec2(tam2);
    vectorx vec3(tam1+tam2);
    
    // preenchimento dos dados
    vec1.preenche();
    vec2.preenche();
    vec3.concatena(vec1, vec2);
    
    // imprimindo os vetores
    vec1.imprime();
    vec2.imprime();
    vec3.imprime();
    

    return 0;
}