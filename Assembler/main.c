#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "assembler.h"

/*
Main function accepts hack assembly file name as argument
*/

int main(int argc, char *argv[]) {
    if(argc >= 2) {
        FILE *infile;
        infile = fopen(argv[1], "r");
        size_t outlen;
        unsigned char *out;
        outlen = assemble(infile, &out);
        fclose(infile);

        FILE *outfile;
        char outfilename[64];
        char ext[8];
        sscanf(argv[1], "%[^.].%s", outfilename, ext);
        strcpy(ext, "hack");

        sprintf(outfilename, "%s.%s", outfilename, ext);
        outfile = fopen(outfilename, "w");

        output(outfile, out, outlen);
        fclose(outfile);
        free(out);
    }
}
