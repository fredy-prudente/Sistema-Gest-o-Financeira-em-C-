#include "Pagamento.h"

// Construtor
Pagamento::Pagamento(int idTransacao, double valor, std::string data, std::string tipo,
                     Categoria* categoria, std::string descricao, std::string formaPagamento,
                     std::string beneficiario, std::string comprovante)
    : Transacao(idTransacao, valor, data, tipo, categoria, descricao),
      formaPagamento(formaPagamento), beneficiario(beneficiario), comprovante(comprovante) {}

// Getters e Setters
std::string Pagamento::getFormaPagamento() const {
    return formaPagamento;
}

void Pagamento::setFormaPagamento(const std::string& formaPagamento) {
    this->formaPagamento = formaPagamento;
}

std::string Pagamento::getBeneficiario() const {
    return beneficiario;
}

void Pagamento::setBeneficiario(const std::string& beneficiario) {
    this->beneficiario = beneficiario;
}

std::string Pagamento::getComprovante() const {
    return comprovante;
}

void Pagamento::setComprovante(const std::string& comprovante) {
    this->comprovante = comprovante;
}
