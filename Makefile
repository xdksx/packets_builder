server:server_all.cpp sender.cpp packets.cpp controler.cpp 
	g++ -o server server_all.cpp sender.cpp packets.cpp controler.cpp -fno-stack-protector
