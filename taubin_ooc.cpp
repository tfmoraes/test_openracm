#include <stdio.h>

#include "mem_manager.h"
#include "memory_map.h"
#include "compressed_mesh.h"
#include "vec3f.hpp"
#include "OutCorner.h"
#include "smreader_ply.h"
#include "smwriter_smc_cluster.h"
#include "smreader_smc_cluster.h"
#include "ooc_mesh.h"

int main(int argc, const char *argv[])
{
	int event, NumTriForCluster;
	FILE* arq;
	FILE* out;
	FILE* to_read;

	SMreader_ply* smreader = new SMreader_ply;
	SMwriter_smc_cluster* cluster_writer = new SMwriter_smc_cluster;
	SMreader_smc_cluster* ooc_reader = new SMreader_smc_cluster;
	COoCMesh * mesh = new COoCMesh;

	NumTriForCluster = 200;

	arq = fopen(argv[1], "r");
	smreader->open(arq, true, false);

	out = fopen("/tmp/data.smc_cluster", "wb");
	cluster_writer->open(out);
	cluster_writer->m_OOCC.PrepareClusters(smreader->nverts, smreader->nfaces, NumTriForCluster);
	cluster_writer->m_GraNumTriInCluster = NumTriForCluster;
	cluster_writer->set_boundingbox(smreader->bb_min_f, smreader->bb_max_f);

	while (event = smreader->read_element()) {
		switch (event) {
		case SM_VERTEX:
			cluster_writer->write_vertex(smreader->v_pos_f);
			break;		
		case SM_TRIANGLE:
			cluster_writer->write_triangle(smreader->t_idx, smreader->t_final);
			break;
		case SM_FINALIZED:
			cluster_writer->write_finalized(smreader->final_idx);
			printf("finalized\n");
			break;
		default:
			break;
		}
	}

	cluster_writer->m_OOCC.Save("/tmp/meta.h");
	smreader->close();
	cluster_writer->close();

	printf("\n\n\n\n\n");

	mesh->PrepareData("/tmp", true);
	printf("Numero de faces %d", mesh->GetNumFaces());
	mesh->GetTri(0);

	return 0;
}
