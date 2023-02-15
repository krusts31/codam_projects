#calls all the make files
find ./ -name "Makefile" | rev | cut -d '/' -f2- | rev | xargs -L 1 make -C 
find CPP_piscine -name "*.o" | xargs -L 1 rm  
