#pragma once
#include <io_system/interface/base.h>

typedef struct synapse_iosys_cached_base
{
	synapse_iosys_base* base_io_system;
	void			  * cache_entity  ;

	size_t			  (*cached_read)		 (struct synapse_iosys_cached_base*, void*, size_t);
	size_t			  (*cached_write)		 (struct synapse_iosys_cached_base*, void*, size_t);

	size_t			  (*cached_read_reserve) (struct synapse_iosys_cached_base*, size_t);
	size_t			  (*cached_write_reserve)(struct synapse_iosys_cached_base*, size_t);
} synapse_iosys_cached_base;

#define synapse_iosys_cached_base_cached_read(pEntity, pPointer, pSize)\
	pEntity.cached_read(&pEntity, pPointer, pSize)

#define synapse_iosys_cached_base_cached_write(pEntity, pPointer, pSize)\
	pEntity.cached_write(&pEntity, pPointer, pSize)

#define synapse_iosys_cached_base_cached_read_reserve(pEntity, pReserveSize, pReservePointer)\
	pEntity.cached_read_reserve(&pEntity, pReserveSize, pReservePointer)

#define synapse_iosys_cached_base_cached_write_reserve(pEntity, pReserveSize, pReservePointer)\
	pEntity.cached_write_reserve(&pEntity, pReserveSize, pReservePointer)