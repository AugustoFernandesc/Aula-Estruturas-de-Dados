#include <iostream>
#include <string>

using namespace std;

class Estudante {
private:
    string idade;
    string nome;
    int matricula;

public:
    Estudante(string i, string n, int m) {
        idade = i;
        nome = n;
        matricula = m;
    }

    string getNome() {
        return nome;
    }

    string getIdade(){
        return idade;
    }

    string getMatricula(){
        return matricula;
    }
};

int main() {
    
    int 
    Estudante e = new Estudante("Augusto", "19", 2349);
    
    cout << e.getNome() << endl << e.getIdade() << endl << e.getMatricula();

    return 0;
}
