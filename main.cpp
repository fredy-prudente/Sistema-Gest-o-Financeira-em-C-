#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "include/Usuario.h"
#include "include/ContaBancaria.h"
#include "include/Transacao.h"
#include "include/Categoria.h"
#include "include/Orcamento.h"
#include "include/Relatorio.h"
#include "include/Investimento.h"
#include "include/Emprestimo.h"
#include "include/Pagamento.h"
#include "include/Fatura.h"

int main() {
    int opcao;
    Usuario* usuario = nullptr;
    Orcamento* orcamento = nullptr;
    Relatorio* relatorio = nullptr;
    Fatura* fatura = nullptr;

    // Vetores para armazenar objetos
    std::vector<Categoria*> categorias;
    std::vector<Transacao*> transacoes;
    std::vector<Investimento*> investimentos;
    std::vector<Emprestimo*> emprestimos;

    do {
        std::cout << "=== Sistema Financeiro ===\n";
        std::cout << "1. Cadastrar Usuario\n";
        std::cout << "2. Adicionar Conta Bancaria\n";
        std::cout << "3. Registrar Transacao\n";
        std::cout << "4. Consultar Saldo\n";
        std::cout << "5. Gerar Relatorio\n";
        std::cout << "6. Definir Orcamento\n";
        std::cout << "7. Gerenciar Investimentos\n";
        std::cout << "8. Administrar Emprestimos\n";
        std::cout << "9. Visualizar Fatura\n";
        std::cout << "10. Sair\n";
        std::cout << "Selecione uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpar o buffer do '\n'

        switch(opcao) {
            case 1: {
                // Cadastro de Usuario
                std::string nome, email, senha, endereco, telefone, dataCadastro;
                std::cout << "=== Cadastro de Usuario ===\n";
                std::cout << "Nome: ";
                std::getline(std::cin, nome);
                std::cout << "Email: ";
                std::getline(std::cin, email);
                std::cout << "Senha: ";
                std::getline(std::cin, senha);
                std::cout << "Endereco: ";
                std::getline(std::cin, endereco);
                std::cout << "Telefone: ";
                std::getline(std::cin, telefone);
                std::cout << "Data de Cadastro (dd/mm/aaaa): ";
                std::getline(std::cin, dataCadastro);

                usuario = new Usuario(nome, email, senha, endereco, telefone, dataCadastro);
                std::cout << "Usuario cadastrado com sucesso!\n";
                break;
            }
            case 2: {
                // Adicionar Conta Bancaria
                if (usuario == nullptr) {
                    std::cout << "Voce precisa cadastrar um usuario primeiro.\n";
                    break;
                }
                std::string numeroConta, tipoConta, agencia, banco;
                double saldo, limite;

                std::cout << "=== Adicionar Conta Bancaria ===\n";
                std::cout << "Numero da Conta: ";
                std::getline(std::cin, numeroConta);
                std::cout << "Tipo de Conta: ";
                std::getline(std::cin, tipoConta);
                std::cout << "Saldo Inicial: ";
                std::cin >> saldo;
                std::cin.ignore();
                std::cout << "Agencia: ";
                std::getline(std::cin, agencia);
                std::cout << "Banco: ";
                std::getline(std::cin, banco);
                std::cout << "Limite: ";
                std::cin >> limite;
                std::cin.ignore();

                ContaBancaria* conta = new ContaBancaria(numeroConta, tipoConta, saldo, agencia, banco, limite);
                usuario->adicionarConta(conta);
                std::cout << "Conta bancaria adicionada com sucesso!\n";
                break;
            }
            case 3: {
                // Registrar Transacao
                if (usuario == nullptr || usuario->getContas().empty()) {
                    std::cout << "Voce precisa cadastrar um usuario e uma conta bancaria primeiro.\n";
                    break;
                }
                int idTransacao;
                double valor;
                std::string data, tipo, descricao, nomeCategoria, tipoCategoria;
                double orcamentoCategoria;
                bool ativoCategoria;

                std::cout << "=== Registrar Transacao ===\n";
                std::cout << "ID da Transacao: ";
                std::cin >> idTransacao;
                std::cin.ignore();
                std::cout << "Valor: ";
                std::cin >> valor;
                std::cin.ignore();
                std::cout << "Data (dd/mm/aaaa): ";
                std::getline(std::cin, data);
                std::cout << "Tipo (debito/credito): ";
                std::getline(std::cin, tipo);

                // Converter para minusculas
                std::transform(tipo.begin(), tipo.end(), tipo.begin(), [](unsigned char c){ return std::tolower(c); });

                std::cout << "Descricao: ";
                std::getline(std::cin, descricao);

                // Selecionar ou criar categoria
                std::cout << "Nome da Categoria: ";
                std::getline(std::cin, nomeCategoria);
                Categoria* categoria = nullptr;
                for (auto cat : categorias) {
                    if (cat->getNome() == nomeCategoria) {
                        categoria = cat;
                        break;
                    }
                }
                if (categoria == nullptr) {
                    std::cout << "Categoria nao encontrada. Criando nova categoria.\n";
                    std::cout << "Tipo da Categoria (receita/despesa): ";
                    std::getline(std::cin, tipoCategoria);
                    std::cout << "Orcamento da Categoria: ";
                    std::cin >> orcamentoCategoria;
                    std::cin.ignore();
                    std::cout << "Ativo (1 para Sim, 0 para Nao): ";
                    std::cin >> ativoCategoria;
                    std::cin.ignore();
                    categoria = new Categoria(categorias.size() + 1, nomeCategoria, tipoCategoria, orcamentoCategoria, "", ativoCategoria);
                    categorias.push_back(categoria);
                }

                // Criar transacao
                Transacao* transacao = new Transacao(idTransacao, valor, data, tipo, categoria, descricao);

                // Atualizar saldo da conta
                std::cout << "Selecione a conta para registrar a transacao:\n";
                auto contas = usuario->getContas();
                for (size_t i = 0; i < contas.size(); ++i) {
                    std::cout << i + 1 << ". " << contas[i]->getNumeroConta() << " - " << contas[i]->getBanco() << "\n";
                }
                int contaOpcao;
                std::cin >> contaOpcao;
                std::cin.ignore();
                if (contaOpcao < 1 || contaOpcao > contas.size()) {
                    std::cout << "Opcao invalida.\n";
                    delete transacao;
                    break;
                }
                ContaBancaria* contaSelecionada = contas[contaOpcao - 1];

                if (tipo == "debito") {
                    if (contaSelecionada->sacar(valor)) {
                        contaSelecionada->adicionarTransacao(transacao);
                        transacoes.push_back(transacao);
                        std::cout << "Transacao registrada e saldo atualizado.\n";
                    } else {
                        std::cout << "Saldo insuficiente.\n";
                        delete transacao;
                    }
                } else if (tipo == "credito") {
                    contaSelecionada->depositar(valor);
                    contaSelecionada->adicionarTransacao(transacao);
                    transacoes.push_back(transacao);
                    std::cout << "Transacao registrada e saldo atualizado.\n";
                } else {
                    std::cout << "Tipo de transacao invalido.\n";
                    delete transacao;
                }

                // Atualizar orcamento se existir
                if (orcamento != nullptr) {
                    orcamento->atualizarValorGasto(valor);
                }

                break;
            }
            case 4: {
                // Consultar Saldo
                if (usuario == nullptr || usuario->getContas().empty()) {
                    std::cout << "Voce nao possui contas bancarias.\n";
                    break;
                }
                std::cout << "=== Consultar Saldo ===\n";
                auto contas = usuario->getContas();
                for (size_t i = 0; i < contas.size(); ++i) {
                    std::cout << i + 1 << ". " << contas[i]->getNumeroConta() << " - " << contas[i]->getBanco() << "\n";
                }
                std::cout << "Selecione a conta: ";
                int contaOpcao;
                std::cin >> contaOpcao;
                std::cin.ignore();
                if (contaOpcao < 1 || contaOpcao > contas.size()) {
                    std::cout << "Opcao invalida.\n";
                    break;
                }
                std::cout << "Saldo atual: " << contas[contaOpcao - 1]->getSaldo() << "\n";
                break;
            }
            case 5: {
                // Gerar Relatorio
                if (transacoes.empty()) {
                    std::cout << "Nao ha transacoes para gerar relatorio.\n";
                    break;
                }
                int idRelatorio;
                std::string tipoRelatorio, periodo, dataGeracao;

                std::cout << "=== Gerar Relatorio ===\n";
                std::cout << "ID do Relatorio: ";
                std::cin >> idRelatorio;
                std::cin.ignore();
                std::cout << "Tipo de Relatorio (Mensal, Anual, etc.): ";
                std::getline(std::cin, tipoRelatorio);
                std::cout << "Periodo: ";
                std::getline(std::cin, periodo);
                std::cout << "Data de Geracao (dd/mm/aaaa): ";
                std::getline(std::cin, dataGeracao);

                relatorio = new Relatorio(idRelatorio, tipoRelatorio, periodo, dataGeracao);
                relatorio->gerarRelatorio(transacoes);
                relatorio->exibirRelatorio();
                delete relatorio;
                relatorio = nullptr;
                break;
            }
            case 6: {
                // Definir Orcamento
                if (orcamento != nullptr) {
                    delete orcamento;
                }
                int idOrcamento;
                double valorTotal;
                std::string periodo;

                std::cout << "=== Definir Orcamento ===\n";
                std::cout << "ID do Orcamento: ";
                std::cin >> idOrcamento;
                std::cin.ignore();
                std::cout << "Valor Total: ";
                std::cin >> valorTotal;
                std::cin.ignore();
                std::cout << "Periodo: ";
                std::getline(std::cin, periodo);

                orcamento = new Orcamento(idOrcamento, valorTotal, periodo);
                for (auto categoria : categorias) {
                    orcamento->adicionarCategoria(categoria);
                }
                std::cout << "Orcamento definido com sucesso!\n";
                break;
            }
            case 7: {
                // Gerenciar Investimentos
                int opcaoInvestimento;
                std::cout << "=== Gerenciar Investimentos ===\n";
                std::cout << "1. Adicionar Investimento\n";
                std::cout << "2. Listar Investimentos\n";
                std::cout << "Selecione uma opcao: ";
                std::cin >> opcaoInvestimento;
                std::cin.ignore();

                if (opcaoInvestimento == 1) {
                    int idTransacao;
                    double valor, rentabilidade;
                    std::string data, tipo, descricao, tipoInvestimento, dataAplicacao, prazo;

                    std::cout << "ID da Transacao: ";
                    std::cin >> idTransacao;
                    std::cin.ignore();
                    std::cout << "Valor Aplicado: ";
                    std::cin >> valor;
                    std::cin.ignore();
                    std::cout << "Data (dd/mm/aaaa): ";
                    std::getline(std::cin, data);
                    tipo = "credito";
                    std::cout << "Descricao: ";
                    std::getline(std::cin, descricao);
                    std::cout << "Tipo de Investimento: ";
                    std::getline(std::cin, tipoInvestimento);
                    std::cout << "Data de Aplicacao (dd/mm/aaaa): ";
                    std::getline(std::cin, dataAplicacao);
                    std::cout << "Rentabilidade (%): ";
                    std::cin >> rentabilidade;
                    std::cin.ignore();
                    std::cout << "Prazo: ";
                    std::getline(std::cin, prazo);

                    // Categoria para investimentos
                    Categoria* categoriaInvestimento = nullptr;
                    for (auto cat : categorias) {
                        if (cat->getNome() == "Investimento") {
                            categoriaInvestimento = cat;
                            break;
                        }
                    }
                    if (categoriaInvestimento == nullptr) {
                        categoriaInvestimento = new Categoria(categorias.size() + 1, "Investimento", "receita", 0.0, "", true);
                        categorias.push_back(categoriaInvestimento);
                    }

                    Investimento* investimento = new Investimento(idTransacao, valor, data, tipo, categoriaInvestimento, descricao,
                                                                  tipoInvestimento, dataAplicacao, rentabilidade, prazo);
                    investimentos.push_back(investimento);
                    transacoes.push_back(investimento);

                    std::cout << "Investimento adicionado com sucesso!\n";
                } else if (opcaoInvestimento == 2) {
                    if (investimentos.empty()) {
                        std::cout << "Nao ha investimentos cadastrados.\n";
                    } else {
                        for (const auto& investimento : investimentos) {
                            std::cout << "ID: " << investimento->getIdTransacao()
                                      << ", Tipo: " << investimento->getTipoInvestimento()
                                      << ", Valor Aplicado: " << investimento->getValor()
                                      << ", Rentabilidade: " << investimento->getRentabilidade() << "%\n";
                        }
                    }
                } else {
                    std::cout << "Opcao invalida.\n";
                }
                break;
            }
            case 8: {
                // Administrar Emprestimos
                int opcaoEmprestimo;
                std::cout << "=== Administrar Emprestimos ===\n";
                std::cout << "1. Adicionar Emprestimo\n";
                std::cout << "2. Listar Emprestimos\n";
                std::cout << "Selecione uma opcao: ";
                std::cin >> opcaoEmprestimo;
                std::cin.ignore();

                if (opcaoEmprestimo == 1) {
                    int idTransacao, prazo;
                    double valor, taxaJuros;
                    std::string data, tipo, descricao, dataContratacao;

                    std::cout << "ID da Transacao: ";
                    std::cin >> idTransacao;
                    std::cin.ignore();
                    std::cout << "Valor Emprestado: ";
                    std::cin >> valor;
                    std::cin.ignore();
                    std::cout << "Data (dd/mm/aaaa): ";
                    std::getline(std::cin, data);
                    tipo = "debito";
                    std::cout << "Descricao: ";
                    std::getline(std::cin, descricao);
                    std::cout << "Taxa de Juros (%): ";
                    std::cin >> taxaJuros;
                    std::cin.ignore();
                    std::cout << "Prazo (meses): ";
                    std::cin >> prazo;
                    std::cin.ignore();
                    std::cout << "Data de Contratacao (dd/mm/aaaa): ";
                    std::getline(std::cin, dataContratacao);

                    // Categoria para emprestimos
                    Categoria* categoriaEmprestimo = nullptr;
                    for (auto cat : categorias) {
                        if (cat->getNome() == "Emprestimo") {
                            categoriaEmprestimo = cat;
                            break;
                        }
                    }
                    if (categoriaEmprestimo == nullptr) {
                        categoriaEmprestimo = new Categoria(categorias.size() + 1, "Emprestimo", "despesa", 0.0, "", true);
                        categorias.push_back(categoriaEmprestimo);
                    }

                    Emprestimo* emprestimo = new Emprestimo(idTransacao, valor, data, tipo, categoriaEmprestimo, descricao,
                                                            taxaJuros, prazo, dataContratacao);
                    emprestimos.push_back(emprestimo);
                    transacoes.push_back(emprestimo);

                    std::cout << "Emprestimo adicionado com sucesso!\n";
                } else if (opcaoEmprestimo == 2) {
                    if (emprestimos.empty()) {
                        std::cout << "Nao ha emprestimos cadastrados.\n";
                    } else {
                        for (const auto& emprestimo : emprestimos) {
                            std::cout << "ID: " << emprestimo->getIdTransacao()
                                      << ", Valor Emprestado: " << emprestimo->getValor()
                                      << ", Taxa de Juros: " << emprestimo->getTaxaJuros()
                                      << "%, Saldo Devedor: " << emprestimo->getSaldoDevedor() << "\n";
                        }
                    }
                } else {
                    std::cout << "Opcao invalida.\n";
                }
                break;
            }
            case 9: {
                // Visualizar Fatura
                if (transacoes.empty()) {
                    std::cout << "Nao ha transacoes para gerar fatura.\n";
                    break;
                }
                int idFatura;
                std::string dataVencimento, status;

                std::cout << "=== Visualizar Fatura ===\n";
                std::cout << "ID da Fatura: ";
                std::cin >> idFatura;
                std::cin.ignore();
                std::cout << "Data de Vencimento (dd/mm/aaaa): ";
                std::getline(std::cin, dataVencimento);
                std::cout << "Status (Paga/Nao Paga): ";
                std::getline(std::cin, status);

                fatura = new Fatura(idFatura, dataVencimento, status);
                for (auto transacao : transacoes) {
                    fatura->adicionarTransacao(transacao);
                }
                fatura->exibirFatura();
                delete fatura;
                fatura = nullptr;
                break;
            }
            case 10:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
        }

        std::cout << "\n";

    } while(opcao != 10);

    // Liberar memoria alocada
    if (usuario != nullptr) {
        delete usuario;
    }
    if (orcamento != nullptr) {
        delete orcamento;
    }
    if (relatorio != nullptr) {
        delete relatorio;
    }
    if (fatura != nullptr) {
        delete fatura;
    }
    for (auto transacao : transacoes) {
        delete transacao;
    }
    for (auto categoria : categorias) {
        delete categoria;
    }

    return 0;
}
