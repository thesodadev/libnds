#include "ndstypes.h"
#include "system.h"
#include "bios.h"

int swiDecompressLZSSVram(void * source, void * destination, uint32 toGetSize, TDecompressionStream * stream) {

	if (isDSiMode()) {
		return swiDecompressLZSSVramTWL(source,destination,toGetSize,stream);
	} else {
		return swiDecompressLZSSVramNTR(source,destination,toGetSize,stream);
	}
	
}
