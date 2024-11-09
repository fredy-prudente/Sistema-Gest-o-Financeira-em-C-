#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

#include <string>
#include "Transacao.h"

class Investimento : public Transacao {
private:
    std::string tipoInvestimento;
    std::string dataAplicacao;
    double rentabilidade;
    std::string prazo;

public:
    // Construtor
    Investimento(int idTransacao, double valor, std::string data, std::string tipo,
                 Categoria* categoria, std::string descricao, std::string tipoInvestimento,
                 std::string dataAplicacao, double rentabilidade, std::string prazo);

    // Métodos
    double calcularRetorno() const;

    // Getters e Setters
    std::string getTipoInvestimento() const;
    void setTipoInvestimento(const std::string& tipoInvestimento);

    std::string getDataAplicacao() const;
    void setDataAplicacao(const std::string& dataAplicacao);

    double getRentabilidade() const;
    void setRentabilidade(double rentabilidade);

    std::string getPrazo() const;
    void setPrazo(const std::string& prazo);
};

#endif // INVESTIMENTO_H
