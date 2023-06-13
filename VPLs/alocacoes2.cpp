// Copyright [2022] MICAEL PRESOTTO
#include <string>

class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor
    std::string devolveNome() {
        return nome;
    }
    int devolveMatricula() {
        return matricula;
    }
    void escreveNome(std::string nome_) {
        nome = nome_;
    }
    void escreveMatricula(int matricula_) {
        matricula = matricula_;
    }
 private:
    std::string nome;
    int matricula;
};
Aluno *turma_filtra(Aluno t[], int N, int menor_matr) {
    int cont = 0;
    int tamanho_tf = 0;
    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            cont++;
        }
    }
    Aluno *tf = new Aluno[cont];
    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            Aluno *a = new Aluno();
            a -> escreveNome(t[i].devolveNome());
            a -> escreveMatricula(t[i].devolveMatricula());
            tf[tamanho_tf++] = *a;
            delete a;
        }
    }

    return tf;
}
int *turma_conta(Aluno t[], int N) {
    int *c = new int[26]{0};
    for (int i = 0; i < N; i++) {
        char inicial = t[i].devolveNome()[0];
        int pos = inicial - 'A';
        c[pos]++;
    }
    return c;
}
/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/
