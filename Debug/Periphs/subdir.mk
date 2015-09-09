################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Periphs/adc.cpp 

OBJS += \
./Periphs/adc.o 

CPP_DEPS += \
./Periphs/adc.d 


# Each subdirectory must supply rules for building sources it contributes
Periphs/adc.o: ../Periphs/adc.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega8 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"Periphs/adc.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


