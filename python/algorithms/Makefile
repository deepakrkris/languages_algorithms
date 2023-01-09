dirs=$(shell echo ./*/)

run:
	for d in $(dirs) ; do cd $$d; CMD="make run" ; $$CMD ; cd .. ; done
