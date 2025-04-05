# Jogo de Bocha em C

Este projeto implementa um jogo simples de **bocha** (ou bocce) entre duas equipes, desenvolvido em linguagem C. O objetivo é arremessar bolas tentando deixá-las o mais próximo possível do *bolim* (bola alvo).

---

## 🛠️ Como compilar

Para compilar o jogo, utilize o GCC ou outro compilador C:

```bash
gcc main.c -o bocha
```

---

## 🕹️ Como jogar

1. O bolim é posicionado aleatoriamente no campo (coordenadas X e Y).
2. Cada equipe (vermelha e azul) tem **duas jogadas alternadas**.
3. O jogador escolhe uma **força de lançamento** (inteiro).
4. A bola é lançada com base na força escolhida e um desvio aleatório.
5. A cada jogada, o campo é atualizado e exibido com as bolas posicionadas.
6. Após as 4 jogadas (2 por equipe), a bola mais próxima do bolim no eixo **Y** define a equipe vencedora.
7. O placar é exibido ao final da partida.

---

## 📅 Funcionalidades

- Campo representado em texto com coordenadas.
- Arremesso com força influenciando a distância.
- Bolas com identificadores exclusivos (`R1`, `A2`, etc).
- Visualização do campo a cada rodada.
- Cálculo de pontuação com base na proximidade do bolim.

---

## 📆 Exemplo de execução

```
Posição do bolim -> x: 4, y: 96
----------------------------------------------------------------

Vermelho: Escolha a força da jogada (ex: 35):
> 34

A bola R1, da equipe 1, está na posição [7][100].

[Campo exibido...]

Azul: Escolha a força da jogada (ex: 35):
> 36

A bola A1, da equipe 2, está na posição [15][96].

[Campo exibido...]

Equipe azul pontuou!

Placar final:
Vermelho: 0 ponto(s)
Azul: 1 ponto(s)
```

---

## 📁 Estrutura do projeto

- `main.c`: código principal do jogo com:
  - Definição de estruturas.
  - Geração de lançamentos aleatórios.
  - Impressão do campo.
  - Cálculo de pontuação.

---

## 📌 Observações

- O campo simula o eixo Y com escala de 3 em 3 para melhor visualização.
- O desvio aleatório imita a imprecisão do lançamento.
- Projeto didático, ideal para exercícios de lógica e manipulação de estruturas em C.

---




