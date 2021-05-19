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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Bubo/listerEnregistrements.o \
	${OBJECTDIR}/ClientCGI.o \
	${OBJECTDIR}/Collecteur.o \
	${OBJECTDIR}/Enregistrement.o \
	${OBJECTDIR}/GPS.o \
	${OBJECTDIR}/Serveur.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=sqlite3
CXXFLAGS=sqlite3

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetsocketv2

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetsocketv2: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetsocketv2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Bubo/listerEnregistrements.o: Bubo/listerEnregistrements.cpp 
	${MKDIR} -p ${OBJECTDIR}/Bubo
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bubo/listerEnregistrements.o Bubo/listerEnregistrements.cpp

${OBJECTDIR}/ClientCGI.o: ClientCGI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ClientCGI.o ClientCGI.cpp

${OBJECTDIR}/Collecteur.o: Collecteur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Collecteur.o Collecteur.cpp

${OBJECTDIR}/Enregistrement.o: Enregistrement.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Enregistrement.o Enregistrement.cpp

${OBJECTDIR}/GPS.o: GPS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GPS.o GPS.cpp

${OBJECTDIR}/Serveur.o: Serveur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Serveur.o Serveur.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/projetsocketv2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
