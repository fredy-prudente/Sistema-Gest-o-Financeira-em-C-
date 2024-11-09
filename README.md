# Sistema Financeiro em C++

## Descrição

Este é um projeto de um **sistema financeiro** desenvolvido em C++ que implementa conceitos de **Programação Orientada a Objetos (POO)**. O sistema permite gerenciar:

- **Usuários**
- **Contas Bancárias**
- **Transações**
- **Categorias**
- **Orçamentos**
- **Investimentos**
- **Empréstimos**
- **Faturas**

O objetivo do projeto é demonstrar a interligação entre classes e a aplicação de POO em um contexto prático, oferecendo funcionalidades básicas de um sistema financeiro pessoal.

---

## Pré-requisitos

- **Compilador C++**: Necessário um compilador compatível com C++11 ou superior. Exemplos:
  - **GCC** (g++): versão 5.0 ou superior.
  - **Clang**: versão 3.3 ou superior.
  - **Visual Studio**: versão 2015 ou superior.

- **Sistema Operacional**: O código é multiplataforma e pode ser compilado em sistemas **Windows**, **Linux** ou **macOS**.

---

## Compilação e Execução

### Compilação via Linha de Comando

1. **Clone o repositório** ou baixe os arquivos do projeto.

2. **Navegue até o diretório raiz** do projeto `sistema_financeiro/`:

   ```bash
   cd caminho/para/sistema_financeiro
3. **Compile o programa utilizando o seguinte comando:**
    ```bash
    g++ main.cpp src/*.cpp -I include -o sistema_financeiro
    ```

### Compilação no Windows com MinGW

Se estiver utilizando o MinGW no Windows, o comando é similar:

    g++ main.cpp src/*.cpp -I include -o sistema_financeiro.exe

Execução

Após a compilação bem-sucedida, execute o programa:

    sistema_financeiro.exe
## Uso do Programa

O programa apresenta um menu principal com as seguintes opções:

    Cadastrar Usuário
    Adicionar Conta Bancária
    Registrar Transação
    Consultar Saldo
    Gerar Relatório
    Definir Orçamento
    Gerenciar Investimentos
    Administrar Empréstimos
    Visualizar Fatura
    Sair

## Observações Importantes

  **Entradas Sem Acentos:** Devido a questões de codificação de caracteres, insira textos sem acentos e sem caracteres especiais.

  **Tipos de Transação:** Ao registrar uma transação, insira debito ou credito (sem acentos) no campo "Tipo".

  **Codificação no Windows:** Se caracteres acentuados aparecerem de forma estranha no console do Windows, é devido à codificação. Para uma solução rápida, evite o uso de acentos.

  **Gerenciamento de Memória:** O programa utiliza alocação dinâmica de memória. Todos os objetos alocados são liberados antes do encerramento do programa para evitar vazamentos de memória.

## Agradecimentos
A grande equipe:
- Fredy Prudente
- José Vinicius
- Luca Guerreiro
- Nilo Fraga
- Luciano
### Além do Big professor:
- Fausto Bernard
  
Agradeço a todos que contribuíram direta ou indiretamente para o desenvolvimento deste projeto.
