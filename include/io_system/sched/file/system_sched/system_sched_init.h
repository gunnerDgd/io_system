#pragma once
#include <io_system/file/file_io_system.h>
#include <io_system/sched/file/system_sched/system_sched_type.h>

synapse_iosys_sched_system
synapse_iosys_sched_system_initialize(size_t);

synapse_iosys_sched_system
synapse_iosys_sched_system_initialize_default();

synapse_iosys_sched_system_io_request
synapse_iosys_sched_system_io_request_initialize(void*, size_t, size_t);

synapse_iosys_sched_system_io_session
synapse_iosys_sched_system_io_session_initialize(synapse_iosys_sched_system, synapse_io_system_file*);

void
synapse_iosys_sched_system_cleanup(synapse_iosys_sched_system);

void
synapse_iosys_sched_system_io_session_cleanup(synapse_iosys_sched_system_io_session);

void
synapse_iosys_sched_system_io_request_cleanup(synapse_iosys_sched_system_io_request);