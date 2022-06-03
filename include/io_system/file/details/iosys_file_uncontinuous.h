#pragma once
#include <io_system/interface/base.h>
#include <io_system/memory/model.h>

typedef struct __synapse_iosys_file_uncontinuous_io_model
{
	void*									 io_entity	   ;
	synapse_iosys_uncontinuous_memory_model* io_read_cache ,
										   * io_write_cache;

	size_t									 io_pointer			    ,

											 io_read_cached		    ,
											 io_read_cached_pointer ,

											 io_write_cached		,
											 io_write_cached_pointer;
	
} __synapse_iosys_file_uncontinuous_io_model;

__synapse_iosys_file_uncontinuous_io_model*
__synapse_iosys_file_uncontinuous_io_model_initialize_open  (const char*, 
															 synapse_iosys_uncontinuous_memory_model*,
															 synapse_iosys_uncontinuous_memory_model*);

__synapse_iosys_file_uncontinuous_io_model*
__synapse_iosys_file_uncontinuous_io_model_initialize_create(const char*, 
															 synapse_iosys_uncontinuous_memory_model*,
															 synapse_iosys_uncontinuous_memory_model*);

void
__synapse_iosys_file_uncontinuous_io_model_cleanup			(__synapse_iosys_file_uncontinuous_io_model*);

size_t
__synapse_iosys_file_uncontinuous_io_model_read_from		(__synapse_iosys_file_uncontinuous_io_model*, uint8_t*, size_t);

size_t
__synapse_iosys_file_uncontinuous_io_model_write_to			(__synapse_iosys_file_uncontinuous_io_model*, uint8_t*, size_t);

size_t
__synapse_iosys_file_uncontinuous_io_model_caching_read_from(__synapse_iosys_file_uncontinuous_io_model*, size_t);

size_t
__synapse_iosys_file_uncontinuous_io_model_caching_write_to (__synapse_iosys_file_uncontinuous_io_model*, size_t);