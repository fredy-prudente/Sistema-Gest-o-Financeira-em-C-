#include "Categoria.h"
#include <algorithm>

// Construtor
Categoria::Categoria(int idCategoria, std::string nome, std::string tipo, double orcamento,
                     std::string descricao, bool ativo)
    : idCategoria(idCategoria), nome(nome), tipo(tipo), orcamento(orcamento),
      descricao(descricao), ativo(ativo) {}

// Destrutor
Categoria::~Categoria() {
    for (auto subcategoria : subcategorias) {
        delete subcategoria;
    }
}

// Métodos para gerenciar subcategorias
void Categoria::adicionarSubcategoria(Categoria* categoria) {
    subcategorias.push_back(categoria);
}

void Categoria::removerSubcategoria(Categoria* categoria) {
    subcategorias.erase(std::remove(subcategorias.begin(), subcategorias.end(), categoria), subcategorias.end());
}

std::vector<Categoria*> Categoria::getSubcategorias() const {
    return subcategorias;
}

// Getters e Setters
int Categoria::getIdCategoria() const {
    return idCategoria;
}

void Categoria::setIdCategoria(int idCategoria) {
    this->idCategoria = idCategoria;
}

std::string Categoria::getNome() const {
    return nome;
}

void Categoria::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Categoria::getTipo() const {
    return tipo;
}

void Categoria::setTipo(const std::string& tipo) {
    this->tipo = tipo;
}

double Categoria::getOrcamento() const {
    return orcamento;
}

void Categoria::setOrcamento(double orcamento) {
    this->orcamento = orcamento;
}

std::string Categoria::getDescricao() const {
    return descricao;
}

void Categoria::setDescricao(const std::string& descricao) {
    this->descricao = descricao;
}

bool Categoria::isAtivo() const {
    return ativo;
}

void Categoria::setAtivo(bool ativo) {
    this->ativo = ativo;
}
