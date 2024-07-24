#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

uint32_t read_uint32_from_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Fail to open file");
        exit(EXIT_FAILURE);
    }

    uint32_t number;
    if (fread(&number, sizeof(number), 1, file) != 1) {
        perror("Fail to read file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);

    return ntohl(number);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "USE: %s <filename1> <filename2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    uint32_t num1 = read_uint32_from_file(argv[1]);
    uint32_t num2 = read_uint32_from_file(argv[2]);
    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}
