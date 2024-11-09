#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
#include "Categoria.h"

class Transacao {
protected:
    int idTransacao;
    double valor;
    std::string data;
    std::string tipo; // débito ou crédito
    Categoria* categoria;
    std::string descricao;

public:
    // Construtor
    Transacao(int idTransacao, double valor, std::string data, std::string tipo,
              Categoria* categoria, std::string descricao);

    // Destrutor
    virtual ~Transacao();

    // Getters e Setters
    int getIdTransacao() const;
    void setIdTransacao(int idTransacao);

    double getValor() const;
    void setValor(double valor);

    std::string getData() const;
    void setData(const std::string& data);

    std::string getTipo() const;
    void setTipo(const std::string& tipo);

    Categoria* getCategoria() const;
    void setCategoria(Categoria* categoria);

    std::string getDescricao() const;
    void setDescricao(const std::string& descricao);
};

#endif // TRANSACAO_H
