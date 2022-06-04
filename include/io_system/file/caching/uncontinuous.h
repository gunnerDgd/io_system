#pragma once
#include <io_system/interface/cached_base.h>
#include <io_system/memory/uncontinuous_model.h>

synapse_iosys_cached_base*
synapse_iosys_file_caching_uncontinuous_initialize(synapse_iosys_base*, synapse_iosys_uncontinuous_memory_model*, synapse_iosys_uncontinuous_memory_model*);

void
synapse_iosys_file_caching_uncontinuous_cleanup   (synapse_iosys_cached_base*);

size_t
synapse_iosys_file_caching_uncontinuous_read_from		 (synapse_iosys_cached_base*, void*, size_t);

size_t
synapse_iosys_file_caching_uncontinuous_read_from_reserve(synapse_iosys_cached_base*, size_t);

size_t
synapse_iosys_file_caching_uncontinuous_write_to		 (synapse_iosys_cached_base*, void*, size_t);

size_t
synapse_iosys_file_caching_uncontinuous_write_to_reserve (synapse_iosys_cached_base*, size_t);