#include "Relatorio.h"
#include <iostream>

// Construtor
Relatorio::Relatorio(int idRelatorio, std::string tipoRelatorio, std::string periodo,
                     std::string dataGeracao)
    : idRelatorio(idRelatorio), tipoRelatorio(tipoRelatorio), periodo(periodo),
      dataGeracao(dataGeracao), totalReceitas(0.0), totalDespesas(0.0) {}

// Destrutor
Relatorio::~Relatorio() {}

// Métodos
void Relatorio::gerarRelatorio(const std::vector<Transacao*>& transacoes) {
    this->transacoes = transacoes;
    totalReceitas = 0.0;
    totalDespesas = 0.0;
    for (const auto& transacao : transacoes) {
        std::string tipoTransacao = transacao->getTipo();
        if (tipoTransacao == "credito") {
            totalReceitas += transacao->getValor();
        } else if (tipoTransacao == "debito") {
            totalDespesas += transacao->getValor();
        }
    }
}


void Relatorio::exibirRelatorio() const {
    std::cout << "Relatorio " << tipoRelatorio << " - " << periodo << "\n";
    std::cout << "Data de Geracao: " << dataGeracao << "\n";
    std::cout << "Total de Receitas: " << totalReceitas << "\n";
    std::cout << "Total de Despesas: " << totalDespesas << "\n";
    std::cout << "Transacoes:\n";
    for (const auto& transacao : transacoes) {
        std::cout << "ID: " << transacao->getIdTransacao() << ", Valor: " << transacao->getValor()
                  << ", Tipo: " << transacao->getTipo() << ", Descricao: " << transacao->getDescricao() << "\n";
    }
}

// Getters e Setters
int Relatorio::getIdRelatorio() const {
    return idRelatorio;
}

void Relatorio::setIdRelatorio(int idRelatorio) {
    this->idRelatorio = idRelatorio;
}

std::string Relatorio::getTipoRelatorio() const {
    return tipoRelatorio;
}

void Relatorio::setTipoRelatorio(const std::string& tipoRelatorio) {
    this->tipoRelatorio = tipoRelatorio;
}

std::string Relatorio::getPeriodo() const {
    return periodo;
}

void Relatorio::setPeriodo(const std::string& periodo) {
    this->periodo = periodo;
}

std::string Relatorio::getDataGeracao() const {
    return dataGeracao;
}

void Relatorio::setDataGeracao(const std::string& dataGeracao) {
    this->dataGeracao = dataGeracao;
}

double Relatorio::getTotalReceitas() const {
    return totalReceitas;
}

void Relatorio::setTotalReceitas(double totalReceitas) {
    this->totalReceitas = totalReceitas;
}

double Relatorio::getTotalDespesas() const {
    return totalDespesas;
}

void Relatorio::setTotalDespesas(double totalDespesas) {
    this->totalDespesas = totalDespesas;
}

std::vector<Transacao*> Relatorio::getTransacoes() const {
    return transacoes;
}

void Relatorio::setTransacoes(const std::vector<Transacao*>& transacoes) {
    this->transacoes = transacoes;
}
