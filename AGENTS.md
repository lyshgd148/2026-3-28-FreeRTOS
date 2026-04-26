# OpenCode Agent Instructions - STM32 Embedded Learning Projects

## Project Overview
This repository contains a collection of STM32 embedded system learning projects organized by version numbers. Each numbered directory (e.g., `11.0-VET6`) represents a complete Keil MDK-ARM project for a specific learning stage.

## Project Structure
- `STM32F103VET6/` - Projects for STM32F103VET6 (512KB Flash, 64KB RAM)
  - `1.0-BASE/` to `11.0-VET6/` - Sequential learning projects
- `STM32F103C8T6/` - Projects for STM32F103C8T6 (Blue Pill board)
- Each version directory contains a complete Keil project

## Development Environment
- **IDE**: Keil MDK-ARM (µVision)
- **Configuration**: STM32CubeMX for peripheral initialization
- **Library**: STM32 HAL Library
- **Target**: ARM Cortex-M3 (STM32F103 series)

## Key Directories in Each Project
- `Core/` - STM32CubeMX generated core code
- `Drivers/` - STM32 HAL library drivers
- `Hardware/` - Custom hardware drivers (OLED, KEY, LED)
- `MDK-ARM/` - Keil project files and build output
- `*.ioc` - STM32CubeMX configuration file

## Building Projects
1. Open the `.uvprojx` file in `MDK-ARM/` directory with Keil µVision
2. Build using F7 or Project → Build Target
3. Output files are in `MDK-ARM/<project-name>/` directory

## Code Generation Notes
- **DO NOT** manually edit files in `Core/` directory between `USER CODE BEGIN` and `USER CODE END` comments
- Regenerate code using STM32CubeMX when changing peripheral configurations
- Custom code should be placed in `Hardware/` directory or within `USER CODE` sections

## Hardware Drivers
Custom drivers are located in `Hardware/` directory:
- `OLED.c/.h` - SSD1306 OLED display driver with I2C interface
- `KEY.c/.h` - Advanced button detection with state machine (supports click, double-click, long-press, repeat)
- `LED.c/.h` - LED control functions

## Project Progression
Projects are numbered sequentially (1.0, 2.0, 3.0, etc.) representing increasing complexity:
- Early versions: Basic GPIO and peripheral setup
- Middle versions: Communication protocols (I2C, USART)
- Later versions: Advanced features (DMA, interrupts, custom drivers)

## Git Ignored Files
- Keil build artifacts (`*.axf`, `*.o`, `*.lst`, `*.map`)
- Temporary files (`*.uvoptx`, `*.uvguix.*`, `.mxproject`)
- VSCode configuration (`.vscode/`)

## Working with OpenCode
- Focus changes within `Hardware/` directory for custom functionality
- Preserve `USER CODE` sections when editing `Core/` files
- Reference existing projects for implementation patterns
- Test changes by building in Keil before committing