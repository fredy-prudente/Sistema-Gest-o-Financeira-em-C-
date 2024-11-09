#include "ContaBancaria.h"
#include <algorithm>

// Construtor
ContaBancaria::ContaBancaria(std::string numeroConta, std::string tipoConta, double saldo,
                             std::string agencia, std::string banco, double limite)
    : numeroConta(numeroConta), tipoConta(tipoConta), saldo(saldo),
      agencia(agencia), banco(banco), limite(limite) {}

// Destrutor
ContaBancaria::~ContaBancaria() {
    for (auto transacao : transacoes) {
        delete transacao;
    }
}

// Métodos para gerenciar transações
void ContaBancaria::adicionarTransacao(Transacao* transacao) {
    transacoes.push_back(transacao);
}

std::vector<Transacao*> ContaBancaria::getTransacoes() const {
    return transacoes;
}

// Métodos para depósito e saque
void ContaBancaria::depositar(double valor) {
    saldo += valor;
}

bool ContaBancaria::sacar(double valor) {
    if (valor <= saldo + limite) {
        saldo -= valor;
        return true;
    }
    return false;
}

// Getters e Setters
std::string ContaBancaria::getNumeroConta() const {
    return numeroConta;
}

void ContaBancaria::setNumeroConta(const std::string& numeroConta) {
    this->numeroConta = numeroConta;
}

std::string ContaBancaria::getTipoConta() const {
    return tipoConta;
}

void ContaBancaria::setTipoConta(const std::string& tipoConta) {
    this->tipoConta = tipoConta;
}

double ContaBancaria::getSaldo() const {
    return saldo;
}

void ContaBancaria::setSaldo(double saldo) {
    this->saldo = saldo;
}

std::string ContaBancaria::getAgencia() const {
    return agencia;
}

void ContaBancaria::setAgencia(const std::string& agencia) {
    this->agencia = agencia;
}

std::string ContaBancaria::getBanco() const {
    return banco;
}

void ContaBancaria::setBanco(const std::string& banco) {
    this->banco = banco;
}

double ContaBancaria::getLimite() const {
    return limite;
}

void ContaBancaria::setLimite(double limite) {
    this->limite = limite;
}
