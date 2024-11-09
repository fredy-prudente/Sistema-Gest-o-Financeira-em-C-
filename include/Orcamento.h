#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include <string>
#include <vector>
#include "Categoria.h"

class Orcamento {
private:
    int idOrcamento;
    double valorTotal;
    std::string periodo;
    std::vector<Categoria*> categoriasIncluidas;
    double valorGasto;
    double valorRestante;

public:
    // Construtor
    Orcamento(int idOrcamento, double valorTotal, std::string periodo);

    // Destrutor
    ~Orcamento();

    // Métodos para gerenciar categorias
    void adicionarCategoria(Categoria* categoria);
    void removerCategoria(Categoria* categoria);
    std::vector<Categoria*> getCategoriasIncluidas() const;

    // Métodos para atualizar valores
    void atualizarValorGasto(double valor);
    void calcularValorRestante();

    // Getters e Setters
    int getIdOrcamento() const;
    void setIdOrcamento(int idOrcamento);

    double getValorTotal() const;
    void setValorTotal(double valorTotal);

    std::string getPeriodo() const;
    void setPeriodo(const std::string& periodo);

    double getValorGasto() const;
    void setValorGasto(double valorGasto);

    double getValorRestante() const;
    void setValorRestante(double valorRestante);
};

#endif // ORCAMENTO_H
