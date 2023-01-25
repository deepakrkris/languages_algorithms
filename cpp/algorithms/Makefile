OUTPUT_PATH=$(HOME)"/output"
examples=$(shell ls *.cpp)
headers=$(shell ls *.h)
MKDIR_P = mkdir -p

clean:
	rm -rf $(OUTPUT_PATH)
	${MKDIR_P} $(OUTPUT_PATH)
	chmod 777 $(OUTPUT_PATH)

all: clean
	for dir in $(examples); do echo $(headers); echo $$dir; out=$(OUTPUT_PATH)"/$$dir"".o"; logs=$(OUTPUT_PATH)"/log"; echo $$out; g++ -std=c++14 $$dir -o $$out; $$out>>$$logs ; done

run:
	for dir in $(examples); do echo $$dir; out=$(OUTPUT_PATH)"/$$dir"".o"; $$out ; done

.PHONY: clean
