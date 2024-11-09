#include "Emprestimo.h"
#include <cmath>

// Construtor
Emprestimo::Emprestimo(int idTransacao, double valor, std::string data, std::string tipo,
                       Categoria* categoria, std::string descricao, double taxaJuros, int prazo,
                       std::string dataContratacao)
    : Transacao(idTransacao, valor, data, tipo, categoria, descricao),
      taxaJuros(taxaJuros), prazo(prazo), dataContratacao(dataContratacao) {
    saldoDevedor = valor;
}

// Métodos
double Emprestimo::calcularParcelaMensal() const {
    double taxaMensal = taxaJuros / 100;
    return (valor * taxaMensal) / (1 - pow(1 + taxaMensal, -prazo));
}

// Getters e Setters
double Emprestimo::getTaxaJuros() const {
    return taxaJuros;
}

void Emprestimo::setTaxaJuros(double taxaJuros) {
    this->taxaJuros = taxaJuros;
}

int Emprestimo::getPrazo() const {
    return prazo;
}

void Emprestimo::setPrazo(int prazo) {
    this->prazo = prazo;
}

double Emprestimo::getSaldoDevedor() const {
    return saldoDevedor;
}

void Emprestimo::setSaldoDevedor(double saldoDevedor) {
    this->saldoDevedor = saldoDevedor;
}

std::string Emprestimo::getDataContratacao() const {
    return dataContratacao;
}

void Emprestimo::setDataContratacao(const std::string& dataContratacao) {
    this->dataContratacao = dataContratacao;
}
