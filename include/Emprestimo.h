#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <string>
#include "Transacao.h"

class Emprestimo : public Transacao {
private:
    double taxaJuros;
    int prazo; // em meses
    double saldoDevedor;
    std::string dataContratacao;

public:
    // Construtor
    Emprestimo(int idTransacao, double valor, std::string data, std::string tipo,
               Categoria* categoria, std::string descricao, double taxaJuros, int prazo,
               std::string dataContratacao);

    // Métodos
    double calcularParcelaMensal() const;

    // Getters e Setters
    double getTaxaJuros() const;
    void setTaxaJuros(double taxaJuros);

    int getPrazo() const;
    void setPrazo(int prazo);

    double getSaldoDevedor() const;
    void setSaldoDevedor(double saldoDevedor);

    std::string getDataContratacao() const;
    void setDataContratacao(const std::string& dataContratacao);
};

#endif // EMPRESTIMO_H
