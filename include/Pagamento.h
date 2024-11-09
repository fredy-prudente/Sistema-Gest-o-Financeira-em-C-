#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include "Transacao.h"
#include <string>

class Pagamento : public Transacao {
private:
    std::string formaPagamento;
    std::string beneficiario;
    std::string comprovante;

public:
    // Construtor
    Pagamento(int idTransacao, double valor, std::string data, std::string tipo,
              Categoria* categoria, std::string descricao, std::string formaPagamento,
              std::string beneficiario, std::string comprovante);

    // Getters e Setters
    std::string getFormaPagamento() const;
    void setFormaPagamento(const std::string& formaPagamento);

    std::string getBeneficiario() const;
    void setBeneficiario(const std::string& beneficiario);

    std::string getComprovante() const;
    void setComprovante(const std::string& comprovante);
};

#endif // PAGAMENTO_H
