################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Timer_Test.lss \

FLASH_IMAGE += \
Timer_Test.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Timer_Test.elf secondary-outputs

# Tool invocations
Timer_Test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Timer_Test.map -mmcu=atmega32 -o "Timer_Test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Timer_Test.lss: Timer_Test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Timer_Test.elf  >"Timer_Test.lss"
	@echo 'Finished building: $@'
	@echo ' '

Timer_Test.hex: Timer_Test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Timer_Test.elf  "Timer_Test.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Timer_Test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Timer_Test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Timer_Test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
