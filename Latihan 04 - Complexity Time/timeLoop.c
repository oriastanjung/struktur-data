#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void process(long i,...){
  va_list arg; // b , c, d
  
  long a[] = {0,0,0,0,0,0,0,0,0};

  va_start(arg , i); // baca si arg ==> b , c, d

  a[0] = i; // arg pertama itu a, isi dijadiin i

  for(int index = 1; index < 9 ; index++){
    a[index] = va_arg(arg,long);
  }
  
  for (int index = 0; index < 9; index++){
    if(a[index] == 0){
      break;
    }else{
      printf("loop %d sebesar %ld\n", index+1,a[index]);
    }
  }
  
  va_end(arg);
  for (int j = 1; j < a[0]; j++){
    for(int k = 1; k < a[1]; k++){
      for(int l = 1; l < a[2]; l++){
        for(int m = 1; m < a[3]; m++){
          printf("%s","");
        }
      }
    }
  }
}

int main() {
  long a = 10;
  long b = 20;
  long c = 30;
  long d = 30;

  clock_t mulai, selesai;
  
  mulai = clock();
  process(a,b,c,d,NULL);
  selesai = clock();
  printf("Waktu yang diperlukan ialah %.9f\n",(double)(selesai-mulai));
  return 0; 
}