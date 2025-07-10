# 🐍 Snake

Clássico jogo da cobrinha (Snake), desenvolvido em **C**, rodando no terminal (CLI). O jogo utiliza caracteres para representar a cobra e o tabuleiro, permitindo movimentação via teclado e exibindo a pontuação.

---

## 📦 Tecnologias utilizadas

### Backend / Console

- **C (ANSI C)**: linguagem principal para lógica do jogo e manipulação do terminal
- **Biblioteca padrão stdio.h e stdlib.h**: leitura/escrita e controle do fluxo
- **Funções do tipo `system("cls")` ou `system("clear")`**: para limpar a tela e redesenhar o tabuleiro
- **Conceitos de delay**: para controlar a velocidade da cobra

---

## 🗂️ Estrutura do projeto

```
snake/
├── snake.c      # código-fonte principal do jogo
└── README.md
```

---

## ⚙️ Como compilar e rodar

### 🧪 Pré-requisitos

- **GCC** ou outro compilador C

---

### ▶️ Compilando e executando

No Windows (cmd ou PowerShell):

```bash
gcc snake.c -o snake.exe
./snake.exe
```

No Linux/macOS:

```bash
gcc snake.c -o snake
./snake
```

---

## 🧠 Decisões de arquitetura

- **Apenas um arquivo fonte (`snake.c`)**: concentra toda a lógica do jogo
- **Loop principal**: redesenha o tabuleiro a cada iteração, detecta colisões e processa entradas
- **Delay simples com `sleep` ou `for` vazio**: controla velocidade
- **Uso de `system("cls")` ou `system("clear")`** para limpar o terminal

---

## 📄 Licença

Projeto desenvolvido por Bernardo Alves. Livre para fins educacionais.

---

## 👤 Contato

Sinta-se à vontade para entrar em contato comigo:

- **LinkedIn:** [linkedin.com/in/bernardoalvesdev](https://linkedin.com/in/bernardoalvesdev)
- **E-mail:** bernardoalvesdev@gmail.com
- **Portfólio:** [https://www.bernardoalvesdev.com.br](https://www.bernardoalvesdev.com.br)
