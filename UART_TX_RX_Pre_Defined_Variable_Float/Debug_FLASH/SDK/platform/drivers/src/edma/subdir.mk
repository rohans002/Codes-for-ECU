################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/S32DS.3.4/S32DS/software/S32SDK_S32K1XX_RTM_4.0.3/platform/drivers/src/edma/edma_driver.c \
D:/NXP/S32DS.3.4/S32DS/software/S32SDK_S32K1XX_RTM_4.0.3/platform/drivers/src/edma/edma_hw_access.c \
D:/NXP/S32DS.3.4/S32DS/software/S32SDK_S32K1XX_RTM_4.0.3/platform/drivers/src/edma/edma_irq.c 

OBJS += \
./SDK/platform/drivers/src/edma/edma_driver.o \
./SDK/platform/drivers/src/edma/edma_hw_access.o \
./SDK/platform/drivers/src/edma/edma_irq.o 

C_DEPS += \
./SDK/platform/drivers/src/edma/edma_driver.d \
./SDK/platform/drivers/src/edma/edma_hw_access.d \
./SDK/platform/drivers/src/edma/edma_irq.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/edma/edma_driver.o: D:/NXP/S32DS.3.4/S32DS/software/S32SDK_S32K1XX_RTM_4.0.3/platform/drivers/src/edma/edma_driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/edma/edma_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/platform/drivers/src/edma/edma_hw_access.o: D:/NXP/S32DS.3.4/S32DS/software/S32SDK_S32K1XX_RTM_4.0.3/platform/drivers/src/edma/edma_hw_access.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/edma/edma_hw_access.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/platform/drivers/src/edma/edma_irq.o: D:/NXP/S32DS.3.4/S32DS/software/S32SDK_S32K1XX_RTM_4.0.3/platform/drivers/src/edma/edma_irq.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/drivers/src/edma/edma_irq.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


