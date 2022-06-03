#include <io_system/memory/alloc/system_paging/system_paging.h>
#include <io_system/memory/alloc/details/system_paging/iosys_memory_system_paging.h>

synapse_io_system_memory_alloc_model
synapse_io_system_memory_system_paging_initialize(int pAllocType)
{
	return __synapse_io_system_memory_system_paging_initialize(pAllocType);
}