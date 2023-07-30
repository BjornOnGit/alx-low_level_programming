#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void display_elf_header(const char* filename) {
    int fd = open(filename, O_RDONLY);
    Elf64_Ehdr elf_header;
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(98);
    }
    
    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        fprintf(stderr, "Error reading ELF header\n");
        exit(98);
    }
    
    /*Display the information contained in the ELF header*/
    printf("Magic: %02x %02x %02x %02x\n", elf_header.e_ident[EI_MAG0], elf_header.e_ident[EI_MAG1], elf_header.e_ident[EI_MAG2], elf_header.e_ident[EI_MAG3]);
    printf("Class: %d\n", elf_header.e_ident[EI_CLASS]);
    printf("Data: %d\n", elf_header.e_ident[EI_DATA]);
    printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);
    printf("OS/ABI: %d\n", elf_header.e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("Type: %d\n", elf_header.e_type);
    printf("Entry point address: %lx\n", elf_header.e_entry);
    
    close(fd);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: elf_header elf_filename\n");
        exit(1);
    }
    
    display_elf_header(argv[1]);
    
    return 0;
}