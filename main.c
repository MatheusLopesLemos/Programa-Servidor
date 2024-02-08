

#include <stdio.h>
#include <stdlib.h>

#define l 24
#define c 7

int main() {
  int i, j;
  float temperatura[l][c] = {
      {46, 44, 45, 49, 59, 46, 43}, {49, 43, 42, 56, 59, 48, 47},
      {63, 42, 48, 58, 59, 45, 48}, {46, 48, 49, 59, 59, 49, 49},
      {48, 49, 56, 59, 59, 51, 51}, {45, 70, 57, 49, 59, 49, 59},
      {44, 41, 45, 49, 52, 46, 63}, {46, 44, 45, 49, 59, 46, 43},
      {49, 43, 42, 56, 59, 48, 47}, {63, 42, 48, 58, 59, 45, 48},
      {46, 48, 49, 59, 59, 49, 49}, {48, 49, 56, 59, 59, 51, 51},
      {45, 70, 57, 49, 59, 49, 59}, {44, 41, 45, 49, 52, 46, 63},
      {46, 44, 45, 49, 59, 46, 43}, {49, 43, 42, 56, 59, 48, 47},
      {63, 42, 48, 58, 59, 45, 48}, {46, 48, 49, 59, 59, 49, 49},
      {48, 49, 56, 59, 59, 51, 51}, {45, 70, 57, 49, 59, 49, 59},
      {44, 41, 45, 49, 52, 46, 63}, {48, 49, 56, 59, 59, 51, 51},
      {43, 44, 44, 45, 46, 46, 47}, {46, 44, 45, 49, 59, 46, 43}};
  float tempServMedia[c] = {0};
  float somaCalculoMediaTempHora = 0;
  float mediaTempHora = 0;
  float maxTempHora = 0;
  float minTempHora = 0;
  float somaCalculoMediaTempServ = 0;
  float mediaTempServ = 0;
  float maiorDiferencaTemp = 0;
  int horaMaiorVariacaoTemp = 0;
  float mediaHora[l] = {0};
  float mediaHoraMenosTemp = 0;

  system("clear"); // limpa a tela

  printf("******** TABELA DE TEMPERATURAS *******\n\n");
  // imprimindo a matriz
  printf("HORA\tSERV0\tSERV1\tSERV2\tSERV3\tSERV4\tSERV5\tSERV6\n");
  for (i = 0; i < l; i++) {
    printf(" %dh:\t", i);
    for (j = 0; j < c; j++) {
      printf(" %.1f\t", temperatura[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");

  printf("******** CALCULO DE TEMPERATURAS *******\n\n");

  for (int i = 0; i < l; i++) {
    printf("Hora %i:\n", i);
    somaCalculoMediaTempHora = 0;
    maxTempHora = 0;
    minTempHora = 0;
    for (int j = 0; j < c; j++) {
      somaCalculoMediaTempHora += temperatura[i][j];
      if (maxTempHora < temperatura[i][j]) {
        maxTempHora = temperatura[i][j];
      }

      if (minTempHora == 0) {
        minTempHora = temperatura[i][j];
      } else {
        if (minTempHora > temperatura[i][j]) {
          minTempHora = temperatura[i][j];
        }
      }
    }
    mediaTempHora = somaCalculoMediaTempHora / 7;
    mediaHora[i] = mediaTempHora;
    printf("Média: %.2f, Maxima: %.2f, Minima: %.2f", mediaTempHora, maxTempHora, minTempHora);
    printf("\n \n");
  }

  printf("******** TEMPERATURA MÉDIA DOS SERVIDORES *******\n\n");
  // Lembre de usar o vetor tempServMedia
  for (int i = 0; i < c; i++) {
    somaCalculoMediaTempServ = 0;
    mediaTempServ = 0;
    for (int j = 0; j < l; j++) {
      somaCalculoMediaTempServ += temperatura[j][i];
      mediaTempServ = somaCalculoMediaTempServ / 24;
      tempServMedia[i] = mediaTempServ;
    }
    printf("SERV%d= %.2f\n", i, mediaTempServ);
  }
  printf("\n");

  printf("********TABELA DE TEMPERATURAS C/ TEMPS ACIMA DA MEDIA*******\n\n");
  // Seu código aqui.
  /* Você deve imprimir a tabela da mesma forma que eu fiz lá em cima.
  Só que dessa vez se uma temperatura de servidor estiver acima da média dele
  você deve imprimir um asterisco (*) ao lado dela */

  printf("HORA\tSERV0\tSERV1\tSERV2\tSERV3\tSERV4\tSERV5\tSERV6\n");
  for (int i = 0; i < l; i++) {
    printf(" %dh:\t", i);
    for (int j = 0; j < c; j++) {
      if (temperatura[i][j] > (tempServMedia[j] + 3)) {
        printf(" %.1f**\t", temperatura[i][j]);
      } else {
        if (temperatura[i][j] > tempServMedia[j]) {
          printf(" %.1f*\t", temperatura[i][j]);
        } else {
          printf(" %.1f\t", temperatura[i][j]);
        }
      }
    }
    printf("\n");
  }
  printf("\n \n");
  printf("********HORÁRIO COM MAIOR TEMPERATURA*******\n\n");

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      mediaHoraMenosTemp = mediaHora[i] - temperatura[i][j];
      if (mediaHoraMenosTemp < 0) {
        mediaHoraMenosTemp = mediaHoraMenosTemp * -1;
      }

      if (mediaHoraMenosTemp > maiorDiferencaTemp) {
        maiorDiferencaTemp = mediaHoraMenosTemp;
        horaMaiorVariacaoTemp = i;
      }
    }
  }

  printf("O horário com maior diferença de temperatura é: %ih", horaMaiorVariacaoTemp);

  return 0;
}
