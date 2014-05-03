MBR_PATH = ./mbr/
CORE_PATH = ./core/
CPU_CTRL_PATH = ./cpu_ctrl/
MEM_CTRL_PATH = ./memory_ctrl/
HEADER = ./header/
GRAPHIC = ./graphic/
SEGMENT_CTRL = ./GDT_IDT/
INTERRUPT = ./interrupt/
HARDWARE  = ./hardware/
img:Jupiter.img
	rm Jupiter
	rm *.o
	rm *.bin
	rm *.core
	
	
	
#编译选项
mbr.bin:$(MBR_PATH)mbr.s
	nasm $(MBR_PATH)mbr.s -o mbr.bin
ipl.bin:$(CORE_PATH)ipl.s
	nasm $(CORE_PATH)ipl.s -o ipl.bin

####################################################################################################
Jupiter.o:$(CORE_PATH)Jupiter.c $(HEADER)JS_CPU_ctrl.h $(HEADER)JS_MEM_ctrl.h $(HEADER)JS_Constant.h
	gcc $(CORE_PATH)Jupiter.c -c -m32  
#JS_VGA.o:$(CORE_PATH)JS_VGA.c
#	gcc $(CORE_PATH)JS_VGA.c -c -m32 
JS_Base_Graphic.o:$(GRAPHIC)JS_Base_Graphic.c	
	gcc $(GRAPHIC)JS_Base_Graphic.c	 -c -m32 
JS_Window_Graphic.o:$(GRAPHIC)JS_Window_Graphic.c	
	gcc $(GRAPHIC)JS_Window_Graphic.c	 -c -m32 
JS_GDT.o:$(SEGMENT_CTRL)JS_GDT.c
	gcc $(SEGMENT_CTRL)JS_GDT.c  -c -m32
JS_IDT.o:$(SEGMENT_CTRL)JS_IDT.c
	gcc $(SEGMENT_CTRL)JS_IDT.c  -c -m32
JS_Init_PIC.o:$(INTERRUPT)JS_Init_PIC.c
	gcc $(INTERRUPT)JS_Init_PIC.c  -c -m32
JS_Print.o:$(GRAPHIC)JS_Print.c
	gcc $(GRAPHIC)JS_Print.c  -c -m32
JS_System_Buffer.o:$(CORE_PATH)JS_System_Buffer.c
	gcc $(CORE_PATH)JS_System_Buffer.c -c -m32
JS_Init_Hardware.o:$(HARDWARE)JS_Init_Hardware.c
	gcc $(HARDWARE)JS_Init_Hardware.c -c -m32
JS_Memory_size.o:$(MEM_CTRL_PATH)JS_Memory_size.c
	gcc $(MEM_CTRL_PATH)JS_Memory_size.c -c -m32
####################################################################################################
JS_base_ctrl.o:$(CPU_CTRL_PATH)JS_base_ctrl.s
	nasm -f macho $(CPU_CTRL_PATH)JS_base_ctrl.s -o JS_base_ctrl.o

JS_CPU_Cache_ctrl.o:$(CPU_CTRL_PATH)JS_CPU_Cache_ctrl.s
	nasm -f macho $(CPU_CTRL_PATH)JS_CPU_Cache_ctrl.s -o JS_CPU_Cache_ctrl.o
	
JS_CPU_Version.o:$(CPU_CTRL_PATH)JS_CPU_Version.s
	nasm -f macho $(CPU_CTRL_PATH)JS_CPU_Version.s -o JS_CPU_Version.o
	
JS_write_mem.o:$(MEM_CTRL_PATH)JS_write_mem.s
	nasm -f macho $(MEM_CTRL_PATH)JS_write_mem.s -o JS_write_mem.o
	
JS_read_mem.o:$(MEM_CTRL_PATH)JS_read_mem.s
	nasm -f macho $(MEM_CTRL_PATH)JS_read_mem.s -o JS_read_mem.o
	
JS_io_set.o:$(CPU_CTRL_PATH)JS_io_set.s
	nasm -f macho $(CPU_CTRL_PATH)JS_io_set.s -o JS_io_set.o
	
JS_Char_Array.o:$(GRAPHIC)JS_Char_Array.s
	nasm -f macho $(GRAPHIC)JS_Char_Array.s -o JS_Char_Array.o
	
JS_Mouse_Array.o:$(GRAPHIC)JS_Mouse_Array.s
	nasm -f macho $(GRAPHIC)JS_Mouse_Array.s -o  JS_Mouse_Array.o
	
JS_ICON_Array.o:$(GRAPHIC)JS_ICON_Array.s
	nasm -f macho $(GRAPHIC)JS_ICON_Array.s -o  JS_ICON_Array.o
	
JS_memory_test.o:$(MEM_CTRL_PATH)JS_memory_test.s
	nasm -f macho $(MEM_CTRL_PATH)JS_memory_test.s -o JS_memory_test.o
	
####################################################################################################
#
#中断处理程序编译集合
####################################################################################################
JS_Int21.o:$(INTERRUPT)JS_Int21.s
	nasm -f macho $(INTERRUPT)JS_Int21.s -o JS_Int21.o
JS_Int21p.o:$(INTERRUPT)JS_Int21p.c
	gcc $(INTERRUPT)JS_Int21p.c  -c -m32
JS_Int2c.o:$(INTERRUPT)JS_Int2c.s
	nasm -f macho $(INTERRUPT)JS_Int2c.s -o JS_Int2c.o
JS_Int2cp.o:$(INTERRUPT)JS_Int2cp.c
	gcc $(INTERRUPT)JS_Int2cp.c  -c -m32

	
####################################################################################################
Jupiter:Jupiter.o JS_base_ctrl.o JS_io_set.o JS_write_mem.o JS_read_mem.o JS_Base_Graphic.o JS_Window_Graphic.o  \
JS_Char_Array.o JS_GDT.o JS_IDT.o JS_Init_PIC.o JS_Int21.o JS_Int21p.o JS_Int2c.o JS_Int2cp.o JS_Print.o JS_Mouse_Array.o\
JS_ICON_Array.o JS_System_Buffer.o JS_Init_Hardware.o JS_memory_test.o JS_CPU_Version.o JS_CPU_Cache_ctrl.o JS_Memory_size.o




	ld -e _Jupiter Jupiter.o  JS_Base_Graphic.o JS_base_ctrl.o JS_io_set.o JS_write_mem.o  JS_read_mem.o JS_Window_Graphic.o \
JS_Char_Array.o JS_GDT.o JS_IDT.o JS_Init_PIC.o JS_Int21.o JS_Int21p.o JS_Int2c.o JS_Int2cp.o JS_Print.o JS_Mouse_Array.o \
JS_ICON_Array.o JS_System_Buffer.o JS_Init_Hardware.o JS_memory_test.o JS_CPU_Version.o JS_CPU_Cache_ctrl.o JS_Memory_size.o \
-o Jupiter




Jupiter.core:Jupiter
	objcopy -j .text -S -O binary Jupiter Jupiter.core
Jupiter.img:mbr.bin ipl.bin Jupiter.core
	cat mbr.bin ipl.bin Jupiter.core>system.core
	dd	if=system.core of=Jupiter.img bs=512 conv=sync
	
	
	
	
#命令
run:Jupiter.img
	rm Jupiter
	rm *.o
	rm *.bin
	rm *.core
	qemu-system-i386 -fda Jupiter.img

clean:
	rm Jupiter
	rm *.o
	rm *.bin
	rm *.core
	rm *.img

	
test:Jupter.img
	bochs
