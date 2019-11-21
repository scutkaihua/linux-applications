########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = arm-linux-gnueabihf-gcc
CXXFLAGS = -std=c11 -Wall
LDFLAGS = 
DEBUG   = 
# Makefile settings - Can be customized.
APPNAME = main
EXT = .c
SRCDIR = src
OBJDIR = .obj
DEPDIR = .dep
SUBDIRS =  $(DEPDIR) $(OBJDIR)
############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d )
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: CHECKDIRS  $(APPNAME) 

#check  directories for tmp files while building
CHECKDIRS:
	if ! [ -f $(DEPDIR) ] ;then  mkdir -p $(SUBDIRS)	;fi	
	
# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS)  $(DEBUG) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
$(DEPDIR)/%.d: $(SRCDIR)/%$(EXT) 
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)   $(DEP)
	$(CC) $(CXXFLAGS)  $(DEBUG) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
clean:
	$(RM) $(APPNAME) $(SUBDIRS)  -rf
# Cleans only all files with the extension .d
cleandep:
	$(RM) $(DEP) 
#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)