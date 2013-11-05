################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Fighter.cpp \
../src/character.cpp \
../src/comp345_driver_for_character.cpp 

OBJS += \
./src/Fighter.o \
./src/character.o \
./src/comp345_driver_for_character.o 

CPP_DEPS += \
./src/Fighter.d \
./src/character.d \
./src/comp345_driver_for_character.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


