TITLE = fantasyCombat
CPP = Creature.cpp
CPP += Game.cpp
CPP += Barbarian.cpp
CPP += Bluemen.cpp
CPP += Harrypotter.cpp
CPP += Medusa.cpp
CPP += Vampire.cpp
CPP += main.cpp
DELETE = *.gch
DELETE += *.o

all:
	g++ ${CPP} -o ${TITLE}

clean:
	${RM} ${DELETE} ${TITLE}
