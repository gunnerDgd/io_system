#include "basic_operation.h"

int main()
{
	synapse_iosys_base		  *pIoSys		= tstcase_synapse_iosys_file_native_open	   ()	   ;
	synapse_iosys_cached_base *pIoSysCached = tstcase_synapse_iosys_file_native_cached_open(pIoSys);
	
	synapse_iosys_cached_base_cached_write((*pIoSysCached), "Hello World\n", 12);
	synapse_iosys_cached_base_cached_write((*pIoSysCached), "Hello World\n", 12);
	synapse_iosys_cached_base_cached_write((*pIoSysCached), "Hello World\n", 12);
	synapse_iosys_cached_base_cached_write((*pIoSysCached), "Hello World\n", 12);
	synapse_iosys_cached_base_cached_write((*pIoSysCached), "Hello World\n", 12);
	synapse_iosys_cached_base_cached_write((*pIoSysCached), "Hello World\n", 12);
	synapse_iosys_cached_base_cached_write((*pIoSysCached), "Hello World\n", 12);
	synapse_iosys_cached_base_cached_write((*pIoSysCached), "Hello World\n", 12);

	tstcase_synapse_iosys_file_native_write_to(pIoSysCached);
}