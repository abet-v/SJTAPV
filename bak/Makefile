COREDIR =	./NibblerCore/

LIBSDIR =	./Libs/

LIBS =		X11\
		GameEngine\

all:	Core Lib


Core:
	make -C $(COREDIR) $(filter-out $@,$(MAKECMDGOALS))

Lib:
	$(foreach lib, $(LIBS), make -C $(LIBSDIR)$(lib)/ $(filter-out $@,$(MAKECMDGOALS));)
