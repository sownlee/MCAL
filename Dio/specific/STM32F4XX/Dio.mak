################################################################################
# Information module
################################################################################
DEV_MODULE_NAME = Dio
DEV_PLATFORM_NAME = STM32F4XX

################################################################################
# BSW module ID (see 'AUTOSAR_BasicSoftwareModules.pdf' for details)
################################################################################
DEV_MODULE_ID_AUTOSAR = 120

################################################################################
# List of files and directories to build the tresos plugin
################################################################################

# Get xdm file
DEV_SRC_FILES = $(MODULE_PATH)/specific/$(PLATFORM_NAME)/config/Dio.xdm@outdir=config \

# Get docs files
DEV_SRC_FILES +=$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/DIO_IM.pdf@outdir=doc \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/DIO_UM.pdf@outdir=doc \

# Get source and include template files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/generate_PC/include/Dio_Cfg.h@outdir=generate_PC/include \
				$(MODULE_PATH)/generic/generate_PC/include/Dio_Gpio_Ip_Cfg.h@outdir=generate_PC/include \
				$(MODULE_PATH)/generic/generate_PC/include/Dio_Ipc_Cfg.h@outdir=generate_PC/include \
				$(MODULE_PATH)/generic/generate_PC/src/Dio_Cfg.c@outdir=generate_PC/src \
				$(MODULE_PATH)/generic/generate_PC/src/Dio_Gpio_Ip_Cfg.c@outdir=generate_PC/src \
				$(MODULE_PATH)/generic/generate_PC/src/Dio_Ipc_Cfg.c@outdir=generate_PC/src \

# Get source and include files
DEV_SRC_FILES +=$(MODULE_PATH)/generic/include/Dio_Types.h@outdir=include \
				$(MODULE_PATH)/generic/include/Dio_VersionInfo.h@outdir=include \
				$(MODULE_PATH)/generic/include/Dio.h@outdir=include \
				$(MODULE_PATH)/generic/src/Dio.c@outdir=src \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/include/Dio_Ipc_Types.h@outdir=include \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/include/Dio_Ipc.h@outdir=include \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/src/Dio_Ipc.c@outdir=src \
				$(MODULE_PATH)/Ip/IP_GPIO/include/Dio_Gpio_Ip_Devassert.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_GPIO/include/Dio_Gpio_Ip_Types.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_GPIO/include/Dio_Gpio_Ip_VersionInfo.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_GPIO/include/Dio_Gpio_Ip.h@outdir=include\
				$(MODULE_PATH)/Ip/IP_GPIO/src/Dio_Gpio_Ip.c@outdir=src\

# Get example folder
DEV_SRC_DIR =$(MODULE_PATH)/specific/$(PLATFORM_NAME)/examples
