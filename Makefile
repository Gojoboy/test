CLANG = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
UCSF = uchat_src/*.c 
UCSSF = uchat_server_src/*.c 
OD = obj
UCFN = uchat
UCSFN = uchat_server
LIBPATH = -L../libraries/lib -lpthread -lpthread -ldl 
LIB = 
GTKINC = -D_GNU_SOURCE `pkg-config --cflags gtk+-3.0`
GTKLIB = -rdynamic `pkg-config --cflags --libs gtk+-3.0`

all: clean uchat uchat_server clean

uchat: clean
	#@make install -sC uchat_src
	@${CLANG} ${GTKLIB} -o ${UCFN} ${UCSF} #${LIBPATH} 

uchat_server: clean
	

uninstall: clean
	#@make uninstall -sC libmx
	@rm -f ${UCFN}
	@rm -f ${UCSFN}

clean:
	#@make clean -sC libmx
	@rm -rdf ${OD} 

reinstall: uninstall uchat uchat_server clean 

