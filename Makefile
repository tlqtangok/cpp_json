CC = g++ -std=c++11 

nullstring := 
dep_I_incpath = -I./inc
dep_L_libpath = $(nullstring) 
dep_l_libname = $(nullstring)
deps_extra = $(dep_I_incpath) $(dep_L_libpath)  $(dep_l_libname)

#deps_extra = $(nullstring)

#c_flag = -g -Wno-format -fpermissive 
c_flag = -g -pthread -Wno-format -fpermissive

c_files =  \
$(wildcard *.cpp) $(wildcard *.c)
h_files = \
$(wildcard *.hpp) $(wildcard *.h)
o_files_mess = \
$(patsubst %.cpp,%.o,${c_files}) $(patsubst %.c,%.o,${c_files})
o_files = \
$(filter %.o, $(o_files_mess))
elf_file=  \
mainapp.exe

rm_files = \
*.o *.dep *.elf  *.s *.exe


all:$(elf_file)

$(elf_file):$(o_files)
	$(CC) $(c_flag) -o $@ $(o_files) $(deps_extra) 
main.o: main.cpp
	$(CC) $(c_flag) -o $@ -c $< $(deps_extra) 
	$(CC) $(c_flag) -o $@ -c $< $(deps_extra) 
#	@echo "c_file is:$(c_files)"; echo "h_files:$(h_files)"; echo "o_files:$(o_files)"

clean:
	rm -rf $(rm_files)

run:$(elf_file)
	./$(elf_file)

