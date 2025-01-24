# Specify target
all: song

# Object files
song: music.o groups.o Album.o pgroup.o cp2_songs.o
	g++ $^ -o $@

# Compile source files into object files
%.o: %.cpp %.h
	g++ -c $< -o $@

# Clean
clean:
	rm -f *.o song

