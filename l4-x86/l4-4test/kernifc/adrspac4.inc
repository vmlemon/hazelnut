
;----------------------------------------------------------------------------
;
;       address space description
;
;----------------------------------------------------------------------------




; shared by all tasks
; I
; I  per task
; I  I
; I  I


     virtual_space_size    equ  (3*GB+512*MB)            

  tcb_space_size           equ  (256*MB)
  physical_kernel_mem_size equ  ( 64*MB)
  pnode_space_size         equ  ( 64*MB)

  reserved_space_1_size    equ  ( 88*MB)

  pdir_space_size          equ  (  4*MB)
  kernel_resident_tab_size equ  ( 12*MB)

     vint_size             equ     32  
     iopbm_size            equ  ( 8*KB-32)  
     ldt_size              equ  (64*KB)  

     reserved_space_2_size equ  (4*MB-(64+8)*KB)

     ptab_space_size       equ  ( 4*MB)
     com0_space_size       equ  ( 8*MB)
     com1_space_size       equ  ( 8*MB)




    

linear_address_space       struc

     virtual_space         db virtual_space_size  dup (?)

  tcb_space                db tcb_space_size      dup (?)
  physical_kernel_memory   db physical_kernel_mem_size dup (?) ; dyn allocated !
  pnode_space              db pnode_space_size    dup (?) ; dyn allocated !

  reserved_space_1         db reserved_space_1_size dup (?)

  pdir_space               db pdir_space_size     dup (?)
  kernel_resident_tables   db kernel_resident_tab_size dup (?) ; dyn allocated !

                           dd vint_size/4         dup (?)
     iopbm                 dd iopbm_size/4        dup (?)
     ldt                   dd ldt_size/4          dup (?)

     reserved_space_2      db reserved_space_2_size dup (?)

     ptab_space            db ptab_space_size     dup (?)
     com0_space            db com0_space_size     dup (?)
     com1_space            db com1_space_size     dup (?)



linear_address_space       ends


linear_address_space_size   equ  (offset com1_space+com1_space_size)    ;  masm611 bug

         ;  MOD 2*32  is ok , since only used for segment descriptor construction.
         


kernel_firewall_size       equ  KB4

auxiliary_address_space    struc

                           db   offset tcb_space          dup (?)

  kernel_firewall          db   kernel_firewall_size      dup (?)

                           db   offset ptab_space-offset tcb_space-KB4 dup (?)

                           dd   offset ptab_space SHR 12  dup (?)
     pdir                  dd                                  ?
     
auxiliary_address_space    ends



max_physical_memory_size   equ (1*GB)

max_phys_memory struc

  max_physical_memory      db  max_physical_memory_size  dup (?)

max_phys_memory ends


log2_pagesize              equ 12                      ; 4 K pages
pagesize                   equ (1 SHL log2_pagesize)   ;


log2_chaptersize           equ (5+2)                   ; 32 PTEs per chapter
chaptersize                equ (1 SHL log2_chaptersize);
ptes_per_chapter           equ (chaptersize / 4)       ;
chapters_per_page          equ (pagesize / chaptersize);




PM                         equ offset physical_kernel_memory

max_ptabs                  equ (physical_kernel_mem_size / pagesize)


com0_base            equ offset com0_space         ; due to pharlap asm bug
com1_base            equ offset com1_space         ; [pdir+offset cs/MB4] generates

shared_table_base    equ offset tcb_space
shared_table_size    equ (offset kernel_resident_tables+kernel_resident_tab_size - shared_table_base)



dwords_per_task_proot equ 1

kernel_r_tables struc

                    db offset kernel_resident_tables             dup (?)

  accessed_bitmap   dd   max_physical_memory_size/pagesize/32    dup (?)
  ptab_backlink     dd   max_ptabs                               dup (?)
  chapter_map       db   max_ptabs*chapters_per_page             dup (?)

  reserved_space_3  db   00B65000h-KB4                           dup (?)

  logical_info_page db   KB4                                     dup (?)

                    db   280h-8                                  dup (?)
  gdt               dd   8*2*4/4                                 dup (?)
                    db   4                                       dup (?)
  cpu_cb            db   128+4                                   dup (?)
  sched_cb          db   16*8+64                                 dup (?)
  intr_cb           db   16*4                                    dup (?)
  pag_cb            db   32                                      dup (?)
  idt               dd   40h*8/4                                 dup (?)
  task_proot        dd   2048*dwords_per_task_proot              dup (?)  ;     |
                                                                          ;     |
kernel_r_tables ends                                                      ;     |
                                                                          ;     V
kernel_r_tables_size equ (offset task_proot+sizeof task_proot)            ;  masm611 bug 

.erre         kernel_r_tables_size LE (offset kernel_resident_tables+kernel_resident_tab_size)



special_proots struc

                    db offset task_proot                         dup (?)

  empty_proot       dd 0
  kernel_proot      dd 0
  sigma0_proot      dd 0

special_proots ends

             
.erre         offset pnode_space GE (offset physical_kernel_memory + physical_kernel_mem_size)
