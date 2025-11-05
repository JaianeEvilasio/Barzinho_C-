# Cinestesia: Barzinho C++

Projeto acadêmico da disciplina de Estrutura de Dados e Orientação a Objetos (EDOO) do CIn-UFPE.

## Descrição Geral
O **Cinestesia** é um projeto desenvolvido em C++ para a disciplina de Estrutura de Dados e Orientação a Objetos, ministrada pelo professor Francisco Paulo Magalhães Simões, do curso de Sistemas de Informação do Centro de Informática da UFPE (CIn-UFPE).

O projeto consiste em um sistema em modo console para um "Barzinho", que apresenta um cardápio digital completo e funções de gerenciamento no estilo **CRUD (Create, Read, Update, Delete)**.

## Integrantes
* Clarissa Honório
* Jaiane Evilásio
* Lavinya Costa
* Luciano Paixão
* Marcos Silva

## Estrutura do Projeto 
```
Barzinho_C-/
    ├── Aperitivo.h
    ├── Barzinho.cpp
    ├── barzinho.db
    ├── barzinho.exe
    ├── Barzinho.h
    ├── Bebidas.h
    ├── Cliente.cpp
    ├── Cliente.h
    ├── main.cpp
    ├── Pedido.cpp
    ├── Pedido.h
    ├── Produto.h
    ├── programa.exe
    ├── README.md
    ├── sqlite3.c
    ├── sqlite3.h
    └── sqlite3.o
```

## Resultados
![Cardápio](https://github.com/user-attachments/assets/e49a6009-463b-402a-b802-094088b5863b)

![Pedido Adicionado](https://github.com/user-attachments/assets/b8073266-058d-4485-8403-c8733c3d1cf0)

## Arquitetura do Projeto
Este projeto implementa um sistema simples de pedidos para um bar (Barzinho), escrito em C++ e orientado a objetos. O núcleo é a classe `Barzinho`, que mantém o cardápio (produtos) e armazena pedidos finalizados. Produtos são modelados por uma hierarquia (`Produto` → `Bebidas` / `Aperitivo`). A aplicação é de console (CLI) e usa herança e polimorfismo para exibir itens.

### Componentes Principais

* **`Barzinho` (`Barzinho.h` / `Barzinho.cpp`)**
    * Mantém um cardápio (`Produto* cardapio[100]`) e uma lista de pedidos (`Pedido* pedidos[100]`).
    * Responsável por adicionar produtos, listar por categoria e armazenar pedidos.
    * Libera (`delete`) os objetos de cardápio e pedidos no destrutor — portanto, é o proprietário desses objetos.

* **`Produto` (`Produto.h`)**
    * Classe base com atributos `nome`, `preco` e `categoria`.
    * Define `virtual void mostrar()` para permitir polimorfismo.

* **`Bebidas`, `Aperitivo` (`Bebidas.h`, `Aperitivo.h`)**
    * Subclasses de `Produto` que sobrescrevem `mostrar()` e definem a categoria.

* **`Pedido` (`Pedido.h` / `Pedido.cpp`)**
    * Contém um `Cliente` (por valor) e um array de ponteiros `Produto* produtos[50]`.
    * Métodos: `adicionaProduto`, `mostrarpedido`, `calcularTotal` (declarado).
    * Não deleta os `Produto*` recebidos — portanto, não é proprietário dos produtos.

* **`Cliente` (`Cliente.h` / `Cliente.cpp`)**
    * Representa o cliente (`nome`).

* **`main.cpp`**
    * Popula o `Barzinho` com produtos (alocados com `new`), lê interações do usuário, cria pedidos (`new Pedido(...)`), adiciona produtos (referenciando ponteiros do cardápio) e registra pedidos no `Barzinho`.

### Uso do Banco de Dados SQLite

Para garantir a persistência dos dados, o SQLite foi utilizado para armazenar os pedidos realizados pelos clientes. O banco de dados `barzinho.db` contém duas tabelas principais:

1.  **Tabela `cardapio`:** Armazena os itens do cardápio, incluindo nome, preço e categoria (aperitivos ou bebidas).
2.  **Tabela `pedidos`:** Registra os pedidos feitos pelos clientes, com informações como nome do cliente, item pedido, quantidade e valor total.

O banco de dados foi integrado ao sistema de forma simples, com as tabelas sendo criadas automaticamente ao inicializar o sistema. Quando um pedido é finalizado, ele é armazenado na tabela `pedidos` do banco, permitindo que os dados sejam preservados para consultas futuras.

A escolha do SQLite se deu pela sua leveza e facilidade de integração, sendo ideal para a necessidade de persistência local do projeto.

## Conceitos Utilizados na Disciplina
* Linguagem C++
* **Programação Orientada a Objetos (POO)**
* **Polimorfismo e Herança**
* Estrutura **CRUD (Create, Read, Update, Delete)**

## Instruções de Execução
Para compilar e executar este projeto, você precisará de:

* **Kit de Compilação:** MinGW (ou MSVC) e SQlite

### Compilar: 
g++ barzinho.cpp -o barzinho
### Executar: 
./barzinho.exe

---

## Links relevantes
### Confira o video explicando nosso código: 
https://youtu.be/5Kg2RZTEyJk
### Para mais detalhes, confira também o relatório sobre o projeto:
https://1drv.ms/w/c/b6db38c16927f196/EaD8-IhdJGtNgK40-h-LNAgBaoIiGXXYDaNCMbn7NK4ofw?e=7ofHOe
