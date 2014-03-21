
NAME =		$(PWD)/nibbler

SRC =		src

SOURCES =	$(SRC)/GameEngine/GameEngine.cpp \
		$(SRC)/GameEngine/Events/InputEvent.cpp \
		$(SRC)/GameEngine/Events/Event.cpp \
		$(SRC)/GameEngine/Events/EventHandler.cpp \
		$(SRC)/GameEngine/Events/EventDispatcher.cpp \
		$(SRC)/GameEngine/Core/Core.cpp \
		$(SRC)/GameEngine/CoreInput.cpp \
		$(SRC)/GameEngine/Scene.cpp \
		$(SRC)/GameEngine/Renderer.cpp \
		$(SRC)/GameEngine/SceneManager.cpp \
		$(SRC)/GameEngine/GameScreen.cpp \
		$(SRC)/GameEngine/GameScreenManager.cpp \
		$(SRC)/GameEngine/Core/CoreServices.cpp \
		$(SRC)/GameEngine/Clock/Clock.cpp \

SOURCES +=	$(SRC)/GameEngine/Entities/BaseEntity.cpp \
		$(SRC)/GameEngine/Entities/ShapeEntity.cpp \

SOURCES +=	$(SRC)/GameEngine/Sound/SoundManager.cpp \
		$(SRC)/GameEngine/Sound/Sound.cpp \
		$(SRC)/GameEngine/RessourceManager.cpp \

SOURCES += 	$(SRC)/GameEngine/Image.cpp \
		$(SRC)/GameEngine/stb_image.cpp \
		$(SRC)/GameEngine/Entities/ImageEntity.cpp \

SOURCES +=	$(SRC)/main.cpp \
		$(SRC)/NibblerCore.cpp \
		$(SRC)/Bullet.cpp \
		$(SRC)/Player.cpp \

OBJS =		$(SOURCES:.cpp=.o)

LDFLAGS =	-ldl -rdynamic -L./ -lfmodex64

CXX =		g++

INCLUDES =	-I./$(SRC) -I./$(SRC)/GameEngine/

CXXFLAGS =	$(INCLUDES) -ansi -pedantic -Wextra -Wall


$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $@ $(LDFLAGS)

.cpp.o:
		$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY: 	all clean fclean re
