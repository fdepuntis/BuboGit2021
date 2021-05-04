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
	${OBJECTDIR}/_ext/b57f3ad/serialib.o \
	${OBJECTDIR}/_ext/5c0/Ampoule.o \
	${OBJECTDIR}/_ext/5c0/BDD.o \
	${OBJECTDIR}/_ext/5c0/Collecteur.o \
	${OBJECTDIR}/_ext/5c0/Config.o \
	${OBJECTDIR}/_ext/5c0/Enregistrement.o \
	${OBJECTDIR}/_ext/5c0/GPS.o \
	${OBJECTDIR}/_ext/5c0/Galerie.o \
	${OBJECTDIR}/_ext/5c0/Geolocalisation.o \
	${OBJECTDIR}/_ext/5c0/Horodatage.o \
	${OBJECTDIR}/_ext/5c0/Internet.o \
	${OBJECTDIR}/_ext/5c0/Lampadaire.o \
	${OBJECTDIR}/_ext/5c0/Luxmetre.o \
	${OBJECTDIR}/_ext/5c0/Mail.o \
	${OBJECTDIR}/_ext/5c0/Photo.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-l sqlite3 -lcgicc -I /usr/local/include/Poco/ -L /usr/local/lib -lPocoFoundation -lPocoNet -lPocoNetSSL -lPocoUtil -lPocoXML
CXXFLAGS=-l sqlite3 -lcgicc -I /usr/local/include/Poco/ -L /usr/local/lib -lPocoFoundation -lPocoNet -lPocoNetSSL -lPocoUtil -lPocoXML

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/photosdepuntis

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/photosdepuntis: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/photosdepuntis ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/b57f3ad/serialib.o: ../../serialib/serialib.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/b57f3ad
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b57f3ad/serialib.o ../../serialib/serialib.cpp

${OBJECTDIR}/_ext/5c0/Ampoule.o: ../Ampoule.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Ampoule.o ../Ampoule.cpp

${OBJECTDIR}/_ext/5c0/BDD.o: ../BDD.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/BDD.o ../BDD.cpp

${OBJECTDIR}/_ext/5c0/Collecteur.o: ../Collecteur.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Collecteur.o ../Collecteur.cpp

${OBJECTDIR}/_ext/5c0/Config.o: ../Config.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Config.o ../Config.cpp

${OBJECTDIR}/_ext/5c0/Enregistrement.o: ../Enregistrement.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Enregistrement.o ../Enregistrement.cpp

${OBJECTDIR}/_ext/5c0/GPS.o: ../GPS.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/GPS.o ../GPS.cpp

${OBJECTDIR}/_ext/5c0/Galerie.o: ../Galerie.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Galerie.o ../Galerie.cpp

${OBJECTDIR}/_ext/5c0/Geolocalisation.o: ../Geolocalisation.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Geolocalisation.o ../Geolocalisation.cpp

${OBJECTDIR}/_ext/5c0/Horodatage.o: ../Horodatage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Horodatage.o ../Horodatage.cpp

${OBJECTDIR}/_ext/5c0/Internet.o: ../Internet.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Internet.o ../Internet.cpp

${OBJECTDIR}/_ext/5c0/Lampadaire.o: ../Lampadaire.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Lampadaire.o ../Lampadaire.cpp

${OBJECTDIR}/_ext/5c0/Luxmetre.o: ../Luxmetre.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Luxmetre.o ../Luxmetre.cpp

${OBJECTDIR}/_ext/5c0/Mail.o: ../Mail.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Mail.o ../Mail.cpp

${OBJECTDIR}/_ext/5c0/Photo.o: ../Photo.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Photo.o ../Photo.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/photosdepuntis

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
