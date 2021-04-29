#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/f055e18e/GPS.o \
	${OBJECTDIR}/_ext/f055e18e/Geolocalisation.o \
	${OBJECTDIR}/_ext/f055e18e/Horodatage.o \
	${OBJECTDIR}/_ext/b57f3ad/serialib.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/recuperationheure

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/recuperationheure: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/recuperationheure ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/f055e18e/GPS.o: ../../Depuntis/developpement/Codes/GPS.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/f055e18e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f055e18e/GPS.o ../../Depuntis/developpement/Codes/GPS.cpp

${OBJECTDIR}/_ext/f055e18e/Geolocalisation.o: ../../Depuntis/developpement/Codes/Geolocalisation.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/f055e18e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f055e18e/Geolocalisation.o ../../Depuntis/developpement/Codes/Geolocalisation.cpp

${OBJECTDIR}/_ext/f055e18e/Horodatage.o: ../../Depuntis/developpement/Codes/Horodatage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/f055e18e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/f055e18e/Horodatage.o ../../Depuntis/developpement/Codes/Horodatage.cpp

${OBJECTDIR}/_ext/b57f3ad/serialib.o: ../../serialib/serialib.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/b57f3ad
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b57f3ad/serialib.o ../../serialib/serialib.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/recuperationheure

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
