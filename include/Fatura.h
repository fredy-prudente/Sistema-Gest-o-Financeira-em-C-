#ifndef FATURA_H
#define FATURA_H

#include <string>
#include <vector>
#include "Transacao.h"

class Fatura {
private:
    int idFatura;
    double valorTotal;
    std::string dataVencimento;
    std::string status;
    std::vector<Transacao*> listaTransacoes;
    double saldoAtual;

public:
    // Construtor
    Fatura(int idFatura, std::string dataVencimento, std::string status);

    // Destrutor
    ~Fatura();

    // Métodos
    void adicionarTransacao(Transacao* transacao);
    void calcularValorTotal();
    void exibirFatura() const;

    // Getters e Setters
    int getIdFatura() const;
    void setIdFatura(int idFatura);

    double getValorTotal() const;
    void setValorTotal(double valorTotal);

    std::string getDataVencimento() const;
    void setDataVencimento(const std::string& dataVencimento);

    std::string getStatus() const;
    void setStatus(const std::string& status);

    std::vector<Transacao*> getListaTransacoes() const;
    void setListaTransacoes(const std::vector<Transacao*>& transacoes);

    double getSaldoAtual() const;
    void setSaldoAtual(double saldoAtual);
};

#endif // FATURA_H
