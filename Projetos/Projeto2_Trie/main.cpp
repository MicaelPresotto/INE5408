#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <omp.h>
#define letras_alfabeto 26
using namespace std;

class TrieNode {
public:
    TrieNode* filhos[letras_alfabeto];
    int prefixos, comprimento, posicao;

    TrieNode() {
        #pragma omp parallel for schedule(static)
        for (int i = 0; i < letras_alfabeto; i++) filhos[i] = nullptr;
        posicao = 0;
        comprimento = 0;
        prefixos = 0;
    }
    ~TrieNode(){};
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {deletar(root); root = nullptr;}
    void deletar(TrieNode* root){
        for (int i = 0; i < letras_alfabeto; i++){
            
            if(root->filhos[i]){
                deletar(root->filhos[i]);
            }
        }
        delete root;
    }
    string strToLower(string key){
        for (char& c : key) {
            c = tolower(c);
        }
        return key;
    }
    void insert(string key, int posicao, int comprimento) {
        TrieNode* aux = root;
        strToLower(key);
        for (char c : key) {
            int index = c - 'a';
            if (!aux->filhos[index]) {
                aux->filhos[index] = new TrieNode();
            }
            aux = aux->filhos[index];
            aux->prefixos++;
        }
        aux->comprimento = comprimento;
        aux->posicao = posicao;
    }

    TrieNode* countPrefixes(string key) {
        TrieNode* aux = root;
        strToLower(key);
        #pragma omp parallel for schedule(guided)
        for (char c : key) {
            int index = c - 'a';
            if (!aux->filhos[index]) {
                return nullptr;
            }
            aux = aux->filhos[index];
        }
        return aux;
    }
};
Trie trie;
void extraiDics(string dic) {
    ifstream my_file(dic);
    if (my_file.is_open()){
        string linha;
        int position = 0;
        while (getline(my_file, linha)){
            size_t inicio = linha.find('[');
            size_t final = linha.find(']', inicio);
            string word = linha.substr(inicio + 1, final - inicio - 1);
            trie.insert(word, position, linha.length());
            position += linha.length() + 1;
        }
        my_file.close();
    }
}

int main() {
    string filename;
    string word;
    vector<string> words;
    cin >> filename;
    extraiDics(filename);
    
    while (1) {  // leitura das palavras ate' encontrar "0"
        cin >> word;
        if (word.compare("0") == 0) {
            break;
        }
        words.push_back(word);
    }
    
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < words.size(); i++) {
        TrieNode* aux = trie.countPrefixes(words[i]);
        if (!aux) {
            cout << words[i] << " is not prefix" << endl;
        } else {
            cout << words[i] << " is prefix of " << aux->prefixos << " words" << endl;
            if (aux->comprimento){
                cout << words[i] << " is at (" << aux->posicao << "," << aux->comprimento << ")" << endl;
            }
        }
    }
 
    return 0;
}
