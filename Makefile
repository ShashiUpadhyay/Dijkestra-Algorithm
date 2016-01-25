all: execute

execute:
	javac SalesMan.java
	javah -jni SalesMan
	g++ my_dijkstras.cpp -I/usr/lib/jvm/default-java/include -shared -rdynamic -fPIC -lc -o libSalesMan.so
	java -Djava.library.path=. SalesMan
