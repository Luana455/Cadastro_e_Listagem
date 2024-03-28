#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// Defini��o da classe Produto
class Produto {
public:
    string nome;
    float valor;

    // Construtor
    Produto(string n, float v) : nome(n), valor(v) {}
};

// Fun��o para ordenar os produtos por valor (do menor para o maior)
bool compararPorValor(const Produto& p1, const Produto& p2) {
    return p1.valor < p2.valor;
}

int main() {
    setlocale(LC_ALL, "ptb");

    vector<Produto> listaProdutos;

    while (true) {
        char opcao;
        cout << "\nMENU:" << endl;
        cout << "1 - Listar produtos" << endl;
        cout << "2 - Cadastrar novo produto" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        if (opcao == '1') {
            // Ordena os produtos por valor
            sort(listaProdutos.begin(), listaProdutos.end(), compararPorValor);

            // Exibe a lista de produtos
            cout << "\nLISTA DE PRODUTOS:" << endl;
            cout << "---------------------------" << endl;
            cout << "Nome\t\tValor" << endl;
            cout << "---------------------------" << endl;
            for (const Produto& produto : listaProdutos) {
                cout << produto.nome << "\t\t" << produto.valor << endl;
            }
        }
        else if (opcao == '2') {
            // Cadastro de um novo produto
            string nome;
            float valor;
            cout << "\nCADASTRO DE NOVO PRODUTO:" << endl;
            cout << "Nome do produto: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Valor do produto: ";
            cin >> valor;

            // Adiciona o novo produto � lista
            listaProdutos.push_back(Produto(nome, valor));

            // Ordena os produtos por valor
            sort(listaProdutos.begin(), listaProdutos.end(), compararPorValor);

            // Exibe a lista de produtos atualizada
            cout << "\nLista de produtos atualizada:" << endl;
            cout << "---------------------------" << endl;
            cout << "Nome\t\tValor" << endl;
            cout << "---------------------------" << endl;
            for (const Produto& produto : listaProdutos) {
                cout << produto.nome << "\t\t" << produto.valor << endl;
            }
        }
        else if (opcao == '3') {
            // Sai do programa
            cout << "Saindo..." << endl;
            break;
        }
        else {
            cout << "Op��o inv�lida. Por favor, escolha uma op��o v�lida." << endl;
        }
    }

    return 0;
}