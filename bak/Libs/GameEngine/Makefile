
NAME =		$(PWD)/libGameEngine.a

SRC =		./src

SOURCES =       $(SRC)/GameEngine.cpp \
		$(SRC)/Events/InputEvent.cpp \
		$(SRC)/Events/Event.cpp \
		$(SRC)/Events/EventHandler.cpp \
		$(SRC)/Events/EventDispatcher.cpp \
		$(SRC)/Core/Core.cpp \
		$(SRC)/CoreInput.cpp \
		$(SRC)/Scene.cpp \
		$(SRC)/Renderer.cpp \
		$(SRC)/SceneManager.cpp \
		$(SRC)/GameScreen.cpp \
		$(SRC)/GameScreenManager.cpp \
		$(SRC)/Core/CoreServices.cpp \
		$(SRC)/Entities/BaseEntity.cpp \
		$(SRC)/Entities/ShapeEntity.cpp \

OBJS =          $(SOURCES:.cpp=.o)

LDFLAGS =

CXX =           g++

INCLUDES =	-I$(SRC)

CXXFLAGS =      $(INCLUDES) -ansi -pedantic -Wextra -Wall


$(NAME):	$(OBJS)
		ar rc $@ $(OBJS)
		ranlib $@
#		$(CXX) $(OBJS) -o $@ $(LDFLAGS)

.cpp.o:
		$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
		$(RM) $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re:             fclean $(NAME)

.PHONY:         all clean fclean re

