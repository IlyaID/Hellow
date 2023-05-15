#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


union data
  {
    uint64_t u64;
    uint8_t arr[8];
    uint32_t a32[2];
  };

void printBytes(union data x) {
for(int i=0;i<size;++i)
  printf("\nbyte[%d](%x)",i+1,p[i]);
printf("\n");
}

union data convertLittleToBig(union data x) {
  printf("\nCurrent representation\n");
  printBytes(in,sizeInBytes);
  for(int i=0;i<sizeInBytes;++i)
    out[i] = in[sizeInBytes-i-1];
  printf("\nRepresentation after conversion\n");
  printBytes(out,sizeInBytes);
}

int main() {
  union data little;
  printf("\nEnter a number that you wish to convert into big endian: ");
  int64_t inp;
  scanf("%"inp);
  little=inp;
  union data x big;
  convertLittleToBig((uint8_t*)&little,(uint8_t*)&big,sizeof(big));
}