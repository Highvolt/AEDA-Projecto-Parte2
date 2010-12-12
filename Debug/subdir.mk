################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Aeroporto.cpp \
../Companhia.cpp \
../Pista_aterragem.cpp \
../Pista_descolagem.cpp \
../Plano_de_voo.cpp \
../main.cpp 

OBJS += \
./Aeroporto.o \
./Companhia.o \
./Pista_aterragem.o \
./Pista_descolagem.o \
./Plano_de_voo.o \
./main.o 

CPP_DEPS += \
./Aeroporto.d \
./Companhia.d \
./Pista_aterragem.d \
./Pista_descolagem.d \
./Plano_de_voo.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


