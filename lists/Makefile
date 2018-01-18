app := lists 

CXX 	:= /depot/gcc-4.8.2/bin/g++
LD		:= /depot/binutils-2.27/bin/ld
CXXFLAGS:= -g -std=c++11
LDFLAGS := -g 
LDLIBS 	:=

SRCS := $(shell find . -name "*.cpp")
OBJS := $(subst .cpp,.o,$(SRCS))

all: $(app)

$(app): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(app) $(OBJS) $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

cleanall: clean
	$(RM) *~ .depend
	$(RM) $(app)

include .depend
