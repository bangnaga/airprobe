
#ifndef __GSMSTACK_H__
#define __GSMSTACK_H__ 1

#ifdef __cplusplus
extern "C" {
#endif

#include "interleave.h"

typedef struct
{
	int flags;
	int fn;
	int bsic;
	char msg[23];	/* last decoded message */
	INTERLEAVE_CTX interleave_ctx;

	/* FIXME: later do this per each ts per each arfcn */
	unsigned char burst[4 * 58 * 2];
	int burst_count;
} GS_CTX;

int GS_new(GS_CTX *ctx);
int GS_process(GS_CTX *ctx, int ts, int type, char *data);

#ifdef __cplusplus
}
#endif

#endif
