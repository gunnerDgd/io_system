#pragma once

#define synapse_io_system_opaque_define(pName)\
	typedef struct pName { void* opaque; } pName;

#define synapse_io_system_opaque_reference(pObject)\
	(pObject.opaque)

#define synapse_io_system_opaque_cast(pObject, pType)\
	((pType)(pObject.opaque))

#define synapse_io_system_opaque_init(pObjectType, pName, pValue)\
	pObjectType pName = { .opaque = pValue }

#define synapse_io_system_opaque_valid(pObject)\
	(pObject.opaque != NULL)