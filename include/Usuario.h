#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "ContaBancaria.h"

class Usuario {
private:
    std::string nome;
    std::string email;
    std::string senha;
    std::string endereco;
    std::string telefone;
    std::string dataCadastro;
    std::vector<ContaBancaria*> contas;

public:
    // Construtor
    Usuario(std::string nome, std::string email, std::string senha,
            std::string endereco, std::string telefone, std::string dataCadastro);

    // Destrutor
    ~Usuario();

    // Métodos para gerenciar contas
    void adicionarConta(ContaBancaria* conta);
    void removerConta(ContaBancaria* conta);
    std::vector<ContaBancaria*> getContas() const;

    // Getters e Setters
    std::string getNome() const;
    void setNome(const std::string& nome);

    std::string getEmail() const;
    void setEmail(const std::string& email);

    std::string getSenha() const;
    void setSenha(const std::string& senha);

    std::string getEndereco() const;
    void setEndereco(const std::string& endereco);

    std::string getTelefone() const;
    void setTelefone(const std::string& telefone);

    std::string getDataCadastro() const;
    void setDataCadastro(const std::string& dataCadastro);
};

#endif // USUARIO_H
