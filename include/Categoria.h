#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <vector>

class Categoria {
private:
    int idCategoria;
    std::string nome;
    std::string tipo; // receita ou despesa
    double orcamento;
    std::string descricao;
    bool ativo;
    std::vector<Categoria*> subcategorias;

public:
    // Construtor
    Categoria(int idCategoria, std::string nome, std::string tipo, double orcamento,
              std::string descricao, bool ativo);

    // Destrutor
    ~Categoria();

    // Métodos para gerenciar subcategorias
    void adicionarSubcategoria(Categoria* categoria);
    void removerSubcategoria(Categoria* categoria);
    std::vector<Categoria*> getSubcategorias() const;

    // Getters e Setters
    int getIdCategoria() const;
    void setIdCategoria(int idCategoria);

    std::string getNome() const;
    void setNome(const std::string& nome);

    std::string getTipo() const;
    void setTipo(const std::string& tipo);

    double getOrcamento() const;
    void setOrcamento(double orcamento);

    std::string getDescricao() const;
    void setDescricao(const std::string& descricao);

    bool isAtivo() const;
    void setAtivo(bool ativo);
};

#endif // CATEGORIA_H
