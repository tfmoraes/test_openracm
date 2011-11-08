#include <stdio.h>

#include "mem_manager.h"
#include "memory_map.h"
#include "compressed_mesh.h"
#include "vec3f.hpp"
#include "OutCorner.h"
#include "smreader_ply.h"
#include "ooc_mesh.h"

int main(int argc, const char *argv[])
{
	int event;
	FILE* arq;
	SMreader_ply* smreader = new SMreader_ply;
	COoCMesh* mesh = new COoCMesh;
	arq = fopen(argv[1], "r");
	smreader->open(arq, false, false);
	
	while (event = smreader->read_element()) {
		switch (event) {
		case SM_VERTEX:
			printf("vertex");
			break;		
		case SM_TRIANGLE:
			printf("triangle");
			break;
		case SM_FINALIZED:
			printf("finalized");
			break;
		default:
			break;
		}
	}
	
	smreader->close();
	return 0;
}
