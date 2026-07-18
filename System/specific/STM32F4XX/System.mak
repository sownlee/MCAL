################################################################################
# Information module
################################################################################
DEV_MODULE_NAME = System
DEV_PLATFORM_NAME = STM32F4XX

################################################################################
# BSW module ID (see 'AUTOSAR_BasicSoftwareModules.pdf' for details)
################################################################################
DEV_MODULE_ID_AUTOSAR = 255

################################################################################
# List of files and directories to build the tresos plugin
################################################################################

# Get xdm file
DEV_SRC_FILES = $(MODULE_PATH)/specific/$(PLATFORM_NAME)/config/System.xdm@outdir=config \

# Get docs files
DEV_SRC_FILES +=$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/SYSTEM_IM.pdf@outdir=doc \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/SYSTEM_UM.pdf@outdir=doc \

# Get source and include template files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/generate_PC/include/Interrupt_System_Ip_Cfg.h@outdir=generate_PC/include \
				$(MODULE_PATH)/generic/generate_PC/include/System_Cfg.h@outdir=generate_PC/include \
				$(MODULE_PATH)/generic/generate_PC/src/Interrupt_System_Ip_Cfg.c@outdir=generate_PC/src \
				$(MODULE_PATH)/generic/generate_PC/src/System_Cfg.c@outdir=generate_PC/src \

# Get source and include files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/include/OsIf_Internal.h@outdir=include \
				$(MODULE_PATH)/generic/include/System_Types.h@outdir=include \
				$(MODULE_PATH)/generic/include/System.h@outdir=include \
				$(MODULE_PATH)/generic/src/System.c@outdir=src \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/include/System_Ipc.h@outdir=include \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/src/System_Ipc.c@outdir=src \
				$(MODULE_PATH)/Ip/IP_INTERRUPT/Hw/include/Interrupt_System_HW.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_INTERRUPT/Hw/src/Interrupt_System_HW.c@outdir=src\
				$(MODULE_PATH)/Ip/IP_INTERRUPT/include/Interrupt_System_Ip_Devassert.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_INTERRUPT/include/Interrupt_System_Ip_Types.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_INTERRUPT/include/Interrupt_System_Ip.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_INTERRUPT/src/Interrupt_System_Ip.c@outdir=src\
				$(MODULE_PATH)/Ip/IP_OSSYSTEM/Hw/include/Systick_System_HW.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_OSSYSTEM/Hw/src/Systick_System_HW.c@outdir=src\
				$(MODULE_PATH)/Ip/IP_OSSYSTEM/include/Systick_System_Ip.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_OSSYSTEM/src/Systick_System_Ip.c@outdir=src

# Get example folder
DEV_SRC_DIR =$(MODULE_PATH)/specific/$(PLATFORM_NAME)/examples
