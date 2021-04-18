#include <stdio.h>
#include <stdlib.h>

char* get_contents(char const* path) {
  char* buffer = 0;
  long length = 0;
  FILE* f = fopen(path, "rb");

  if (f) {
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);

    buffer = (char *) malloc((length + 1) * sizeof(char));
    if (buffer) {
      fread(buffer, sizeof(char), length, f);
    }

    fclose(f);
  }

  buffer[length] = '\0';
  return buffer;
}

int main(int argc, char** argv) {
  for (int i = 0; i < argc; ++i)
    printf("%s", get_contents(argv[i]));

  return 0;
}
