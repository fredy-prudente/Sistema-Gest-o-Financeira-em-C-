#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>
#include <vector>
#include "Transacao.h"

class ContaBancaria {
protected:
    std::string numeroConta;
    std::string tipoConta;
    double saldo;
    std::string agencia;
    std::string banco;
    double limite;
    std::vector<Transacao*> transacoes;

public:
    // Construtor
    ContaBancaria(std::string numeroConta, std::string tipoConta, double saldo,
                  std::string agencia, std::string banco, double limite);

    // Destrutor
    virtual ~ContaBancaria();

    // Métodos para gerenciar transações
    void adicionarTransacao(Transacao* transacao);
    std::vector<Transacao*> getTransacoes() const;

    // Métodos para depósito, saque, etc.
    virtual void depositar(double valor);
    virtual bool sacar(double valor);

    // Getters e Setters
    std::string getNumeroConta() const;
    void setNumeroConta(const std::string& numeroConta);

    std::string getTipoConta() const;
    void setTipoConta(const std::string& tipoConta);

    double getSaldo() const;
    void setSaldo(double saldo);

    std::string getAgencia() const;
    void setAgencia(const std::string& agencia);

    std::string getBanco() const;
    void setBanco(const std::string& banco);

    double getLimite() const;
    void setLimite(double limite);
};

#endif // CONTABANCARIA_H
