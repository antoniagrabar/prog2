#include <stdio.h>
#include <string.h>
#include <ctype.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


const char boje[6][20]={"Bijela","Crvena","Narancasta","Plava","Zelena","Zuta"};

void check_colors(char (*kocka)[3][3]){

  int i,j,k;
  int slozena_kockica=1;

  for ( i = 0; i < 6; i++){
    int slozena_stranica=1;

    for(j=0;j<3;j++){

      for(k=0;k<3;k++){

        if (*(*(*(kocka+i)+j)+k) != *(*(*(kocka+i)+1)+1)){

            slozena_stranica=0;
            slozena_kockica=0;
        }
      }
    }

    if(!slozena_stranica){
      printf("%s\n",boje[i]);
    }
    
  }

  if(slozena_kockica){
    printf("Kocka je slozena\n");
  }
}



int main(){

  char polje[6][3][3];
  int i,j,k;

  for ( i = 0; i < 6; i++){
    for(j=0;j<3;j++){
      for(k=0;k<3;k++){
        scanf(" %c",&polje[i][j][k]);
      }
    }
  }

  check_colors(polje);

  return 0;
}
