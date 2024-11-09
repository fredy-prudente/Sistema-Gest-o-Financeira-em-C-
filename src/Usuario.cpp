#include "Usuario.h"
#include <algorithm>

// Construtor
Usuario::Usuario(std::string nome, std::string email, std::string senha,
                 std::string endereco, std::string telefone, std::string dataCadastro)
    : nome(nome), email(email), senha(senha), endereco(endereco),
      telefone(telefone), dataCadastro(dataCadastro) {}

// Destrutor
Usuario::~Usuario() {
    for (auto conta : contas) {
        delete conta;
    }
}

// Métodos para gerenciar contas
void Usuario::adicionarConta(ContaBancaria* conta) {
    contas.push_back(conta);
}

void Usuario::removerConta(ContaBancaria* conta) {
    contas.erase(std::remove(contas.begin(), contas.end(), conta), contas.end());
}

std::vector<ContaBancaria*> Usuario::getContas() const {
    return contas;
}

// Getters e Setters
std::string Usuario::getNome() const {
    return nome;
}

void Usuario::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Usuario::getEmail() const {
    return email;
}

void Usuario::setEmail(const std::string& email) {
    this->email = email;
}

std::string Usuario::getSenha() const {
    return senha;
}

void Usuario::setSenha(const std::string& senha) {
    this->senha = senha;
}

std::string Usuario::getEndereco() const {
    return endereco;
}

void Usuario::setEndereco(const std::string& endereco) {
    this->endereco = endereco;
}

std::string Usuario::getTelefone() const {
    return telefone;
}

void Usuario::setTelefone(const std::string& telefone) {
    this->telefone = telefone;
}

std::string Usuario::getDataCadastro() const {
    return dataCadastro;
}

void Usuario::setDataCadastro(const std::string& dataCadastro) {
    this->dataCadastro = dataCadastro;
}
