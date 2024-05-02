#include <stdio.h>
#include <stdlib.h>

int N, K, pos, vagas = 0;
int pont[1000];

int main(void) {

  int i = 0;
  int j = 0;
  
  printf("Digite o número de competidores:\n");
  scanf("%d", &N);
  while (N < 1 || N > 1000)
    {
      printf("Valor digitado inválido...\n");
      printf("Digite o número de competidores novamente:\n");
      scanf("%d", &N);
    }
  
  printf("Digite o número de vagas:\n");
  scanf("%d", &K);
  while (K < 1 || K > N)
    {
      printf("Valor digitado inválido...\n");
      printf("Digite o número de vagas novamente:\n");
      scanf("%d", &K);
    }
  
  for(i = 1; i <= N; i++)
    {
      printf("\nDigite a pontuação do competidor %d:\n", i);
      scanf("%d", &pont[i]);      
    }

  //Colocando os dados em ordem crescente com insert sort
  
  int valmax = i;
  
  for(j = 1; j < valmax ; j++)
  {
    int chave = pont[j];
    i = j - 1;
    while ((i >= 0)&&(pont[i]>chave))
    {
      pont[i+1] = pont[i];
      i = i - 1;
    }
    pont[i+1] = chave;       
  }
  j = 0;

  for(j=1; j < valmax; j++)
    {
     // printf("\n%d", pont[j]);
    }

  // Ordem crescente finalizada!
  // Verificando quantos competidores ficaram em cada vaga
  
 pos = N - K;
 vagas = K;

  for(i = 1; i <= N; i++)
  {
    if (pont[pos] == pont[(pos+1)])
    {
      vagas++;
      pos--;
    }
    else if(pont[pos] != pont[pos+1])
    {
      break;
    }
  }
  system("clear");
   printf("\nO total de classificados é: %d", vagas);
  
  return 0;
}