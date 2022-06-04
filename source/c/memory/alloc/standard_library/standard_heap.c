#include <io_system/memory/alloc/standard_library/standard_heap.h>
#include <io_system/memory/alloc/details/standard_library/iosys_memory_standard_heap.h>

#include <stdlib.h>

synapse_io_system_memory_alloc_model*
synapse_io_system_memory_standard_heap_initialize()
{
	synapse_io_system_memory_alloc_model* ptr_alloc =
		malloc(sizeof(synapse_io_system_memory_alloc_model));

	ptr_alloc->allocate   = &__synapse_iosys_memory_standard_heap_allocate  ;
	ptr_alloc->deallocate = &__synapse_iosys_memory_standard_heap_deallocate;
	ptr_alloc->resize     = &__synapse_iosys_memory_standard_heap_resize    ;

	return ptr_alloc;
}

void
synapse_io_system_memory_standard_heap_cleanup(synapse_io_system_memory_alloc_model* pMmodel)
{
	free(pMmodel);
}