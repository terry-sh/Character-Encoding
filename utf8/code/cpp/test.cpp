#include <cstdio>
#include "include/types.h"
#include "include/decode.h"
#include "include/encode.h"
#include "include/io.h"
#include "include/validate.h"

int main(int argc, char **argv)
{
  auto cs = utf8::decode_file("utf8.txt");
  printf("Decoding:\n");
  for (auto &p : *cs)
  {
    printf("dec: %08u\thex: %06x\n", p, p);
  }
  // release dynamic memory
  delete cs;

  utf8::codepoints cp = { 72L, 19990L, 30028L, 131123L }; //'H', 世', '界', '𠀳';
  auto dc = utf8::encode(cp);
  printf("\nEncoding:\n");

  FILE *fw = fopen("write.tmp", "wb");
  for (auto &p : *dc) {
    printf("%u ", p);
    fwrite(&p, utf8::BYTE_SIZE, 1, fw);
  }
  printf("\n");
  fclose(fw);

  return 0;
}
