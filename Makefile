#
# This is a project Makefile. It is assumed the directory this Makefile resides
# in is a project subdirectory.
#
############# MAKE AGENTSPEAK CODE TRANSLATION AND FLASH TO BOARD #############

interface=/dev/ttyUSB0

translate:
	javac -cp embedded-bdi/lib/parser/lib/jason-2.6.jar                       \
        embedded-bdi/lib/parser/src/translator/As2Json.java                   \
        embedded-bdi/lib/parser/src/translator/PlanSkeleton.java              \
        embedded-bdi/lib/parser/src/translator/BodyInstruction.java           \
        embedded-bdi/lib/parser/src/translator/EventOperatorType.java         \
        embedded-bdi/lib/parser/src/translator/HeaderCreator.java

	java -cp                                                                  \
	    embedded-bdi/lib/parser/lib/jason-2.6.jar:embedded-bdi/lib/parser/src \
        translator.As2Json                                                    \
        main/data/agentspeak.asl                                              \
        main/data/functions.h                                                 \
        main/src/config/configuration.h                                       \
        $(EVENT_BASE_SIZE) $(INTENTION_BASE_SIZE) $(INTENTION_STACK_SIZE)

agent-bdi: translate
	idf.py -p $(interface) flash monitor

agent-trad:
	idf.py -p $(interface) flash monitor

################### Individual targets for vacuum example #####################

v1-traditional:
	./copy_examples.sh v1-traditional
	make agent-trad

v2-traditional:
	./copy_examples.sh v2-traditional
	make agent-trad

v3-traditional:
	./copy_examples.sh v3-traditional
	make agent-trad

v1-reactive:
	./copy_examples.sh v1-reactive
	make agent-bdi

v2-reactive:
	./copy_examples.sh v2-reactive
	make agent-bdi

v3-reactive:
	./copy_examples.sh v3-reactive
	make agent-bdi

v1-proactive:
	./copy_examples.sh v1-proactive
	make agent-bdi

v2-proactive:
	./copy_examples.sh v2-proactive
	make agent-bdi

v3-proactive:
	./copy_examples.sh v3-proactive
	make agent-bdi

-include agent.config

######################## DEFAULT IDF MAKEFILE #################################

PROJECT_NAME := agent-loop

include $(IDF_PATH)/make/project.mk