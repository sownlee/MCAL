################################################################################
# Information module
################################################################################
DEV_MODULE_NAME = Rte
DEV_PLATFORM_NAME = STM32F4XX


# Get xdm file
DEV_SRC_FILES = $(MODULE_PATH)/specific/$(PLATFORM_NAME)/config/Rte.xdm@outdir=config \

# Get docs files
DEV_SRC_FILES +=$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/RTE_IM.pdf@outdir=doc \
				$(MODULE_PATH)/specific/$(PLATFORM_NAME)/doc/user_manuals/RTE_UM.pdf@outdir=doc \

################################################################################
# BSW module ID (see 'AUTOSAR_BasicSoftwareModules.pdf' for details)
################################################################################
DEV_MODULE_ID_AUTOSAR = 2

################################################################################
# List of files and directories to build the tresos plugin
################################################################################

# Get source and include files
DEV_SRC_FILES =$(MODULE_PATH)/generic/include/SchM_Adc.h@outdir=include

DEV_SRC_FILES +=$(MODULE_PATH)/generic/include/SchM_Can.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Crc.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Crypto.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Dio.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Eep.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Eth.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Fee.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Fls.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Gpt.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_I2c.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Icu.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Lin.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Mcem.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Mcl.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Mcu.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Ocu.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Pm.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Port.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Pwm.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Spi.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Uart.h@outdir=include \
				$(MODULE_PATH)/generic/include/SchM_Wdg.h@outdir=include \
				$(MODULE_PATH)/generic/src/SchM_Adc.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Can.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Crc.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Crypto.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Dio.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Eep.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Eth.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Fee.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Fls.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Gpt.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_I2c.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Icu.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Lin.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Mcem.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Mcl.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Mcu.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Ocu.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Pm.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Port.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Pwm.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Spi.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Uart.c@outdir=src \
				$(MODULE_PATH)/generic/src/SchM_Wdg.c@outdir=src
