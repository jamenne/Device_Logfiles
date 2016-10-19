CXX		= g++
CXXFLAGS	= -O2 -Wall 
LDFLAGS		= -lgpib
SRCFILES	= LogDev.cpp LogDevMain.cpp
OBJFILES    = LogDev.o LogDevMain.o

LogDev:		$(OBJFILES)
		$(CXX) $(OBJFILES) $(LDFLAGS) -o $@

clean:
		rm -f $(OBJFILES) LogDev 

LogDev.o:	LogDev.cpp LogDev.h
LogDevMain.o:	LogDevMain.cpp LogDev.h