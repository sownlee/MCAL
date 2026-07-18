################################################################################
# Information module
################################################################################
DEV_MODULE_NAME = Port
DEV_PLATFORM_NAME = STM32F4XX

################################################################################
# BSW module ID (see 'AUTOSAR_BasicSoftwareModules.pdf' for details)
################################################################################
DEV_MODULE_ID_AUTOSAR = 124

################################################################################
# List of files and directories to build the tresos plugin
################################################################################

# Get xdm file
DEV_SRC_FILES = $(MODULE_PATH)/specific/$(PLATFORM_NAME)/config/Port.xdm@outdir=config \

# Get docs files
DEV_SRC_FILES +=$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/PORT_IM.pdf@outdir=doc \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/PORT_UM.pdf@outdir=doc \

# Get source and include template files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/generate_PC/include/Port_Cfg.h@outdir=generate_PC/include \
				$(MODULE_PATH)/generic/generate_PC/include/Port_Gpio_Ip_Cfg.h@outdir=generate_PC/include \
				$(MODULE_PATH)/generic/generate_PC/include/Port_Ipc_Cfg.h@outdir=generate_PC/include \
				$(MODULE_PATH)/generic/generate_PC/src/Port_Cfg.c@outdir=generate_PC/src \
				$(MODULE_PATH)/generic/generate_PC/src/Port_Gpio_Ip_Cfg.c@outdir=generate_PC/src \
				$(MODULE_PATH)/generic/generate_PB/include/Port_Gpio_Ip_PBcfg.h@outdir=generate_PB/include \
				$(MODULE_PATH)/generic/generate_PB/include/Port_Ipc_PBcfg.h@outdir=generate_PB/include \
				$(MODULE_PATH)/generic/generate_PB/include/Port_PBcfg.h@outdir=generate_PB/include \
				$(MODULE_PATH)/generic/generate_PB/src/Port_Gpio_Ip_PBcfg.c@outdir=generate_PB/src \
				$(MODULE_PATH)/generic/generate_PB/src/Port_Ipc_PBcfg.c@outdir=generate_PB/src \
				$(MODULE_PATH)/generic/generate_PB/src/Port_PBcfg.c@outdir=generate_PB/src \

# Get source and include files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/include/Port_Types.h@outdir=include \
				$(MODULE_PATH)/generic/include/Port_VersionInfo.h@outdir=include \
				$(MODULE_PATH)/generic/include/Port.h@outdir=include \
				$(MODULE_PATH)/generic/src/Port.c@outdir=src \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/include/Port_Ipc_Types.h@outdir=include \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/include/Port_Ipc.h@outdir=include \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/src/Port_Ipc.c@outdir=src \
				$(MODULE_PATH)/Ip/IP_GPIO/Hw/include/Port_Hw.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_GPIO/Hw/src/Port_Hw.c@outdir=src\
				$(MODULE_PATH)/Ip/IP_GPIO/include/Port_Gpio_Ip_Devassert.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_GPIO/include/Port_Gpio_Ip_Types.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_GPIO/include/Port_Gpio_Ip_VersionInfo.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_GPIO/include/Port_Gpio_Ip.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_GPIO/src/Port_Gpio_Ip.c@outdir=src\

# Get example folder
DEV_SRC_DIR =$(MODULE_PATH)/specific/$(PLATFORM_NAME)/examples
