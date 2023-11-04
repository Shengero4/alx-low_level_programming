#include "main.h"
#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void display_error(char *message) {
    dprintf(STDERR_FILENO, "Error: %s\n", message);
    exit(98);
}

void display_elf_header(const char *filename) {
    int fd;
    Elf64_Ehdr elf_header;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        display_error("Cannot open ELF file");
    }

    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        close(fd);
        display_error("Cannot read ELF header");
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        close(fd);
        display_error("Not an ELF file");
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf(" %02x", elf_header.e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             %s\n",
           elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
           (elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "Unknown"));

    printf("  Data:                              %s\n",
           elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           (elf_header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Unknown"));

    printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);

    printf("  OS/ABI:                            %s\n",
           elf_header.e_ident[EI_OSABI] == ELFOSABI_NONE ? "UNIX - System V" :
           (elf_header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" : "Unknown"));

    printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);

    printf("  Type:                              %s\n",
           elf_header.e_type == ET_NONE ? "NONE (None)" :
           (elf_header.e_type == ET_REL ? "REL (Relocatable file)" :
           (elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" :
           (elf_header.e_type == ET_DYN ? "DYN (Shared object file)" :
           (elf_header.e_type == ET_CORE ? "CORE (Core file)" : "Unknown")))));

    printf("  Entry point address:               %#lx\n", elf_header.e_entry);

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_error("Usage: elf_header elf_filename");
    }

    display_elf_header(argv[1]);

    return 0;
}

