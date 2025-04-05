#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LARGURA 20
#define ALTURA 34  // cada linha representa y = 3 * índice de linha (até 99)

// Estrutura das bolas
typedef struct {
    int collor;  // 1: vermelho, 2: azul
    int x;
    int y;
    char id[16];
} Ball;

// Funções auxiliares

//Posição do bolim no eixo X
int defineBolimX() {
    return 1 + (rand() % LARGURA);
}

//Posição do bolim no eixo Y
int defineBolimY() {
    return 3 * (1 + (rand() % ALTURA));
}

//O que define a posição da bola jogada no eixo X (jogador não tem controle)
int throwBallX() {
    return 1 + (rand() % LARGURA);
}

//O que define a posição da bola jogada no eixo Y (jogador tem certo controle, mas não é totalmente determinístico)
int throwBallY(int force){
    int base = force * 3;
    int desvio = (rand() % 11) - 5;  // variação entre -5 e +5
    int final = base + desvio;

    if (final > 100) final = 100;
    if (final < 0) final = 0;

    return final;
}

// Mostra informações da bola
void showBall(Ball ball[], int i) {
    printf("A bola %s, da equipe %i, esta na posicao [%i][%i].\n",
           ball[i].id, ball[i].collor, ball[i].x, ball[i].y);
}

// Exibe o campo com bolas e bolim
void exibirCampo(Ball ball[], int num_bolas, int bX, int bY) {
    char campo[ALTURA][LARGURA][4];
    for (int i = 0; i < ALTURA; i++)
        for (int j = 0; j < LARGURA; j++)
            strcpy(campo[i][j], ".");

    int linha_bolim = (bY / 3) - 1;
    if (linha_bolim >= 0 && linha_bolim < ALTURA && bX >= 1 && bX <= LARGURA)
        strcpy(campo[linha_bolim][bX - 1], "B");

    for (int i = 0; i < num_bolas; i++) {
        int linha = (ball[i].y / 3) - 1;
        int coluna = ball[i].x - 1;

        if (linha >= 0 && linha < ALTURA && coluna >= 0 && coluna < LARGURA) {
            strncpy(campo[linha][coluna], ball[i].id, 3);
        }
    }

    printf("\nCAMPO DE JOGO:\n\n");
    for (int i = ALTURA - 1; i >= 0; i--) {
        printf("%3d | ", (i + 1) * 3);
        for (int j = 0; j < LARGURA; j++) {
            printf("%3s", campo[i][j]);
        }
        printf("\n");
    }
    printf("     +------------------------------------------------------------->\n");
    printf("       ");
    for (int j = 1; j <= LARGURA; j++) printf("%2d", j % 10);
    printf("  (X)\n\n");
}

// Retorna o valor mais próximo do bolim e define o time que chegou mais perto
int bolaMaisProxima(Ball ball[], int alvo, char eixo, int* team) {
    int menor = 100;
    int valorProximo = 0;

    for (int i = 0; i < 4; i++) {
        int valor = (eixo == 'x') ? ball[i].x : ball[i].y;
        int dist = abs(valor - alvo);
        if (dist < menor) {
            menor = dist;
            valorProximo = valor;
            *team = ball[i].collor;
        }
    }
    for (int i = 4; i < 8; i++) {
        int valor = (eixo == 'x') ? ball[i].x : ball[i].y;
        int dist = abs(valor - alvo);
        if (dist < menor) {
            menor = dist;
            valorProximo = valor;
            *team = ball[i].collor;
        }
    }
    return valorProximo;
}

int main() {
    int force, bX, bY, i;
    Ball ball[4];
    int pts;
    int pontosVermelho = 0, pontosAzul = 0;
    int contR = 1, contA = 1;

    srand(time(NULL));  // inicializa aleatoriedade

    bX = defineBolimX();
    bY = defineBolimY();

    printf("Posicao do bolim -> x: %i, y: %i\n", bX, bY);
    printf("----------------------------------------------------------------\n");

    for (i = 0; i < 2; i++) {
        printf("\nVermelho: Escolha a forca da jogada (ex: 38 eh o maximo):\n");
        scanf("%i", &force);

        ball[i * 2].x = throwBallX();
        ball[i * 2].y = throwBallY(force);
        ball[i * 2].collor = 1;
        snprintf(ball[i * 2].id, sizeof(ball[i * 2].id), "V%d", contR++);

        showBall(ball, i * 2);
        exibirCampo(ball, i * 2 + 1, bX, bY);

        printf("\nAzul: Escolha a forca da jogada (ex: 38 eh o maximo):\n");
        scanf("%i", &force);

        ball[i * 2 + 1].x = throwBallX();
        ball[i * 2 + 1].y = throwBallY(force);
        ball[i * 2 + 1].collor = 2;
        snprintf(ball[i * 2 + 1].id, sizeof(ball[i * 2 + 1].id), "A%d", contA++);

        showBall(ball, i * 2 + 1);
        exibirCampo(ball, i * 2 + 2, bX, bY);
    }

    int teamY;
    bolaMaisProxima(ball, bY, 'y', &teamY);

    if (teamY == 1) {
        printf("\nEquipe vermelha pontuou!\n");
        pontosVermelho++;
    } else {
        printf("\nEquipe azul pontuou!\n");
        pontosAzul++;
    }

    printf("\nPlacar final:\n");
    printf("Vermelho: %d ponto(s)\n", pontosVermelho);
    printf("Azul: %d ponto(s)\n", pontosAzul);

    return 0;
}
