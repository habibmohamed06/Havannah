executer: compiler
	@echo "execution "
	@./aa
compiler: main.cpp fonc.cpp fonc.h
	@echo "compilation . . ."
	@echo "*******************************"
	g++ fonc.cpp main.cpp -o aa
	@echo "*******************************"
	@echo "compilation terminé"
