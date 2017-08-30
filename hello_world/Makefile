app := hello

CXX 	:= g++
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
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(OBJS)

cleanall: clean
	rm -f *~ .depend
	rm -f $(app)

include .depend
