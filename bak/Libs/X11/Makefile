
NAME =		$(PWD)/libNibblerX11.so

SRC_PATH =	./src/

SOURCES +=	$(SRC_PATH)MLXLib/MLXWindow.cpp \
		$(SRC_PATH)MLXLib/MLXImage.cpp \
		$(SRC_PATH)MLXLib/strlcpy.cpp \

SOURCES +=	$(SRC_PATH)X11Core.cpp \
		$(SRC_PATH)X11Renderer.cpp

OBJS =          $(SOURCES:.cpp=.o)

LDFLAGS =       -L. -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm -shared

CXX =           g++

INCLUDES =	-I ../../NibblerCore/src/GameEngine/ -I ../../NibblerCore/src/

CXXFLAGS =      $(INCLUDES) -ansi -pedantic -Wextra -Wall -fPIC


$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $@ $(LDFLAGS)

.cpp.o:
		$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
		$(RM) $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re:             fclean $(NAME)

.PHONY:         all clean fclean re

