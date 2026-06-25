// SPDX-License-Identifier: GPL-2.0
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/utsname.h>
#include <linux/kokuban_envhide.h>
#include "internal.h"

static int version_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, linux_proc_banner,
		utsname()->sysname,
		KOKUBAN_ENVHIDE_RELEASE,
		KOKUBAN_ENVHIDE_VERSION);
	return 0;
}

static int __init proc_version_init(void)
{
	struct proc_dir_entry *pde;

	pde = proc_create_single("version", 0, NULL, version_proc_show);
	pde_make_permanent(pde);
	return 0;
}
fs_initcall(proc_version_init);
