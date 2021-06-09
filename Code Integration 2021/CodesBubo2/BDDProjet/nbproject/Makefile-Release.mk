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
	${OBJECTDIR}/_ext/5ec76e66/Ampoule.o \
	${OBJECTDIR}/_ext/5ec76e66/BDD.o \
	${OBJECTDIR}/_ext/5ec76e66/Collecteur.o \
	${OBJECTDIR}/_ext/5ec76e66/Enregistrement.o \
	${OBJECTDIR}/_ext/5ec76e66/GPS.o \
	${OBJECTDIR}/_ext/5ec76e66/Galerie.o \
	${OBJECTDIR}/_ext/5ec76e66/Geolocalisation.o \
	${OBJECTDIR}/_ext/5ec76e66/Horodatage.o \
	${OBJECTDIR}/_ext/5ec76e66/Lampadaire.o \
	${OBJECTDIR}/_ext/5ec76e66/Mail.o \
	${OBJECTDIR}/_ext/b57f3ad/serialib.o \
	${OBJECTDIR}/_ext/5c0/Config.o \
	${OBJECTDIR}/_ext/5c0/Internet.o \
	${OBJECTDIR}/_ext/5c0/Logger.o \
	${OBJECTDIR}/_ext/5c0/Luxmetre.o \
	${OBJECTDIR}/_ext/5c0/envoyerBDD.o \
	${OBJECTDIR}/_ext/5c0/listerEnregistrements.o \
	${OBJECTDIR}/_ext/5c0/modifier.o \
	${OBJECTDIR}/_ext/5c0/supprimer.o \
	${OBJECTDIR}/enregistrer.o \
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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bddprojet

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bddprojet: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bddprojet ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/5ec76e66/Ampoule.o: ../../Codes/Ampoule.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/Ampoule.o ../../Codes/Ampoule.cpp

${OBJECTDIR}/_ext/5ec76e66/BDD.o: ../../Codes/BDD.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/BDD.o ../../Codes/BDD.cpp

${OBJECTDIR}/_ext/5ec76e66/Collecteur.o: ../../Codes/Collecteur.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/Collecteur.o ../../Codes/Collecteur.cpp

${OBJECTDIR}/_ext/5ec76e66/Enregistrement.o: ../../Codes/Enregistrement.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/Enregistrement.o ../../Codes/Enregistrement.cpp

${OBJECTDIR}/_ext/5ec76e66/GPS.o: ../../Codes/GPS.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/GPS.o ../../Codes/GPS.cpp

${OBJECTDIR}/_ext/5ec76e66/Galerie.o: ../../Codes/Galerie.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/Galerie.o ../../Codes/Galerie.cpp

${OBJECTDIR}/_ext/5ec76e66/Geolocalisation.o: ../../Codes/Geolocalisation.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/Geolocalisation.o ../../Codes/Geolocalisation.cpp

${OBJECTDIR}/_ext/5ec76e66/Horodatage.o: ../../Codes/Horodatage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/Horodatage.o ../../Codes/Horodatage.cpp

${OBJECTDIR}/_ext/5ec76e66/Lampadaire.o: ../../Codes/Lampadaire.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/Lampadaire.o ../../Codes/Lampadaire.cpp

${OBJECTDIR}/_ext/5ec76e66/Mail.o: ../../Codes/Mail.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ec76e66
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ec76e66/Mail.o ../../Codes/Mail.cpp

${OBJECTDIR}/_ext/b57f3ad/serialib.o: ../../serialib/serialib.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/b57f3ad
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b57f3ad/serialib.o ../../serialib/serialib.cpp

${OBJECTDIR}/_ext/5c0/Config.o: ../Config.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Config.o ../Config.cpp

${OBJECTDIR}/_ext/5c0/Internet.o: ../Internet.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Internet.o ../Internet.cpp

${OBJECTDIR}/_ext/5c0/Logger.o: ../Logger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Logger.o ../Logger.cpp

${OBJECTDIR}/_ext/5c0/Luxmetre.o: ../Luxmetre.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/Luxmetre.o ../Luxmetre.cpp

${OBJECTDIR}/_ext/5c0/envoyerBDD.o: ../envoyerBDD.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/envoyerBDD.o ../envoyerBDD.cpp

${OBJECTDIR}/_ext/5c0/listerEnregistrements.o: ../listerEnregistrements.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/listerEnregistrements.o ../listerEnregistrements.cpp

${OBJECTDIR}/_ext/5c0/modifier.o: ../modifier.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/modifier.o ../modifier.cpp

${OBJECTDIR}/_ext/5c0/supprimer.o: ../supprimer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5c0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5c0/supprimer.o ../supprimer.cpp

${OBJECTDIR}/enregistrer.o: enregistrer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/enregistrer.o enregistrer.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bddprojet

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
