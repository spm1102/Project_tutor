clean:
	-del "build"

build:
	-mkdir "build"
	gcc src/*.c  -Iinc -o build/main -lraylib -lgdi32 -lwinmm -Lraylib/lib -Iraylib/include

run:
	./build/main
