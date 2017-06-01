#include <stdio.h>



int main(int argc, char *argv[]){

FILE *file = fopen(argv[1], "r+b");

if(file == 0){
  printf("Could not open file\n");
  printf("Usage: frigate-skipper path/to/dol/file.dol\n");
}
else{

int firstOffset = 0x1FF1E;
int secondOffset = 0x1FF2A;


  fseek(file, firstOffset, SEEK_SET);
  unsigned char firstValue[] = {0x39, 0xF3};
  fwrite(firstValue, sizeof *firstValue, sizeof firstValue,  file);
  fseek(file, secondOffset, SEEK_SET);
  unsigned char secondValue[] = {0xDE, 0x28};
  fwrite(secondValue, sizeof *secondValue, sizeof secondValue,  file);
  //fputs(0xDE28, file);


   fclose(file);
    }
}
