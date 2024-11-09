#ifndef RELATORIO_H
#define RELATORIO_H

#include <string>
#include <vector>
#include "Transacao.h"

class Relatorio {
private:
    int idRelatorio;
    std::string tipoRelatorio;
    std::string periodo;
    std::string dataGeracao;
    double totalReceitas;
    double totalDespesas;
    std::vector<Transacao*> transacoes;

public:
    // Construtor
    Relatorio(int idRelatorio, std::string tipoRelatorio, std::string periodo,
              std::string dataGeracao);

    // Destrutor
    ~Relatorio();

    // Métodos
    void gerarRelatorio(const std::vector<Transacao*>& transacoes);
    void exibirRelatorio() const;

    // Getters e Setters
    int getIdRelatorio() const;
    void setIdRelatorio(int idRelatorio);

    std::string getTipoRelatorio() const;
    void setTipoRelatorio(const std::string& tipoRelatorio);

    std::string getPeriodo() const;
    void setPeriodo(const std::string& periodo);

    std::string getDataGeracao() const;
    void setDataGeracao(const std::string& dataGeracao);

    double getTotalReceitas() const;
    void setTotalReceitas(double totalReceitas);

    double getTotalDespesas() const;
    void setTotalDespesas(double totalDespesas);

    std::vector<Transacao*> getTransacoes() const;
    void setTransacoes(const std::vector<Transacao*>& transacoes);
};

#endif // RELATORIO_H
