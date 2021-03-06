#
# additional routines and headers for libc
#

ifeq ($(subdir),csu)
sysdep_routines += errno-loc
endif

ifeq ($(subdir),io)
sysdep_routines += sys_open sys_open64 sys_openat sys_openat64 \
    sys_fstat sys_fstat64 sys_fstatat sys_fstatat64 sys_lstat \
    sys_lstat64 sys_stat sys_stat64 sys_sendfilev sys_sendfilev64 \
    sys_getcwd sys_pipe sys_mknod sys_access sys_accessat
headers := $(filter-out sys/vfs.h, $(headers))
endif

ifeq ($(subdir),misc)
sysdep_routines +=  gethrtime mount umount umount2 systeminfo resolvepath \
    getpagesizes memcntl meminfo uadmin getpflags setpflags issetugid ucred \
    priv processor_bind processor_info p_online pset_create pset_destroy \
    pset_assign pset_info pset_bind pset_getloadavg pset_list pset_setattr \
    pset_getattr swapctl getustack setustack gethrvtime uucopy uucopystr \
    zone_add_datalink zone_boot zone_check_datalink zone_destroy zone_enter \
    zone_getattr zone_list zone_list_datalink zone_remove_datalink \
    zone_setattr zone_shutdown zone_version core_get_default_content \
    core_get_default_path core_get_global_content core_get_global_path \
    core_get_options core_get_process_content core_get_process_path \
    core_set_default_content core_set_default_path core_set_global_content \
    core_set_global_path core_set_options core_set_process_content \
    core_set_process_path getacct putacct wracct sysfs acct allocids \
    idmap_reg idmap_unreg acctctl pcsample settaskid gettaskid getprojid \
    utssys zone port sendfilev sendfilev64 sig2str _so_accept _so_bind \
    _so_connect _so_getpeername _so_getsockname _so_getsockopt _so_listen \
    _so_recvmsg _so_send _so_sendmsg _so_sendto _so_setsockopt _so_shutdown \
    _so_socket _so_socketpair _sysconfig rctl atomic door __door_return \
    getexecname is_system_labeled privP modctl acl facl lltostr ulltostr \
    _getauthnam _getauthattr deflt _getprofnam _getprofattr _getusernam \
    _getuserattr _getauuserent _getauusernam _getexecattr vfstab fdwalk \
    closefrom ipsecalg gethostent sigsendset sigsend stack_getbounds \
    thr_sighndlrinfo _getexecprof _fgetuserattr priv_str _sbrk_grow_aligned \
    cftime ascftime inet_ntoa_r mnttab inst_sync autofssys cladm lgrpsys \
    _lgrp_home_fast
sysdep_routines += sys_fdsync sys_brk sys_fcntl sys_utssys sys_lwp_private \
    sys_uname sys_getloadavg sys_utimes sys_getpeerucred sys_ucred_get \
    sys_privsys sys_putmsg sys_putpmsg sys_meminfo sys_pset_getloadavg \
    sys_zone_create sys_allocids sys_settaskid sys_zone_lookup sys_port \
    sys_door klogctl
sysdep_headers += sys/feature_tests.h sys/dirent.h sys/utime.h sys/machelf.h \
    sys/systeminfo.h sys/link.h sys/procfs_isa.h sys/ttold.h sys/procset.h \
    sys/synch.h sys/fork.h sys/sockio.h sys/ioccom.h sys/tty.h sys/priocntl.h \
    sys/trap.h sys/sysconfig.h sys/ptms.h sys/stack.h sys/regset.h \
    bits/regset.h sys/priv.h sys/priv_names.h sys/uadmin.h sys/vfstab.h \
    sys/fault.h sys/door.h sys/mount.h sys/procfs.h sys/old_procfs.h \
    sys/reg.h sys/siginfo.h sys/types32.h sys/isa_defs.h sys/int_types.h \
    sys/inttypes.h sys/atomic.h sys/machtypes.h sys/elf.h sys/mkdev.h \
    sys/klog.h sys/zone.h sys/processor.h sys/pset.h sys/task.h sys/exacct.h \
    sys/acct.h sys/acctctl.h sys/utssys.h sys/corectl.h sys/loadavg.h \
    sys/port.h sys/port_impl.h sys/acl.h sys/tsol/label.h sys/fsid.h \
    sys/fstyp.h sys/rctl.h sys/rctl_impl.h sys/sid.h sys/mnttab.h sys/mntio.h \
    sys/instance.h sys/byteorder.h
sysdep_headers += rtld_db.h pcsample.h atomic.h bits/machtypes.h door.h \
    ucred.h priv.h zone.h port.h deflt.h procfs.h rctl.h
headers := $(filter-out sys/sysinfo.h sys/xattr.h, $(headers))
endif

ifeq ($(subdir),dirent)
sysdep_routines += sys_getdents sys_getdents64
endif

ifeq ($(subdir),inet)
sysdep_routines += _link_aton _link_ntoa htonll
endif

ifeq ($(subdir),posix)
sysdep_routines += exit-thread schedP
endif

ifeq ($(subdir),resource)
sysdep_routines += priocntl getvmusage
sysdep_routines += sys_rusagesys sys_priocntlsys sys_rctlsys
endif

ifeq ($(subdir),signal)
sysdep_routines += sys_lwp_sigmask sys_sigqueue sys_sigtimedwait \
    sys_sigaction
endif

ifeq ($(subdir),socket)
sysdep_routines += cmsg_nxthdr sa_len
sysdep_routines += netmask
sysdep_headers += net/if_dl.h
headers := $(filter-out sys/socketvar.h, $(headers))
endif

ifeq ($(subdir),time)
sysdep_routines += ntp_adjtime ntp_gettime sys_time sys_stime
sysdep_headers += sys/timex.h sys/time_impl.h
endif

ifeq ($(subdir),termios)
sysdep_headers += termio.h
sysdep_headers += sys/termio.h
endif

#
# Additional sysdeps for ld.so
#
ifeq ($(subdir),elf)
sysdep-rtld-routines += _sysconfig
endif

ifeq ($(subdir),nss)
databases += audit_user auth_attr bootparams exec_attr netmasks printers \
    prof_attr project user_attr
CFLAGS-files-audit_user.c = -Inss_files
CFLAGS-files-auth_attr.c = -Inss_files
CFLAGS-files-bootparams.c = -Inss_files
CFLAGS-files-exec_attr.c = -Inss_files
CFLAGS-files-netmasks.c = -Inss_files
CFLAGS-files-printers.c = -Inss_files
CFLAGS-files-prof_attr.c = -Inss_files
CFLAGS-files-project.c = -Inss_files
CFLAGS-files-user_attr.c = -Inss_files
endif

ifeq ($(subdir),nptl)
libpthread-sysdep_routines += sys_fcntl sys_fdsync sys_sigaction sys_open \
    sys_open64 sys_priocntlsys schedP priocntl syscall
endif

ifeq ($(subdir),nptl_db)
sysdep_headers += proc_service.h
endif

ifeq ($(subdir),resolv)
libresolv-routines += sys_sigqueue
endif

ifeq ($(subdir),rt)
librt-routines += sys_sigqueue
endif

CFLAGS-accept.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-connect.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-fsync.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-fdatasync.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-fsync.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-msgrcv.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-msync.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-open.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-open64.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-openat.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-openat64.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-recvmsg.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-pselect.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-select.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-send.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-sendmsg.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-sendto.c = -fexceptions -fasynchronous-unwind-tables
CFLAGS-tcdrain.c = -fexceptions -fasynchronous-unwind-tables
