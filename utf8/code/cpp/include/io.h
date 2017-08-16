#ifndef _UTF8_IO_H
#define _UTF8_IO_H

#include <cstdio>
#include "types.h"
#include "decode.h"

namespace utf8 {

  bytes *read_file(const char *filename) {
    FILE *f;
    f = fopen(filename, "rb");
    if (!f) {
      printf("File `%s` open failed.", filename);
      return nullptr;
    }

    auto data = new bytes();
    u8 b;
    while (fread(&b, BYTE_SIZE, 1, f)) {
      data->push_back(b);
    }
    return data;
  };

  codepoints *decode_file(const char *filename) {
    auto data = read_file(filename);
    if (!data) {
      return nullptr;
    }
    return decode(*data);
  };

}

#endif
