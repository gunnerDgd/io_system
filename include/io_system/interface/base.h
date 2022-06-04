#pragma once
#include <stdint.h>

typedef struct synapse_iosys_base
{
	size_t(*read_from)		(void*, void*, size_t); // Reads Data From I/O Entity (void* ptr_entity).
	size_t(*write_to)		(void*, void*, size_t); // Writes Data to I/O Entity  (void* ptr_entity).
	
	size_t(*pointer_current)(void*);				// Retrieves I/O Pointer
	size_t(*pointer_set)	(void*, size_t);		// Get I/O Pointer

	void*   ptr_entity;
} synapse_iosys_base;

/*
* Macros
* 
* synapse_iosys_base_read_from		 : Macro for synapse_iosys_base::read_from
* synapse_iosys_base_write_to		 : Macro for synapse_iosys_base::write_to
* synapse_iosys_base_pointer_current : Macro for synapse_iosys_base::pointer_current
* synapse_iosys_base_pointer_set     : Macro for synapse_iosys_base::pointer_set
*/

#define synapse_iosys_base_read_from(pBase, pBuffer, pSize)\
	pBase.read_from(pBase.ptr_entity, pBuffer, pSize)

#define synapse_iosys_base_write_to(pBase, pBuffer, pSize)\
	pBase.write_to (pBase.ptr_entity, pBuffer, pSize)

#define synapse_iosys_base_pointer_current(pBase)\
	pBase.pointer_current(pBase.ptr_entity)

#define synapse_iosys_base_pointer_set(pBase, pNewPointer)\
	pBase.pointer_set(pBase.ptr_entity, pNewPointer)