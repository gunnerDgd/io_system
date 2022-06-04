#pragma once
#include <stdint.h>

typedef struct synapse_iosys_base
{
	size_t(*read_from)		(void*, void*, size_t);
	size_t(*write_to)		(void*, void*, size_t);
	
	size_t(*pointer_current)(void*);
	size_t(*pointer_set)	(void*, size_t);

	void*   ptr_entity;
} synapse_iosys_base;

#define synapse_iosys_base_read_from(pBase, pBuffer, pSize)\
	pBase.read_from(pBase.ptr_entity, pBuffer, pSize)

#define synapse_iosys_base_write_to(pBase, pBuffer, pSize)\
	pBase.write_to (pBase.ptr_entity, pBuffer, pSize)

#define synapse_iosys_base_pointer_current(pBase)\
	pBase.pointer_current(pBase.ptr_entity)

#define synapse_iosys_base_pointer_set(pBase, pNewPointer)\
	pBase.pointer_set(pBase.ptr_entity, pNewPointer)