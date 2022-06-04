#pragma once
#include <io_system/file/native/native.h>
#include <io_system/file/caching/uncontinuous.h>
#include <io_system/memory/alloc/standard_library/standard_heap.h>

synapse_iosys_base* 
tstcase_synapse_iosys_file_native_open()
{
	return synapse_iosys_file_native_initialize_create_new("test.txt");
}

void tstcase_synapse_iosys_file_native_write_to(synapse_iosys_base* pIoSys)
{
	synapse_iosys_base_write_to((*pIoSys), "Hello World", 11);
}

synapse_iosys_cached_base*
tstcase_synapse_iosys_file_native_cached_open(synapse_iosys_base* pIoSys)
{
	synapse_iosys_cached_base* ptr_cache
		= synapse_iosys_file_caching_uncontinuous_initialize(pIoSys, synapse_io_system_memory_standard_heap_initialize(), synapse_io_system_memory_standard_heap_initialize());

	return ptr_cache;
}