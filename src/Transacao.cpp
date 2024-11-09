#include "Transacao.h"

// Construtor
Transacao::Transacao(int idTransacao, double valor, std::string data, std::string tipo,
                     Categoria* categoria, std::string descricao)
    : idTransacao(idTransacao), valor(valor), data(data), tipo(tipo),
      categoria(categoria), descricao(descricao) {}

// Destrutor
Transacao::~Transacao() {}

// Getters e Setters
int Transacao::getIdTransacao() const {
    return idTransacao;
}

void Transacao::setIdTransacao(int idTransacao) {
    this->idTransacao = idTransacao;
}

double Transacao::getValor() const {
    return valor;
}

void Transacao::setValor(double valor) {
    this->valor = valor;
}

std::string Transacao::getData() const {
    return data;
}

void Transacao::setData(const std::string& data) {
    this->data = data;
}

std::string Transacao::getTipo() const {
    return tipo;
}

void Transacao::setTipo(const std::string& tipo) {
    this->tipo = tipo;
}

Categoria* Transacao::getCategoria() const {
    return categoria;
}

void Transacao::setCategoria(Categoria* categoria) {
    this->categoria = categoria;
}

std::string Transacao::getDescricao() const {
    return descricao;
}

void Transacao::setDescricao(const std::string& descricao) {
    this->descricao = descricao;
}
