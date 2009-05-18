/* $Id: misc.c,v 1.1 2000/02/07 18:03:43 uhlig Exp $
 *
 * misc.c: Miscellaneous ARCS PROM routines.
 *
 * Copyright (C) 1996 David S. Miller (dm@engr.sgi.com)
 */
#include <universe.h>
#include <mips/bcache.h>
#include <mips/sgialib.h>
#if 0
#include <linux/config.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <asm/bcache.h>
#include <asm/sgialib.h>
#include <asm/bootinfo.h>
#include <asm/system.h>
#endif

extern unsigned long mips_cputype;
extern void *sgiwd93_host;
extern void reset_wd33c93(void *instance);

void prom_halt(void)
{
	bcops->bc_disable();
	disable_interrupts();
#if CONFIG_SCSI_SGIWD93
	reset_wd33c93(sgiwd93_host);
#endif
	romvec->halt();
}

void prom_powerdown(void)
{
	bcops->bc_disable();
	disable_interrupts();
#if CONFIG_SCSI_SGIWD93
	reset_wd33c93(sgiwd93_host);
#endif
	romvec->pdown();
}

/* XXX is this a soft reset basically? XXX */
void prom_restart(void)
{
	bcops->bc_disable();
	disable_interrupts();
#if CONFIG_SCSI_SGIWD93
	reset_wd33c93(sgiwd93_host);
#endif
	romvec->restart();
}

void prom_reboot(void)
{
	bcops->bc_disable();
	disable_interrupts();
#if CONFIG_SCSI_SGIWD93
	reset_wd33c93(sgiwd93_host);
#endif
	romvec->reboot();
}

void prom_imode(void)
{
	bcops->bc_disable();
	disable_interrupts();
#if CONFIG_SCSI_SGIWD93
	reset_wd33c93(sgiwd93_host);
#endif
	romvec->imode();
}

long prom_cfgsave(void)
{
	return romvec->cfg_save();
}

struct linux_sysid *prom_getsysid(void)
{
	return romvec->get_sysid();
}

void prom_cacheflush(void)
{
	romvec->cache_flush();
}
