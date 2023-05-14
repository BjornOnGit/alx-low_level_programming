/**
 * file: 100-elf_header.c
 * author: Eze Francis
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
#include <elf.h>

/**
 * print_error - the function that prints an error message
 * @message: pointer to the variable that holds the message string
 * Return: void.
 */
void print_error(char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void print_elf_header(Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d%s\n", header->e_ident[EI_VERSION], header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
    printf("  OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header->e_type == ET_REL ? "REL (Relocatable file)" : (header->e_type == ET_EXEC ? "EXEC (Executable file)" : (header->e_type == ET_DYN ? "DYN (Shared object file)" : "UNKNOWN")));
    printf("  Entry point address:               %lx\n", header->e_entry);
    printf("\n");
}

/**
 * main - The entry point of the program
 * @argc: parameter of type int.
 * @argv: parameter of type char const *.
 * Return: int.
 */
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return (97);
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        print_error("Cannot open file");
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));

    if (bytes_read == -1)
    {
        print_error("Cannot read file");
    }

    if (bytes_read != sizeof(header) || header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 || header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
    {
        print_error("Not an ELF file");
    }

    print_elf_header(&header);

    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        return (100);
    }

    return (0);
}
