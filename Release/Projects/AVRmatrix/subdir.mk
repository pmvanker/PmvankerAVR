################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Projects/AVRmatrix/matrix.c 

OBJS += \
./Projects/AVRmatrix/matrix.o 

C_DEPS += \
./Projects/AVRmatrix/matrix.d 


# Each subdirectory must supply rules for building sources it contributes
Projects/AVRmatrix/%.o: ../Projects/AVRmatrix/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=800000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


