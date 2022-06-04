#pragma once
#include <io_system/interface/base.h>

typedef struct synapse_iosys_cached_base
{
	synapse_iosys_base* base_io_system; // Target I/O System for Caching.
	void			  * cache_entity  ; // I/O Caching System Entity

	size_t			  (*cached_read)		 (struct synapse_iosys_cached_base*, void*, size_t); // Read 
	size_t			  (*cached_write)		 (struct synapse_iosys_cached_base*, void*, size_t);

	size_t			  (*cached_read_reserve) (struct synapse_iosys_cached_base*, size_t); // Reserve File Context at Caching System
	size_t			  (*cached_write_reserve)(struct synapse_iosys_cached_base*, size_t); // Flushes Cached Context to I/O Context.
} synapse_iosys_cached_base;

/*
* Macros
* 
* synapse_iosys_cached_base_cached_read			 : Macro for synapse_iosys_cached_base::cached_read
* synapse_iosys_cached_base_cached_write		 : Macro for synapse_iosys_cached_base::cached_write
* synapse_iosys_cached_base_cached_read_reserve  : Macro for synapse_iosys_cached_base::cached_read_reserve
* synapse_iosys_cached_base_cached_write_reserve : Macro for synapse_iosys_cached_base::cached_write_reserve
*/

#define synapse_iosys_cached_base_cached_read(pEntity, pPointer, pSize)\
	pEntity.cached_read(&pEntity, pPointer, pSize)

#define synapse_iosys_cached_base_cached_write(pEntity, pPointer, pSize)\
	pEntity.cached_write(&pEntity, pPointer, pSize)

#define synapse_iosys_cached_base_cached_read_reserve(pEntity, pReserveSize, pReservePointer)\
	pEntity.cached_read_reserve(&pEntity, pReserveSize, pReservePointer)

#define synapse_iosys_cached_base_cached_write_reserve(pEntity, pReserveSize, pReservePointer)\
	pEntity.cached_write_reserve(&pEntity, pReserveSize, pReservePointer)