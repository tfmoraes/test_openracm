#include <stdio.h>

#include "compressed_mesh.h"
#include "ooc_mesh.h"
#include "smreader_ply.h"

int main(int argc, const char *argv[])
{
	FILE* arq;
	SMreader_ply* smreader = new SMreader_ply;
	arq = fopen(argv[1], "r");
	smreader->open(arq, true, true);
	smreader->close();
	return 0;
}
