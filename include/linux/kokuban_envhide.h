/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_KOKUBAN_ENVHIDE_H
#define _LINUX_KOKUBAN_ENVHIDE_H

#include <linux/string.h>
#include <linux/utsname.h>

/*
 * Keep the real kernel build string intact for boot/module compatibility, but
 * present the stock BZCH userspace-facing UTS strings to app-side native checks.
 */
#define KOKUBAN_ENVHIDE_RELEASE "6.6.77-android15-8-31998796-abogkiS937BXXS7BZCH-4k"
#define KOKUBAN_ENVHIDE_VERSION "#1 SMP PREEMPT Fri Mar 27 08:31:07 UTC 2026"

static inline void kokuban_envhide_uts(struct new_utsname *u)
{
	strscpy(u->release, KOKUBAN_ENVHIDE_RELEASE, sizeof(u->release));
	strscpy(u->version, KOKUBAN_ENVHIDE_VERSION, sizeof(u->version));
}

#endif /* _LINUX_KOKUBAN_ENVHIDE_H */
