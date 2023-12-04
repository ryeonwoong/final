#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    FILE *s, *t;
    int c;

    s = fopen(argv[1], "r");
    if (s == NULL) {
        perror("Error opening source file");
        return 2;
    }

    t = fopen(argv[2], "w");
    if (t == NULL) {
        perror("Error opening destination file");
        fclose(s);
        return 3;
    }

    while ((c = fgetc(s)) != EOF) {
        fputc(c, t);
    }

    fclose(s);
    fclose(t);

    return 0;
}
