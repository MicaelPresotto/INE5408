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


/*
(1) cria um vetor de 'Alunos' a partir de nomes e matriculas; exemplo:
vetor de nomes: ['Fulano', 'Beltrano', 'Ciclano']
vetor de matriculas: [1010, 2020, 3030]
vetor t alocado de saida: [{'Fulano',1010}, {'Beltrano',2020}, {'Ciclano':3030}]
*/

Aluno *turma(std::string nomes[], int matriculas[], int N) {
    Aluno *t = new Aluno[N];
    int i;
    for (i = 0; i < N; i++) {
        t[i].escreveNome(nomes[i]);
        t[i].escreveMatricula(matriculas[i]);
    }
    // ... COLOQUE SEU CÓDIGO AQUI ...

    return t;
}

/*
(2) cria um novo vetor contendo outros dois vetores de alunos (acrescenta vetor 2 apos o vetor 1); exemplo:
t1 de entrada: [{'Fulano',1010}, {'Beltrano',2020}];  N1 = 2
t2 de entrada: [{'Fulana',7070}, {'Beltrana',8080}, {'Cicrana',9090}];  N2 = 3
tu de saída: [{'Fulano',1010}, {'Beltrano',2020}, {'Fulana',7070}, {'Beltrana',8080}, {'Cicrana':9090}]
*/
Aluno *turmas_uniao(Aluno t1[], Aluno t2[], int N1, int N2) {
    Aluno *tu = new Aluno[N1+N2];
    for (int i = 0; i < N1; i++) {
        Aluno *a = new Aluno();
        a -> escreveNome(t1[i].devolveNome());
        a -> escreveMatricula(t1[i].devolveMatricula());
        tu[i] = *a;
        delete a;
    }
    for (int i = 0; i < N2; i++) {
        Aluno *a = new Aluno();
        a -> escreveNome(t2[i].devolveNome());
        a -> escreveMatricula(t2[i].devolveMatricula());
        tu[i+N1] = *a;
        delete a;
    }
    // ... COLOQUE SEU CÓDIGO AQUI ...

    return tu;
}

/*
(3) divide uma turma t existente em duas outras (os conteúdos dos ponteiros pt1 e pt2 serão as duas saídas; inicialmente são iguais a 'nullptr'), a primeira com k elementos e a segunda com o restante (N-k elementos); exemplo:
t de entrada: [{'Fulano',1010}, {'Beltrano',2020}, {'Fulana',7070}, {'Beltrana',8080}, {'Cicrana':9090}]
k = 2
conteudo de pt1: [{'Fulano',1010}, {'Beltrano',2020}]
conteudo de pt2: [{'Fulana',7070}, {'Beltrana',8080}, {'Cicrana',9090}]
*/
void turmas_divisao(Aluno t[], int k, int N, Aluno **pt1, Aluno **pt2) {
    Aluno *t1 = new Aluno[k];
    Aluno *t2 = new Aluno[N-k];
    for (int i = 0; i < k; i++) {
        Aluno *a = new Aluno();
        a -> escreveNome(t[i].devolveNome());
        a -> escreveMatricula(t[i].devolveMatricula());
        t1[i] = *a;
        delete a;
    }
    for (int i = k; i < N; i++) {
        Aluno *a = new Aluno();
        a -> escreveNome(t[i].devolveNome());
        a -> escreveMatricula(t[i].devolveMatricula());
        t2[i-k] = *a;
        delete a;
    }
    // ... COLOQUE SEU CÓDIGO AQUI ...

    *pt1 = t1;
    *pt2 = t2;
}




/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/
