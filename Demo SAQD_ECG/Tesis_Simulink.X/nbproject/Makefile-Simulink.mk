#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Simulink.mk)" "nbproject/Makefile-local-Simulink.mk"
include nbproject/Makefile-local-Simulink.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Simulink
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Tesis_Simulink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Tesis_Simulink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Tesis_Simulink.c MCHP_ADC1_Interrupt.c MCHP_UART1_Interrupt.c Tesis_Simulink_data.c Tesis_Simulink_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Tesis_Simulink.o ${OBJECTDIR}/MCHP_ADC1_Interrupt.o ${OBJECTDIR}/MCHP_UART1_Interrupt.o ${OBJECTDIR}/Tesis_Simulink_data.o ${OBJECTDIR}/Tesis_Simulink_main.o ${OBJECTDIR}/rtGetInf.o ${OBJECTDIR}/rtGetNaN.o ${OBJECTDIR}/rt_nonfinite.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Tesis_Simulink.o.d ${OBJECTDIR}/MCHP_ADC1_Interrupt.o.d ${OBJECTDIR}/MCHP_UART1_Interrupt.o.d ${OBJECTDIR}/Tesis_Simulink_data.o.d ${OBJECTDIR}/Tesis_Simulink_main.o.d ${OBJECTDIR}/rtGetInf.o.d ${OBJECTDIR}/rtGetNaN.o.d ${OBJECTDIR}/rt_nonfinite.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Tesis_Simulink.o ${OBJECTDIR}/MCHP_ADC1_Interrupt.o ${OBJECTDIR}/MCHP_UART1_Interrupt.o ${OBJECTDIR}/Tesis_Simulink_data.o ${OBJECTDIR}/Tesis_Simulink_main.o ${OBJECTDIR}/rtGetInf.o ${OBJECTDIR}/rtGetNaN.o ${OBJECTDIR}/rt_nonfinite.o

# Source Files
SOURCEFILES=Tesis_Simulink.c MCHP_ADC1_Interrupt.c MCHP_UART1_Interrupt.c Tesis_Simulink_data.c Tesis_Simulink_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Simulink.mk dist/${CND_CONF}/${IMAGE_TYPE}/Tesis_Simulink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128MC802
MP_LINKER_FILE_OPTION=,--script=p33FJ128MC802.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Tesis_Simulink.o: Tesis_Simulink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Tesis_Simulink.o.d 
	@${RM} ${OBJECTDIR}/Tesis_Simulink.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Tesis_Simulink.c  -o ${OBJECTDIR}/Tesis_Simulink.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tesis_Simulink.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Tesis_Simulink.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MCHP_ADC1_Interrupt.o: MCHP_ADC1_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_ADC1_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_ADC1_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_ADC1_Interrupt.c  -o ${OBJECTDIR}/MCHP_ADC1_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MCHP_ADC1_Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/MCHP_ADC1_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MCHP_UART1_Interrupt.o: MCHP_UART1_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART1_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART1_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MCHP_UART1_Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/MCHP_UART1_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Tesis_Simulink_data.o: Tesis_Simulink_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Tesis_Simulink_data.o.d 
	@${RM} ${OBJECTDIR}/Tesis_Simulink_data.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Tesis_Simulink_data.c  -o ${OBJECTDIR}/Tesis_Simulink_data.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tesis_Simulink_data.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Tesis_Simulink_data.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Tesis_Simulink_main.o: Tesis_Simulink_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Tesis_Simulink_main.o.d 
	@${RM} ${OBJECTDIR}/Tesis_Simulink_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Tesis_Simulink_main.c  -o ${OBJECTDIR}/Tesis_Simulink_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tesis_Simulink_main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Tesis_Simulink_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/rtGetInf.o: rtGetInf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtGetInf.o.d 
	@${RM} ${OBJECTDIR}/rtGetInf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rtGetInf.c  -o ${OBJECTDIR}/rtGetInf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rtGetInf.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/rtGetInf.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/rtGetNaN.o: rtGetNaN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtGetNaN.o.d 
	@${RM} ${OBJECTDIR}/rtGetNaN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rtGetNaN.c  -o ${OBJECTDIR}/rtGetNaN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rtGetNaN.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/rtGetNaN.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/rt_nonfinite.o: rt_nonfinite.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rt_nonfinite.o.d 
	@${RM} ${OBJECTDIR}/rt_nonfinite.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rt_nonfinite.c  -o ${OBJECTDIR}/rt_nonfinite.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rt_nonfinite.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/rt_nonfinite.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/Tesis_Simulink.o: Tesis_Simulink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Tesis_Simulink.o.d 
	@${RM} ${OBJECTDIR}/Tesis_Simulink.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Tesis_Simulink.c  -o ${OBJECTDIR}/Tesis_Simulink.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tesis_Simulink.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Tesis_Simulink.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MCHP_ADC1_Interrupt.o: MCHP_ADC1_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_ADC1_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_ADC1_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_ADC1_Interrupt.c  -o ${OBJECTDIR}/MCHP_ADC1_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MCHP_ADC1_Interrupt.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/MCHP_ADC1_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MCHP_UART1_Interrupt.o: MCHP_UART1_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART1_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART1_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MCHP_UART1_Interrupt.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/MCHP_UART1_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Tesis_Simulink_data.o: Tesis_Simulink_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Tesis_Simulink_data.o.d 
	@${RM} ${OBJECTDIR}/Tesis_Simulink_data.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Tesis_Simulink_data.c  -o ${OBJECTDIR}/Tesis_Simulink_data.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tesis_Simulink_data.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Tesis_Simulink_data.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Tesis_Simulink_main.o: Tesis_Simulink_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Tesis_Simulink_main.o.d 
	@${RM} ${OBJECTDIR}/Tesis_Simulink_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Tesis_Simulink_main.c  -o ${OBJECTDIR}/Tesis_Simulink_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Tesis_Simulink_main.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Tesis_Simulink_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/rtGetInf.o: rtGetInf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtGetInf.o.d 
	@${RM} ${OBJECTDIR}/rtGetInf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rtGetInf.c  -o ${OBJECTDIR}/rtGetInf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rtGetInf.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/rtGetInf.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/rtGetNaN.o: rtGetNaN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtGetNaN.o.d 
	@${RM} ${OBJECTDIR}/rtGetNaN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rtGetNaN.c  -o ${OBJECTDIR}/rtGetNaN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rtGetNaN.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/rtGetNaN.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/rt_nonfinite.o: rt_nonfinite.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rt_nonfinite.o.d 
	@${RM} ${OBJECTDIR}/rt_nonfinite.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rt_nonfinite.c  -o ${OBJECTDIR}/rt_nonfinite.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rt_nonfinite.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O1 -I"Tesis_Simulink.X" -I"." -I".." -I"C:/Program Files/MATLAB/R2014a/rtw/c/ert" -I"C:/Program Files/MATLAB/R2014a/extern/include" -I"C:/Program Files/MATLAB/R2014a/simulink/include" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/rt_nonfinite.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Tesis_Simulink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Tesis_Simulink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="Tesis_Simulink.X",--library-path=".",--library-path="..",--library-path="C:/Program Files/MATLAB/R2014a/rtw/c/ert",--library-path="C:/Program Files/MATLAB/R2014a/extern/include",--library-path="C:/Program Files/MATLAB/R2014a/simulink/include",--library-path="C:/Program Files/MATLAB/R2014a/rtw/c/src",--library-path="C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Tesis_Simulink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Tesis_Simulink.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="Tesis_Simulink.X",--library-path=".",--library-path="..",--library-path="C:/Program Files/MATLAB/R2014a/rtw/c/ert",--library-path="C:/Program Files/MATLAB/R2014a/extern/include",--library-path="C:/Program Files/MATLAB/R2014a/simulink/include",--library-path="C:/Program Files/MATLAB/R2014a/rtw/c/src",--library-path="C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/R2014a/rtw/c/src/ext_mode/common",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Tesis_Simulink.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Simulink
	${RM} -r dist/Simulink

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
