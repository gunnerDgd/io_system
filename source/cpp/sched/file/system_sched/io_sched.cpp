#include <io_system/sched/file/system_sched/cpp/io_sched.hpp>

io_system::schedule::system_scheduler::scheduler::scheduler
	(count_type pThreadCount)
		: __M_iosys_sched_hnd
			(synapse_iosys_sched_system_initialize(pThreadCount)) {  }

io_system::schedule::system_scheduler::scheduler::scheduler()
	: __M_iosys_sched_hnd
		(synapse_iosys_sched_system_initialize_default()) {  }

io_system::schedule::system_scheduler::scheduler::~scheduler()
{
	synapse_iosys_sched_system_cleanup
		(__M_iosys_sched_hnd);
}

io_system::schedule::system_scheduler::io_request
	io_system::schedule::system_scheduler::scheduler::retrive_completed()
{
	return
		io_request(
			synapse_iosys_sched_system_retrieve_completed(__M_iosys_sched_hnd)
		);
}