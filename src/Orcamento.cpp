#include "Orcamento.h"
#include <algorithm>

// Construtor
Orcamento::Orcamento(int idOrcamento, double valorTotal, std::string periodo)
    : idOrcamento(idOrcamento), valorTotal(valorTotal), periodo(periodo),
      valorGasto(0.0) {
    calcularValorRestante();
}

// Destrutor
Orcamento::~Orcamento() {
    for (auto categoria : categoriasIncluidas) {
        delete categoria;
    }
}

// Métodos para gerenciar categorias
void Orcamento::adicionarCategoria(Categoria* categoria) {
    categoriasIncluidas.push_back(categoria);
}

void Orcamento::removerCategoria(Categoria* categoria) {
    categoriasIncluidas.erase(std::remove(categoriasIncluidas.begin(), categoriasIncluidas.end(), categoria), categoriasIncluidas.end());
}

std::vector<Categoria*> Orcamento::getCategoriasIncluidas() const {
    return categoriasIncluidas;
}

// Métodos para atualizar valores
void Orcamento::atualizarValorGasto(double valor) {
    valorGasto += valor;
    calcularValorRestante();
}

void Orcamento::calcularValorRestante() {
    valorRestante = valorTotal - valorGasto;
}

// Getters e Setters
int Orcamento::getIdOrcamento() const {
    return idOrcamento;
}

void Orcamento::setIdOrcamento(int idOrcamento) {
    this->idOrcamento = idOrcamento;
}

double Orcamento::getValorTotal() const {
    return valorTotal;
}

void Orcamento::setValorTotal(double valorTotal) {
    this->valorTotal = valorTotal;
}

std::string Orcamento::getPeriodo() const {
    return periodo;
}

void Orcamento::setPeriodo(const std::string& periodo) {
    this->periodo = periodo;
}

double Orcamento::getValorGasto() const {
    return valorGasto;
}

void Orcamento::setValorGasto(double valorGasto) {
    this->valorGasto = valorGasto;
    calcularValorRestante();
}

double Orcamento::getValorRestante() const {
    return valorRestante;
}

void Orcamento::setValorRestante(double valorRestante) {
    this->valorRestante = valorRestante;
}
