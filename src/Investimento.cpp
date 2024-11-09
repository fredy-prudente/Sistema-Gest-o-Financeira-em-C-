#include "Investimento.h"

// Construtor
Investimento::Investimento(int idTransacao, double valor, std::string data, std::string tipo,
                           Categoria* categoria, std::string descricao, std::string tipoInvestimento,
                           std::string dataAplicacao, double rentabilidade, std::string prazo)
    : Transacao(idTransacao, valor, data, tipo, categoria, descricao),
      tipoInvestimento(tipoInvestimento), dataAplicacao(dataAplicacao),
      rentabilidade(rentabilidade), prazo(prazo) {}

// Métodos
double Investimento::calcularRetorno() const {
    return valor * (1 + rentabilidade / 100);
}

// Getters e Setters
std::string Investimento::getTipoInvestimento() const {
    return tipoInvestimento;
}

void Investimento::setTipoInvestimento(const std::string& tipoInvestimento) {
    this->tipoInvestimento = tipoInvestimento;
}

std::string Investimento::getDataAplicacao() const {
    return dataAplicacao;
}

void Investimento::setDataAplicacao(const std::string& dataAplicacao) {
    this->dataAplicacao = dataAplicacao;
}

double Investimento::getRentabilidade() const {
    return rentabilidade;
}

void Investimento::setRentabilidade(double rentabilidade) {
    this->rentabilidade = rentabilidade;
}

std::string Investimento::getPrazo() const {
    return prazo;
}

void Investimento::setPrazo(const std::string& prazo) {
    this->prazo = prazo;
}
