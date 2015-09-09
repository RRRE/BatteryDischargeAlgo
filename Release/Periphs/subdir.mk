################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Periphs/adc.cpp \
../Periphs/main.cpp 

OBJS += \
./Periphs/adc.o \
./Periphs/main.o 

CPP_DEPS += \
./Periphs/adc.d \
./Periphs/main.d 


# Each subdirectory must supply rules for building sources it contributes
Periphs/%.o: ../Periphs/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega8 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


