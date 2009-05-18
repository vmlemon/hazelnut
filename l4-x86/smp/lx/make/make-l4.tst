
p={d:\lx\kernel\;\lx\kernifc\;\lx\userifc\}
a=d:\lx\x86^\
all_includes_x86= $(p)l4pre.inc $(p)l4const.inc $(p)l4kd.inc $(p)adrspace.inc $(p)adrspac5.inc $(p)tcb.inc $(p)cpucb.inc $(p)cpucb5.inc $(p)intrifc.inc $(p)pagcb.inc $(p)pagconst.inc $(p)pagmac.inc $(p)pnodes.inc $(p)schedcb.inc $(p)schedcb2.inc $(p)lbmac.inc $(p)syscalls.inc $(p)uid.inc $(p)kpage.inc $(p)msg.inc $(p)SCmac.inc $(p)apic.inc


$(a)apstrtup.obj : $(all_includes_x86) $(p)apstrtup.asm
  @cd \lx\x86
  @..\make\ml-x86 apstrtup asm

$(a)mpconf.obj : $(all_includes_x86) $(p)mpconf.asm
  @cd \lx\x86
  @..\make\ml-x86 mpconf asm

$(a)adrsman.obj : $(all_includes_x86) $(p)adrsman.asm
  @cd \lx\x86
  @..\make\ml-x86 adrsman asm
  
$(a)cpuctr.obj : $(all_includes_x86) $(p)cpuctr.asm
  @cd \lx\x86
  @..\make\ml-x86 cpuctr asm
  
$(a)dispatch.obj : $(all_includes_x86) $(p)dispatch.asm
  @cd \lx\x86
  @..\make\ml-x86 dispatch asm
 
$(a)emuctr.obj : $(all_includes_x86) $(p)emuctr.asm
  @cd \lx\x86
  @..\make\ml-x86 emuctr asm
 
$(a)intctr.obj : $(all_includes_x86) $(p)intctr.asm
  @cd \lx\x86
  @..\make\ml-x86 intctr asm
 
$(a)ipcman.obj : $(all_includes_x86) $(p)ipcman.asm
  @cd \lx\x86
  @..\make\ml-x86 ipcman asm
 
$(a)kdebug.obj : $(all_includes_x86) $(p)kdebug.asm
  @cd \lx\x86
  @..\make\ml-x86 kdebug asm           
 
$(a)kdiopc.obj : $(all_includes_x86) $(p)kdiopc.asm
  @cd \lx\x86
  @..\make\ml-x86 kdiopc asm
 
$(a)kernel.obj : $(p)kernel.asm
  @cd \lx\x86
  @..\make\ml-x86 kernel asm
 
$(a)ktest.obj : $(all_includes_x86) $(p)ktest.asm
  @cd \lx\x86
  @..\make\ml-x86 ktest asm
 
$(a)memctr.obj : $(all_includes_x86) $(p)memctr.asm
  @cd \lx\x86
  @..\make\ml-x86 memctr asm
 
$(a)pagctr.obj : $(all_includes_x86) $(p)pagctr.asm
  @cd \lx\x86
  @..\make\ml-x86 pagctr asm
  
$(a)pagfault.obj : $(all_includes_x86) $(p)pagfault.asm
  @cd \lx\x86
  @..\make\ml-x86 pagfault asm
 
$(a)pagmap.obj : $(all_includes_x86) $(p)pagmap.asm
  @cd \lx\x86
  @..\make\ml-x86 pagmap asm
 
$(a)sgmctr.obj : $(all_includes_x86) $(p)sgmctr.asm
  @cd \lx\x86
  @..\make\ml-x86 sgmctr asm
 
$(a)sigma0.obj : $(all_includes_x86) $(p)sigma0.asm
  @cd \lx\x86
  @..\make\ml-x86 sigma0 asm
 
$(a)start.obj : $(all_includes_x86) $(p)start.asm
  @cd \lx\x86
  @..\make\ml-x86 start asm
 
$(a)startpc.obj : $(all_includes_x86) $(p)startpc.asm
  @cd \lx\x86
  @..\make\ml-x86 startpc asm
 
$(a)tcbman.obj : $(all_includes_x86) $(p)tcbman.asm
  @cd \lx\x86
  @..\make\ml-x86 tcbman asm 
 
$(a)yoonseva.obj : $(all_includes_x86) $(p)yoonseva.asm
  @cd \lx\x86
  @..\make\ml-x86 yoonseva asm 
  
$(a)l4.exe : $(a)adrsman.obj $(a)cpuctr.obj $(a)dispatch.obj $(a)emuctr.obj
$(a)l4.exe : $(a)intctr.obj $(a)ipcman.obj $(a)kdebug.obj $(a)kdiopc.obj
$(a)l4.exe : $(a)kernel.obj $(a)ktest.obj $(a)memctr.obj $(a)pagctr.obj
$(a)l4.exe : $(a)pagfault.obj $(a)pagmap.obj $(a)sgmctr.obj $(a)sigma0.obj $(a)mpconf.obj $(a)apstrtup.obj
$(a)l4.exe : $(a)start.obj $(a)startpc.obj $(a)tcbman.obj 
$(a)l4.exe : $(a)yoonseva.obj
$(a)l4.exe : $(a)boot.obj
 @cd \lx\x86
 @link /nologo @..\make\l4.rsp
 rem pause
 


$(a)boot.obj : $(all_includes_x86) $(p)boot.asm  
  @cd \lx\x86
  @..\make\ml-x86 boot asm 

$(a)boot.com : $(a)boot.obj
 @cd \lx\x86
 link boot.obj/TINY,boot,boot.map

 



 
