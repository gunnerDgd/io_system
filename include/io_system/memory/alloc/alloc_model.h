#pragma once
#include <stdint.h>

typedef struct synapse_io_system_memory_alloc_model
{
	void*   entity;

	void* (*allocate)  (void*, void*, size_t); // Entity, Hint, Size
	void  (*deallocate)(void*, void*, size_t);
	void* (*resize)	   (void*, void*, size_t);
} synapse_io_system_memory_alloc_model;

#define synapse_io_system_memory_alloc_model_allocate(pEntity, pPointer, pSize)\
	pEntity.allocate(pEntity.entity, pPointer, pSize)

#define synapse_io_system_memory_alloc_model_deallocate(pEntity, pPointer, pSize)\
	pEntity.deallocate(pEntity.entity, pPointer, pSize)

#define synapse_io_system_memory_alloc_model_resize(pEntity, pPointer, pSize)\
	pEntity.resize(pEntity.entity, pPointer, pSize)