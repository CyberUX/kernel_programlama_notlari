/*
 * struct task_sturct header dosyası kernel/include/linux/sched.h içindedir.
 */
struct task_struct {
	volatile long state;	/* -1 unrunnable, 0 runnable, >0 stopped */
	struct thread_info *thread_info;
	atomic_t usage;
	unsigned long flags;	/* per process flags, defined below */
	unsigned long ptrace;

	int lock_depth;		/* Lock depth */

	int prio, static_prio;
	struct list_head run_list;
	prio_array_t *array;

	unsigned long sleep_avg;
	unsigned long long timestamp, last_ran;
	int activated;

	unsigned long policy;
	cpumask_t cpus_allowed;
	unsigned int time_slice, first_time_slice;

#ifdef CONFIG_SCHEDSTATS
	struct sched_info sched_info;
#endif

	struct list_head tasks;
	/*
	 * ptrace_list/ptrace_children forms the list of my children
	 * that were stolen by a ptracer.
	 */
	struct list_head ptrace_children;
	struct list_head ptrace_list;

	struct mm_struct *mm, *active_mm;

/* task state */
	struct linux_binfmt *binfmt;
	long exit_state;
	int exit_code, exit_signal;
	int pdeath_signal;  /*  The signal sent when the parent dies  */
	/* ??? */
	unsigned long personality;
	unsigned did_exec:1;
	pid_t pid;
	pid_t tgid;
	/* 
	 * pointers to (original) parent process, youngest child, younger sibling,
	 * older sibling, respectively.  (p->father can be replaced with 
	 * p->parent->pid)
	 */
	struct task_struct *real_parent; /* real parent process (when being debugged) */
	struct task_struct *parent;	/* parent process */
	/*
	 * children/sibling forms the list of my children plus the
	 * tasks I'm ptracing.
	 */
	struct list_head children;	/* list of my children */
	struct list_head sibling;	/* linkage in my parent's children list */
	struct task_struct *group_leader;	/* threadgroup leader */

	/* PID/PID hash table linkage. */
	struct pid pids[PIDTYPE_MAX];

	struct completion *vfork_done;		/* for vfork() */
	int __user *set_child_tid;		/* CLONE_CHILD_SETTID */
	int __user *clear_child_tid;		/* CLONE_CHILD_CLEARTID */

	unsigned long rt_priority;
	unsigned long it_real_value, it_real_incr;
	cputime_t it_virt_value, it_virt_incr;
	cputime_t it_prof_value, it_prof_incr;
	struct timer_list real_timer;
	cputime_t utime, stime;
	unsigned long nvcsw, nivcsw; /* context switch counts */
	struct timespec start_time;
/* mm fault and swap info: this can arguably be seen as either mm-specific or thread-specific */
	unsigned long min_flt, maj_flt;
/* process credentials */
	uid_t uid,euid,suid,fsuid;
	gid_t gid,egid,sgid,fsgid;
	struct group_info *group_info;
	kernel_cap_t   cap_effective, cap_inheritable, cap_permitted;
	unsigned keep_capabilities:1;
	struct user_struct *user;
#ifdef CONFIG_KEYS
	struct key *session_keyring;	/* keyring inherited over fork */
	struct key *process_keyring;	/* keyring private to this process (CLONE_THREAD) */
	struct key *thread_keyring;	/* keyring private to this thread */
#endif
	int oomkilladj; /* OOM kill score adjustment (bit shift). */
	char comm[TASK_COMM_LEN];
/* file system info */
	int link_count, total_link_count;
/* ipc stuff */
	struct sysv_sem sysvsem;
/* CPU-specific state of this task */
	struct thread_struct thread;
/* filesystem information */
	struct fs_struct *fs;
/* open file information */
	struct files_struct *files;
/* namespace */
	struct namespace *namespace;
/* signal handlers */
	struct signal_struct *signal;
	struct sighand_struct *sighand;

	sigset_t blocked, real_blocked;
	struct sigpending pending;

	unsigned long sas_ss_sp;
	size_t sas_ss_size;
	int (*notifier)(void *priv);
	void *notifier_data;
	sigset_t *notifier_mask;
	
	void *security;
	struct audit_context *audit_context;

/* Thread group tracking */
   	u32 parent_exec_id;
   	u32 self_exec_id;
/* Protection of (de-)allocation: mm, files, fs, tty, keyrings */
	spinlock_t alloc_lock;
/* Protection of proc_dentry: nesting proc_lock, dcache_lock, write_lock_irq(&tasklist_lock); */
	spinlock_t proc_lock;
/* context-switch lock */
	spinlock_t switch_lock;

/* journalling filesystem info */
	void *journal_info;

/* VM state */
	struct reclaim_state *reclaim_state;

	struct dentry *proc_dentry;
	struct backing_dev_info *backing_dev_info;

	struct io_context *io_context;

	unsigned long ptrace_message;
	siginfo_t *last_siginfo; /* For ptrace use.  */
/*
 * current io wait handle: wait queue entry to use for io waits
 * If this thread is processing aio, this points at the waitqueue
 * inside the currently handled kiocb. It may be NULL (i.e. default
 * to a stack based synchronous wait) if its doing sync IO.
 */
	wait_queue_t *io_wait;
/* i/o counters(bytes read/written, #syscalls */
	u64 rchar, wchar, syscr, syscw;
#if defined(CONFIG_BSD_PROCESS_ACCT)
	u64 acct_rss_mem1;	/* accumulated rss usage */
	u64 acct_vm_mem1;	/* accumulated virtual memory usage */
	clock_t acct_stimexpd;	/* clock_t-converted stime since last update */
#endif
#ifdef CONFIG_NUMA
  	struct mempolicy *mempolicy;
	short il_next;
#endif
};
/* 
 * thread_info header dosyası include/asm/thread_info.h içindedir
struct thread_info {
	struct task_struct	*task;		/* main task structure */
	struct exec_domain	*exec_domain;	/* execution domain */
	unsigned long		flags;		/* low level flags */
	unsigned long		status;		/* thread-synchronous flags */
	__u32			cpu;		/* current CPU */
	__s32			preempt_count; /* 0 => preemptable, <0 => BUG */


	mm_segment_t		addr_limit;	/* thread address space:
					 	   0-0xBFFFFFFF for user-thead
						   0-0xFFFFFFFF for kernel-thread
						*/
	struct restart_block    restart_block;

	unsigned long           previous_esp;   /* ESP of the previous stack in case
						   of nested (IRQ) stacks
						*/
	__u8			supervisor_stack[0];
};

