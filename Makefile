CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

SOURCE =	Node.cpp SuffixTree.cpp Search.cpp

OBJS =		$(SOURCE:.cpp=.o)

LIBS =

TARGET =	Search

$(TARGET):	$(OBJS)
	$(CXX) $(OBJS) $(LIBS) -o $(TARGET)

all:	$(SOURCE) $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<