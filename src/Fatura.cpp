#include "Fatura.h"
#include <iostream>
#include <algorithm>

// Construtor
Fatura::Fatura(int idFatura, std::string dataVencimento, std::string status)
    : idFatura(idFatura), dataVencimento(dataVencimento), status(status), valorTotal(0.0), saldoAtual(0.0) {}

// Destrutor
Fatura::~Fatura() {
    for (auto transacao : listaTransacoes) {
        delete transacao;
    }
}

// Métodos
void Fatura::adicionarTransacao(Transacao* transacao) {
    listaTransacoes.push_back(transacao);
    calcularValorTotal();
}

void Fatura::calcularValorTotal() {
    valorTotal = 0.0;
    for (const auto& transacao : listaTransacoes) {
        valorTotal += transacao->getValor();
    }
}

void Fatura::exibirFatura() const {
    std::cout << "Fatura ID: " << idFatura << ", Data de Vencimento: " << dataVencimento << ", Status: " << status << "\n";
    std::cout << "Valor Total: " << valorTotal << "\n";
    std::cout << "Transacoes:\n";
    for (const auto& transacao : listaTransacoes) {
        std::cout << "ID: " << transacao->getIdTransacao() << ", Valor: " << transacao->getValor()
                  << ", Descricao: " << transacao->getDescricao() << "\n";
    }
}

// Getters e Setters
int Fatura::getIdFatura() const {
    return idFatura;
}

void Fatura::setIdFatura(int idFatura) {
    this->idFatura = idFatura;
}

double Fatura::getValorTotal() const {
    return valorTotal;
}

void Fatura::setValorTotal(double valorTotal) {
    this->valorTotal = valorTotal;
}

std::string Fatura::getDataVencimento() const {
    return dataVencimento;
}

void Fatura::setDataVencimento(const std::string& dataVencimento) {
    this->dataVencimento = dataVencimento;
}

std::string Fatura::getStatus() const {
    return status;
}

void Fatura::setStatus(const std::string& status) {
    this->status = status;
}

std::vector<Transacao*> Fatura::getListaTransacoes() const {
    return listaTransacoes;
}

void Fatura::setListaTransacoes(const std::vector<Transacao*>& transacoes) {
    this->listaTransacoes = transacoes;
    calcularValorTotal();
}

double Fatura::getSaldoAtual() const {
    return saldoAtual;
}

void Fatura::setSaldoAtual(double saldoAtual) {
    this->saldoAtual = saldoAtual;
}
