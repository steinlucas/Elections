#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  int candidatoA = 0, candidatoB = 0, candidatoC = 0, votoNulo = 0, votoBranco = 0, voto = 0, vTotais = 0, classificacao[4], verEmpate = 0;
  char nomes[4];

  printf("Vote: ");
  scanf("%d", &voto);

  while (voto != 6){
    switch(voto){
      case 1:
        candidatoA++;
        vTotais++;
      break;

      case 2:
        candidatoB++;
        vTotais++;
      break;

      case 3:
        candidatoC++;
        vTotais++;
      break;

      case 4:
        votoNulo++;
        vTotais++;
      break;

      case 5:
        votoBranco++;
        vTotais++;
      break;

      default:
        printf("Insira um voto válido\n");
    };

    printf("Vote: ");
    scanf("%d", &voto);
  }

  printf("\nVotos totais: %d\n", vTotais);
  printf("Votos para o candidato A: %d\n", candidatoA);
  printf("Votos para o candidato B: %d\n", candidatoB);
  printf("Votos para o candidado C: %d\n", candidatoC);
  printf("Percentual de votos brancos: %d%%\n", 100/vTotais*votoBranco);
  printf("Percentual de votos nulos: %d%%\n", 100/vTotais*votoNulo);

  for (int i = 0; i < 1; i++){
    if (candidatoA > candidatoB && candidatoA > candidatoC){
      // A está na frente
      nomes[i] = 'A';
      classificacao[i] = candidatoA;
    } else {
      if (candidatoB > candidatoA && candidatoB > candidatoC){
        // B está na frente
        nomes[i] = 'B';
        classificacao[i] = candidatoB;
      } else {
        if (candidatoC > candidatoA && candidatoC > candidatoB){
          // C está na frente
          nomes[i] = 'C';
          classificacao[i] = candidatoC;
        } else {
          if (candidatoA == candidatoB){
            verEmpate = 1;
          } else {
            if (candidatoA == candidatoC){
              verEmpate = 1;
            } else {
              if (candidatoB == candidatoC){
                verEmpate = 1;
              }
            }
          }
        }
      }
    }
    if (verEmpate != 1){
      printf("Vencedor: candidato %c com %d votos\n", nomes[i], classificacao[i]);
    } else {
      printf("Houve um empate.");
    }
  }
}