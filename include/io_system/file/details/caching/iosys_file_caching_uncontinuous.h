#pragma once
#include <io_system/interface/base.h>
#include <io_system/interface/cached_base.h>

#include <io_system/memory/uncontinuous_model.h>

typedef struct __synapse_iosys_file_caching_uncontinuous
{
	synapse_iosys_uncontinuous_memory_model* io_read_cache ,
										   * io_write_cache;

	size_t									 io_read_pointer		,
											 io_write_pointer		,
		 
											 io_read_cached		    , // Size of Cached Readable Data in Memory.
											 io_read_cached_pointer , // Actual Pointer of Cached Readable Data.

											 io_write_cached		,
											 io_write_cached_pointer;
	
} __synapse_iosys_file_caching_uncontinuous;

__synapse_iosys_file_caching_uncontinuous*
__synapse_iosys_file_caching_uncontinuous_initialize(synapse_iosys_uncontinuous_memory_model*,
													 synapse_iosys_uncontinuous_memory_model*);

void
__synapse_iosys_file_caching_uncontinuous_cleanup		   (synapse_iosys_base*, __synapse_iosys_file_caching_uncontinuous*);

size_t
__synapse_iosys_file_caching_uncontinuous_read_from		   (synapse_iosys_base*, __synapse_iosys_file_caching_uncontinuous*, uint8_t*, size_t);

size_t
__synapse_iosys_file_caching_uncontinuous_write_to		   (synapse_iosys_base*, __synapse_iosys_file_caching_uncontinuous*, uint8_t*, size_t);

size_t
__synapse_iosys_file_caching_uncontinuous_caching_read_from(synapse_iosys_base*, __synapse_iosys_file_caching_uncontinuous*, size_t);

size_t
__synapse_iosys_file_caching_uncontinuous_caching_write_to (synapse_iosys_base*, __synapse_iosys_file_caching_uncontinuous*, size_t);